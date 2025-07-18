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

// Config register bits
const CONFIG_TOUCH_ENABLE: u8 = 0x01;
const CONFIG_SCAN_ENABLE: u8 = 0x02;
const CONFIG_REPORT_MODE_CONTINUOUS: u8 = 0x04;
const CONFIG_SLEEP_DISABLE: u8 = 0x08;

// Control register bits
const CONTROL_RESET: u8 = 0x01;
const CONTROL_CLEAR_INT: u8 = 0x02;
const CONTROL_CALIBRATE: u8 = 0x04;

// Expected device ID - this might need to be updated based on actual hardware
const TRACKPAD_DEVICE_ID: u8 = 0x12; // Placeholder value - needs verification

/// Trackpad position which contains raw readings
#[derive(Debug, Default, Clone, Copy)]
pub struct TrackpadPosition {
    pub x: i16,
    pub y: i16,
    pub pressure: u16,
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
    spi: &'a mut SpiDriver<SSP0>,
    gpio0: &'a GPIO0,
    gpio1: &'a GPIO1,
    side: TrackpadSide,
    initialized: bool,
}

impl<'a> Trackpad<'a> {
    /// Create a new trackpad driver instance
    pub fn new(spi: &'a mut SpiDriver<SSP0>, gpio0: &'a GPIO0, gpio1: &'a GPIO1, side: TrackpadSide) -> Self {
        Trackpad {
            spi,
            gpio0,
            gpio1,
            side,
            initialized: false,
        }
    }

    /// Initialize the trackpad
    pub fn init(&mut self) -> Result<(), ()> {
        // Set CS pin high (inactive) initially
        self.set_cs(true);
        
        // Reset the trackpad
        self.write_register(REG_CONTROL, CONTROL_RESET)?;
        
        // Short delay after reset - in a real implementation, use a proper timer
        for _ in 0..10000 {
            // Busy wait
        }
        
        // Check device ID to confirm trackpad is working
        let device_id = self.read_register(REG_DEVICE_ID)?;
        
        // Configure trackpad
        // Enable touch detection, scanning, continuous reporting, and disable sleep
        self.write_register(REG_CONFIG, CONFIG_TOUCH_ENABLE | CONFIG_SCAN_ENABLE | 
                          CONFIG_REPORT_MODE_CONTINUOUS | CONFIG_SLEEP_DISABLE)?;
        
        // Calibrate the trackpad
        self.write_register(REG_CONTROL, CONTROL_CALIBRATE)?;
        
        // Short delay after calibration
        for _ in 0..10000 {
            // Busy wait
        }
        
        // Clear any pending interrupts
        self.write_register(REG_CONTROL, CONTROL_CLEAR_INT)?;
        
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
            // Return default data if no new data is ready
            return Ok(TrackpadPosition::default());
        }
        
        // Read position data (X and Y coordinates)
        let mut position_buf = [0u8; 4]; // 2 bytes for X, 2 bytes for Y
        self.read_data(REG_POSITION_DATA, &mut position_buf)?;
        
        // Read pressure data
        let mut pressure_buf = [0u8; 2];
        self.read_data(REG_PRESSURE_DATA, &mut pressure_buf)?;
        
        // Combine bytes to form coordinates and pressure
        let x = ((position_buf[0] as u16) << 8) | position_buf[1] as u16;
        let y = ((position_buf[2] as u16) << 8) | position_buf[3] as u16;
        let pressure = ((pressure_buf[0] as u16) << 8) | pressure_buf[1] as u16;
        
        // Determine if pad is being touched based on pressure threshold
        // Actual threshold may need adjustment based on hardware characteristics
        let touching = pressure > 10; 
        
        // Convert to signed values
        let x = x as i16;
        let y = y as i16;
        
        // Clear interrupt to acknowledge data has been read
        self.write_register(REG_CONTROL, CONTROL_CLEAR_INT)?;
        
        Ok(TrackpadPosition {
            x,
            y,
            pressure,
            touching,
        })
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
        unsafe {
            match port {
                0 => (self.gpio0.data.read().bits() & (1 << pin)) == 0,
                1 => (self.gpio1.data.read().bits() & (1 << pin)) == 0,
                _ => false,
            }
        }
    }
    
    /// Set the CS pin high (inactive) or low (active)
    fn set_cs(&self, high: bool) {
        use crate::hal::pins::{TRACKPAD_LEFT_CS, TRACKPAD_RIGHT_CS};
        
        let (port, pin) = match self.side {
            TrackpadSide::Left => TRACKPAD_LEFT_CS,
            TrackpadSide::Right => TRACKPAD_RIGHT_CS,
        };
        
        unsafe {
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
    }
    
    /// Write to a register
    fn write_register(&mut self, reg: u8, value: u8) -> Result<(), ()> {
        // Activate CS (set low)
        self.set_cs(false);
        
        // Send register address with write bit (MSB = 0 for write)
        self.spi.transfer(reg & 0x7F);
        
        // Send data
        self.spi.transfer(value);
        
        // Deactivate CS (set high)
        self.set_cs(true);
        
        Ok(())
    }
    
    /// Read from a register
    fn read_register(&mut self, reg: u8) -> Result<u8, ()> {
        // Activate CS (set low)
        self.set_cs(false);
        
        // Send register address with read bit (MSB = 1 for read)
        self.spi.transfer(reg | 0x80);
        
        // Read data
        let value = self.spi.transfer(0);
        
        // Deactivate CS (set high)
        self.set_cs(true);
        
        Ok(value)
    }
    
    /// Read multiple bytes from a register
    fn read_data(&mut self, reg: u8, buffer: &mut [u8]) -> Result<(), ()> {
        // Activate CS (set low)
        self.set_cs(false);
        
        // Send register address with read bit (MSB = 1 for read)
        self.spi.transfer(reg | 0x80);
        
        // Read data into buffer
        for byte in buffer.iter_mut() {
            *byte = self.spi.transfer(0);
        }
        
        // Deactivate CS (set high)
        self.set_cs(true);
        
        Ok(())
    }
    
    /// Convert raw trackpad position to normalized TrackpadData
    pub fn to_trackpad_data(&mut self) -> Result<TrackpadData, ()> {
        let position = self.read_position()?;
        
        // Convert raw position to normalized TrackpadData
        // Note: The actual conversion factors depend on the trackpad's resolution
        // and may need adjustment
        
        // Assuming trackpad resolution of 0-4095 in X and Y, center it around 0
        // and scale appropriately
        let x = position.x - 2048;
        let y = position.y - 2048;
        
        Ok(TrackpadData {
            x,
            y,
            pressure: position.pressure as u8,
            touching: position.touching,
        })
    }
}
