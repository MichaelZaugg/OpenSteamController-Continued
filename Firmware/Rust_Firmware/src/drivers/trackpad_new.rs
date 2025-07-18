use crate::hal::spi::SpiDriver;
use lpc11xx::{GPIO0, GPIO1};
use crate::controller::input::TrackpadData;

// Steam Controller Trackpad registers (Cirque TM040040)
const REG_DEVICE_ID: u8 = 0x00;
const REG_FIRMWARE_VERSION: u8 = 0x01;
const REG_STATUS: u8 = 0x02;
const REG_SYSTEM_CONFIG: u8 = 0x03;
const REG_FEED_CONFIG1: u8 = 0x04;
const REG_FEED_CONFIG2: u8 = 0x05;
const REG_FEED_CONFIG3: u8 = 0x06;
const REG_CALIBRATION_CONFIG: u8 = 0x07;
const REG_PS2_AUX_CTRL: u8 = 0x08;
const REG_SAMPLE_RATE: u8 = 0x09;
const REG_Z_IDLE: u8 = 0x0A;
const REG_Z_SCALER: u8 = 0x0B;
const REG_SLEEP_INTERVAL: u8 = 0x0C;
const REG_SLEEP_TIMER: u8 = 0x0D;
const REG_DYNAMIC_EMI_ADJUST: u8 = 0x0E;
const REG_TRACKING_ADC_CONFIG: u8 = 0x0F;
const REG_PACKET_BYTE_0: u8 = 0x12;
const REG_PACKET_BYTE_1: u8 = 0x13;
const REG_PACKET_BYTE_2: u8 = 0x14;
const REG_PACKET_BYTE_3: u8 = 0x15;
const REG_PACKET_BYTE_4: u8 = 0x16;
const REG_PACKET_BYTE_5: u8 = 0x17;

// Status register bits
const STATUS_SW_CC: u8 = 0x01; // Switch / Click
const STATUS_SW_DR: u8 = 0x02; // Data Ready
const STATUS_SW_SO: u8 = 0x04; // Second finger / Secondary
const STATUS_SW_LR: u8 = 0x08; // Left / Right
const STATUS_SW_D0: u8 = 0x10; // Data 0
const STATUS_SW_D1: u8 = 0x20; // Data 1
const STATUS_SW_D2: u8 = 0x40; // Data 2
const STATUS_SW_D3: u8 = 0x80; // Data 3

// System config register bits
const SYS_CONFIG_RESET: u8 = 0x01;
const SYS_CONFIG_SHUTDOWN: u8 = 0x02;
const SYS_CONFIG_SLEEP: u8 = 0x04;
const SYS_CONFIG_TRACK_DISABLE: u8 = 0x08;
const SYS_CONFIG_ANYMEAS_DISABLE: u8 = 0x10;
const SYS_CONFIG_GPIO_DISABLE: u8 = 0x20;
const SYS_CONFIG_FEED_DISABLE: u8 = 0x40;
const SYS_CONFIG_SCALED_DATA: u8 = 0x80;

// Feed config bits
const FEED_CONFIG1_ENABLE: u8 = 0x01;
const FEED_CONFIG2_INTELLIMOUSE: u8 = 0x20;
const FEED_CONFIG3_DISABLE_PALM_REJECT: u8 = 0x01;

// Expected device ID for TM040040
const TRACKPAD_DEVICE_ID: u8 = 0x3A;

/// Trackpad position which contains raw readings
#[derive(Debug, Default, Clone, Copy)]
pub struct TrackpadPosition {
    pub x: u16,
    pub y: u16,
    pub z: u16,
    pub touching: bool,
}

/// Trackpad side - left or right
#[derive(Debug, Clone, Copy)]
pub enum TrackpadSide {
    Left,
    Right,
}

/// Trackpad driver for the Steam Controller
pub struct Trackpad<'a> {
    spi: &'a mut SpiDriver,
    gpio0: &'a GPIO0,
    gpio1: &'a GPIO1,
    side: TrackpadSide,
    initialized: bool,
    last_packet: [u8; 6],
}

impl<'a> Trackpad<'a> {
    /// Create a new trackpad driver instance
    pub fn new(spi: &'a mut SpiDriver, gpio0: &'a GPIO0, gpio1: &'a GPIO1, side: TrackpadSide) -> Self {
        Trackpad {
            spi,
            gpio0,
            gpio1,
            side,
            initialized: false,
            last_packet: [0; 6],
        }
    }

    /// Initialize the trackpad
    pub fn init(&mut self) -> Result<(), ()> {
        // Set CS pin high (inactive) initially
        self.set_cs(true);
        
        // Set GPIO references for SPI
        self.spi.set_gpio(self.gpio0, self.gpio1);
        
        // Reset the trackpad
        self.write_register(REG_SYSTEM_CONFIG, SYS_CONFIG_RESET)?;
        
        // Wait for reset to complete
        for _ in 0..10000 {
            core::hint::spin_loop();
        }
        
        // Check device ID to confirm trackpad is working
        let device_id = self.read_register(REG_DEVICE_ID)?;
        if device_id != TRACKPAD_DEVICE_ID {
            return Err(());
        }
        
        // Configure the trackpad for optimal performance
        // Enable tracking, disable sleep, enable scaled data
        self.write_register(REG_SYSTEM_CONFIG, SYS_CONFIG_SCALED_DATA)?;
        
        // Configure feed settings
        self.write_register(REG_FEED_CONFIG1, FEED_CONFIG1_ENABLE)?;
        self.write_register(REG_FEED_CONFIG2, FEED_CONFIG2_INTELLIMOUSE)?;
        self.write_register(REG_FEED_CONFIG3, FEED_CONFIG3_DISABLE_PALM_REJECT)?;
        
        // Set sample rate (default is usually fine)
        self.write_register(REG_SAMPLE_RATE, 0x64)?; // 100 samples/sec
        
        // Set Z sensitivity
        self.write_register(REG_Z_IDLE, 0x1E)?;
        
        // Enable calibration
        self.write_register(REG_CALIBRATION_CONFIG, 0x01)?;
        
        // Wait for calibration to complete
        for _ in 0..50000 {
            core::hint::spin_loop();
        }
        
        self.initialized = true;
        Ok(())
    }
    
    /// Read trackpad position and pressure data
    pub fn read_position(&mut self) -> Result<TrackpadPosition, ()> {
        if !self.initialized {
            return Err(());
        }
        
        // Check if data is ready
        if !self.is_data_ready() {
            // Return previous data if no new data is ready
            return Ok(self.parse_packet(&self.last_packet));
        }
        
        // Read the 6-byte packet
        let mut packet = [0u8; 6];
        for i in 0..6 {
            packet[i] = self.read_register(REG_PACKET_BYTE_0 + i as u8)?;
        }
        
        // Store for next time
        self.last_packet = packet;
        
        Ok(self.parse_packet(&packet))
    }
    
    /// Parse the 6-byte packet into position data
    fn parse_packet(&self, packet: &[u8; 6]) -> TrackpadPosition {
        // Steam Controller trackpad packet format:
        // Byte 0: Button state and packet info
        // Byte 1: X position low byte
        // Byte 2: X position high byte  
        // Byte 3: Y position low byte
        // Byte 4: Y position high byte
        // Byte 5: Z (pressure) value
        
        let button_state = packet[0];
        let x = ((packet[2] as u16) << 8) | (packet[1] as u16);
        let y = ((packet[4] as u16) << 8) | (packet[3] as u16);
        let z = packet[5] as u16;
        
        // Check if finger is touching (Z threshold)
        let touching = z > 20 && (button_state & 0x01) != 0;
        
        TrackpadPosition {
            x,
            y,
            z,
            touching,
        }
    }
    
    /// Check if the trackpad data ready pin is active
    fn is_data_ready(&self) -> bool {
        use crate::hal::pins::{TRACKPAD_LEFT_DR, TRACKPAD_RIGHT_DR};
        
        let (port, pin) = match self.side {
            TrackpadSide::Left => TRACKPAD_LEFT_DR,
            TrackpadSide::Right => TRACKPAD_RIGHT_DR,
        };
        
        // Read the data ready pin (active low)
        // Returns true if data is ready (pin is low)
        match port {
            0 => (self.gpio0.data.read().bits() & (1 << pin)) == 0,
            1 => (self.gpio1.data.read().bits() & (1 << pin)) == 0,
            _ => false,
        }
    }
    
    /// Set the CS pin high (inactive) or low (active)
    fn set_cs(&self, high: bool) {
        use crate::hal::pins::{TRACKPAD_LEFT_CS, TRACKPAD_RIGHT_CS};
        
        let (port, pin) = match self.side {
            TrackpadSide::Left => TRACKPAD_LEFT_CS,
            TrackpadSide::Right => TRACKPAD_RIGHT_CS,
        };
        
        match port {
            0 => {
                if high {
                    self.gpio0.data.modify(|r, w| w.bits(r.bits() | (1 << pin)));
                } else {
                    self.gpio0.data.modify(|r, w| w.bits(r.bits() & !(1 << pin)));
                }
            },
            1 => {
                if high {
                    self.gpio1.data.modify(|r, w| w.bits(r.bits() | (1 << pin)));
                } else {
                    self.gpio1.data.modify(|r, w| w.bits(r.bits() & !(1 << pin)));
                }
            },
            _ => {},
        }
    }
    
    /// Write to a register
    fn write_register(&mut self, reg: u8, value: u8) -> Result<(), ()> {
        // Activate CS (set low)
        self.set_cs(false);
        
        // Small delay for CS setup
        for _ in 0..10 {
            core::hint::spin_loop();
        }
        
        // Send register address with write bit (MSB = 0 for write)
        self.spi.transfer(reg & 0x7F);
        
        // Send data
        self.spi.transfer(value);
        
        // Small delay before CS deactivation
        for _ in 0..10 {
            core::hint::spin_loop();
        }
        
        // Deactivate CS (set high)
        self.set_cs(true);
        
        Ok(())
    }
    
    /// Read from a register
    fn read_register(&mut self, reg: u8) -> Result<u8, ()> {
        // Activate CS (set low)
        self.set_cs(false);
        
        // Small delay for CS setup
        for _ in 0..10 {
            core::hint::spin_loop();
        }
        
        // Send register address with read bit (MSB = 1 for read)
        self.spi.transfer(reg | 0x80);
        
        // Read data
        let value = self.spi.transfer(0);
        
        // Small delay before CS deactivation
        for _ in 0..10 {
            core::hint::spin_loop();
        }
        
        // Deactivate CS (set high)
        self.set_cs(true);
        
        Ok(value)
    }
    
    /// Convert raw trackpad position to normalized TrackpadData
    pub fn to_trackpad_data(&mut self) -> Result<TrackpadData, ()> {
        let position = self.read_position()?;
        
        // Convert raw position to normalized TrackpadData
        // The TM040040 has a resolution of about 1024x1024
        // Center it around 0 and scale appropriately
        let x = (position.x as i16) - 512;
        let y = (position.y as i16) - 512;
        
        // Scale to a reasonable range (Steam Controller uses -32768 to 32767)
        let x_scaled = (x as i32 * 64) as i16;
        let y_scaled = (y as i32 * 64) as i16;
        
        Ok(TrackpadData {
            x: x_scaled,
            y: y_scaled,
            pressure: (position.z as u8).min(255),
            touching: position.touching,
        })
    }
}
