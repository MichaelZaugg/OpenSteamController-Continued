#![no_std]
#![no_main]

use cortex_m_rt::entry;
use panic_halt as _;
use lpc11xx::Peripherals;

mod hal;
mod drivers;
mod controller;
mod utils;

use hal::{I2cDriver, UsartDriver, UsbDriver, SpiDriver, SpiMode};
use drivers::{Mpu6500, Nrf51822};
use drivers::trackpad::{Trackpad, TrackpadSide};
use controller::SteamController;
use controller::input::{TrackpadData, StickData};
use controller::haptics::HapticChannel;

// ADC Channels for analog inputs
const ADC_LEFT_TRIGGER_CHANNEL: u8 = 0;    // AD0 - Pin 42 - PIO0_11
const ADC_RIGHT_TRIGGER_CHANNEL: u8 = 2;   // AD2 - Pin 45 - PIO0_13  
const ADC_JOYSTICK_X_CHANNEL: u8 = 1;      // AD1 - Pin 44 - PIO0_12
const ADC_JOYSTICK_Y_CHANNEL: u8 = 3;      // AD3 - Pin 46 - PIO0_14
const ADC_BATTERY_VOLTAGE_CHANNEL: u8 = 4; // AD4 - Battery voltage sensing

// Function to read ADC value
fn read_adc(adc: &lpc11xx::ADC, channel: u8) -> u16 {
    unsafe {
        // Start conversion on selected channel
        // Set SEL bits (bits 0-7) to the channel mask, and bit 24 (START) to 1 for "start now"
        let channel_mask = 1 << channel;
        adc.cr.write(|w| w.bits((15 << 8) | channel_mask | (1 << 24)));
        
        // Wait for conversion to complete by checking DONE bit (bit 31)
        while (adc.gdr.read().bits() & (1 << 31)) == 0 {
            // Busy wait - in a real application you would use a proper timer
            // or interrupts for ADC completion
        }
        
        // Read result - bits 4-15 contain the 12-bit result
        ((adc.gdr.read().bits() >> 4) & 0xFFF) as u16
    }
}

// Function to apply haptic intensity to hardware
fn apply_haptic(gpio0: &lpc11xx::GPIO0, gpio1: &lpc11xx::GPIO1, channel: HapticChannel, intensity: u8) {
    use hal::pins::*;
    
    match channel {
        HapticChannel::LeftTrackpad => {
            if intensity > 0 {
                // Enable haptic driver
                unsafe { 
                    match HAPTIC_LEFT_ENABLE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_LEFT_ENABLE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_LEFT_ENABLE.1))),
                        _ => {}
                    }
                    
                    // Set activation level - this would ideally be PWM
                    // For now we'll just turn it on or off
                    match HAPTIC_LEFT_ACTIVATE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_LEFT_ACTIVATE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_LEFT_ACTIVATE.1))),
                        _ => {}
                    }
                }
            } else {
                // Disable haptic
                unsafe { 
                    match HAPTIC_LEFT_ENABLE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_LEFT_ENABLE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_LEFT_ENABLE.1))),
                        _ => {}
                    }
                    
                    match HAPTIC_LEFT_ACTIVATE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_LEFT_ACTIVATE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_LEFT_ACTIVATE.1))),
                        _ => {}
                    }
                }
            }
        },
        HapticChannel::RightTrackpad => {
            if intensity > 0 {
                // Enable haptic driver
                unsafe { 
                    match HAPTIC_RIGHT_ENABLE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_RIGHT_ENABLE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_RIGHT_ENABLE.1))),
                        _ => {}
                    }
                    
                    // Set activation level - this would ideally be PWM
                    match HAPTIC_RIGHT_ACTIVATE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_RIGHT_ACTIVATE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() | (1 << HAPTIC_RIGHT_ACTIVATE.1))),
                        _ => {}
                    }
                }
            } else {
                // Disable haptic
                unsafe { 
                    match HAPTIC_RIGHT_ENABLE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_RIGHT_ENABLE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_RIGHT_ENABLE.1))),
                        _ => {}
                    }
                    
                    match HAPTIC_RIGHT_ACTIVATE.0 {
                        0 => gpio0.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_RIGHT_ACTIVATE.1))),
                        1 => gpio1.data.modify(|r, w| w.bits(r.bits() & !(1 << HAPTIC_RIGHT_ACTIVATE.1))),
                        _ => {}
                    }
                }
            }
        }
    }
}

// Function to toggle the Steam logo LED for debugging
fn toggle_steam_led(gpio1: &lpc11xx::GPIO1, led_state: &mut bool) {
    use hal::pins::LED_CONTROL;
    
    *led_state = !*led_state;
    
    unsafe {
        if *led_state {
            // Turn LED on
            gpio1.data.modify(|r, w| w.bits(r.bits() | (1 << LED_CONTROL.1)));
        } else {
            // Turn LED off
            gpio1.data.modify(|r, w| w.bits(r.bits() & !(1 << LED_CONTROL.1)));
        }
    }
}

// Function to send controller state over UART
#[allow(dead_code)]
fn send_controller_state(usart: &mut UsartDriver, state: &controller::input::ControllerState) {
    use nb::block;

    // Simplified protocol - in a real application you would use a proper binary protocol
    // with checksums, etc.
    
    // Send button states
    let buttons = [
        if state.buttons.a { 1 } else { 0 },
        if state.buttons.b { 1 } else { 0 },
        if state.buttons.x { 1 } else { 0 },
        if state.buttons.y { 1 } else { 0 },
        if state.buttons.lb { 1 } else { 0 },
        if state.buttons.rb { 1 } else { 0 },
        state.buttons.lt,
        state.buttons.rt,
        if state.buttons.back { 1 } else { 0 },
        if state.buttons.start { 1 } else { 0 },
        if state.buttons.steam { 1 } else { 0 },
        if state.buttons.left_stick_click { 1 } else { 0 },
        if state.buttons.right_pad_click { 1 } else { 0 },
        if state.buttons.left_pad_click { 1 } else { 0 },
        if state.buttons.left_grip { 1 } else { 0 },
        if state.buttons.right_grip { 1 } else { 0 },
    ];
    
    // Send header
    block!(usart.write(0xAA)).ok();
    
    // Send button states
    for button in &buttons {
        block!(usart.write(*button)).ok();
    }
    
    // Send joystick position
    block!(usart.write((state.left_stick.x >> 8) as u8)).ok();
    block!(usart.write(state.left_stick.x as u8)).ok();
    block!(usart.write((state.left_stick.y >> 8) as u8)).ok();
    block!(usart.write(state.left_stick.y as u8)).ok();
    
    // Send trackpad data (simplifying to just position, not pressure/touch)
    block!(usart.write((state.left_trackpad.x >> 8) as u8)).ok();
    block!(usart.write(state.left_trackpad.x as u8)).ok();
    block!(usart.write((state.left_trackpad.y >> 8) as u8)).ok();
    block!(usart.write(state.left_trackpad.y as u8)).ok();
    
    block!(usart.write((state.right_trackpad.x >> 8) as u8)).ok();
    block!(usart.write(state.right_trackpad.x as u8)).ok();
    block!(usart.write((state.right_trackpad.y >> 8) as u8)).ok();
    block!(usart.write(state.right_trackpad.y as u8)).ok();
    
    // Send gyro data (simplified)
    block!(usart.write((state.motion.gyro.x >> 8) as u8)).ok();
    block!(usart.write(state.motion.gyro.x as u8)).ok();
    block!(usart.write((state.motion.gyro.y >> 8) as u8)).ok();
    block!(usart.write(state.motion.gyro.y as u8)).ok();
    block!(usart.write((state.motion.gyro.z >> 8) as u8)).ok();
    block!(usart.write(state.motion.gyro.z as u8)).ok();
    
    // Send battery level
    block!(usart.write(state.battery_level)).ok();
    
    // Send end marker
    block!(usart.write(0xFF)).ok();
}

#[entry]
fn main() -> ! {
    let peripherals = Peripherals::take().unwrap();
    
    // Configure all pins for Steam Controller functionality
    hal::configure_all_pins(&peripherals);
    
    // Initialize USB for HID first (before peripherals are moved)
    // Setup the global USB instance
    UsbDriver::setup_global();
    
    // Initialize the USB driver
    let usb_initialized = UsbDriver::initialize_global(&peripherals).is_ok();
    
    // Initialize SPI for trackpads
    // Use the correct peripheral based on the LPC11xx crate's naming
    let mut spi = SpiDriver::new(()); // Using unit type as placeholder since SpiDriver ignores the parameter
    spi.init(SpiMode::Mode0);
    
    // Initialize trackpad drivers
    let mut left_trackpad = Trackpad::new(&mut spi, &peripherals.GPIO0, &peripherals.GPIO1, TrackpadSide::Left);
    
    // Initialize the left trackpad
    match left_trackpad.init() {
        Ok(_) => {
            // Left trackpad initialized successfully
        },
        Err(_) => {
            // Handle left trackpad initialization error
        }
    }
    
    // For now, we'll handle one trackpad at a time due to borrowing constraints
    // In a real implementation, this would need to be refactored to use a shared SPI approach
    // let mut right_trackpad = Trackpad::new(&mut spi, &peripherals.GPIO0, &peripherals.GPIO1, TrackpadSide::Right);
    // match right_trackpad.init() {
    //     Ok(_) => {
    //         // Right trackpad initialized successfully
    //     },
    //     Err(_) => {
    //         // Handle right trackpad initialization error
    //     }
    // }
    
    // Initialize I2C for MPU-6500
    let mut i2c = I2cDriver::new(peripherals.I2C);
    i2c.init();
    
    // Initialize MPU-6500 sensor
    let mut mpu = Mpu6500::new(i2c);
    match mpu.init() {
        Ok(_) => {
            // MPU-6500 initialized successfully
        }
        Err(_) => {
            // Handle initialization error
            // In a real application, you might want to retry or enter error state
        }
    }
    
    // Initialize UART for nRF51822
    let mut usart = UsartDriver::new(peripherals.UART);
    usart.init(115200); // Common baud rate
    
    // Initialize nRF51822 for Bluetooth HID
    let mut nrf51822 = Nrf51822::new(usart);
    match nrf51822.init() {
        Ok(_) => {
            // nRF51822 initialized successfully
        },
        Err(_) => {
            // Handle initialization error
        }
    }
    
    // Initialize ADC for analog inputs
    unsafe {
        // Enable ADC clock - bit 13 is ADC
        peripherals.SYSCON.sysahbclkctrl.modify(|r, w| w.bits(r.bits() | (1 << 13)));
        
        // Configure ADC - Enable ADC and set clock divider
        // CR register: bit 8-15 is clock divider, bit 0 is power down (0 = powered)
        peripherals.ADC.cr.write(|w| w.bits((15 << 8) & !1));
    }
    
    // Power on the joystick
    unsafe {
        match hal::pins::JOYSTICK_POWER_ENABLE.0 {
            0 => peripherals.GPIO0.data.modify(|r, w| w.bits(r.bits() | (1 << hal::pins::JOYSTICK_POWER_ENABLE.1))),
            1 => peripherals.GPIO1.data.modify(|r, w| w.bits(r.bits() | (1 << hal::pins::JOYSTICK_POWER_ENABLE.1))),
            _ => {}
        }
    }
    
    // Initialize Steam Controller
    let mut controller = SteamController::new();
    
    // Calibrate the motion sensor
    match controller.calibrate_motion_sensor(&mut mpu) {
        Ok(_) => {
            // Calibration successful
        }
        Err(_) => {
            // Handle calibration error
        }
    }
    
    // Initialize LED state for debugging
    let mut led_state = false;
    let mut led_counter = 0u32;
    
    // Configure LED pin as output
    unsafe {
        // Set LED pin as output in DIR register
        peripherals.GPIO1.dir.modify(|r, w| w.bits(r.bits() | (1 << hal::pins::LED_CONTROL.1)));
        // Turn LED on initially to show firmware is starting
        peripherals.GPIO1.data.modify(|r, w| w.bits(r.bits() | (1 << hal::pins::LED_CONTROL.1)));
    }
    
    // Import pin definitions for clarity
    use hal::pins::*;
    
    // Enable battery power if not on USB
    let usb_connected = match USB_VBUS.0 {
        0 => (peripherals.GPIO0.data.read().bits() & (1 << USB_VBUS.1)) != 0,
        1 => (peripherals.GPIO1.data.read().bits() & (1 << USB_VBUS.1)) != 0,
        _ => false
    };
    
    if !usb_connected {
        unsafe {
            match POWER_BATTERY_ENABLE.0 {
                0 => peripherals.GPIO0.data.modify(|r, w| w.bits(r.bits() | (1 << POWER_BATTERY_ENABLE.1))),
                1 => peripherals.GPIO1.data.modify(|r, w| w.bits(r.bits() | (1 << POWER_BATTERY_ENABLE.1))),
                _ => {}
            }
        }
    }
    
    let dt_ms = 10; // 10ms loop time for ~100Hz update rate
    
    // LED state for debugging
    let mut led_state = false;
    let mut led_counter = 0u32;
    
    loop {
        // Blink LED every ~1 second for debugging (100 loops * 10ms = 1 second)
        led_counter += 1;
        if led_counter >= 500 {
            led_counter = 0;
            toggle_steam_led(&peripherals.GPIO1, &mut led_state);
        }
        
        // Process motion data from MPU-6500
        match controller.process_motion_data(&mut mpu, dt_ms) {
            Ok(_) => {
                // Motion data processed successfully
            }
            Err(_) => {
                // Handle motion sensor error
            }
        }
        
        // Read button states
        let gpio0_state = peripherals.GPIO0.data.read().bits();
        let gpio1_state = peripherals.GPIO1.data.read().bits();
        
        // Update button states in controller
        controller.process_button_input(gpio0_state | (gpio1_state << 16));
        
        // Read analog inputs for triggers
        let left_trigger = read_adc(&peripherals.ADC, ADC_LEFT_TRIGGER_CHANNEL) as u8;
        let right_trigger = read_adc(&peripherals.ADC, ADC_RIGHT_TRIGGER_CHANNEL) as u8;
        
        // Update triggers in controller
        controller.process_analog_input(left_trigger, right_trigger);
        
        // Read joystick position
        let joystick_x = read_adc(&peripherals.ADC, ADC_JOYSTICK_X_CHANNEL) as i16 - 2048; // Center around 0
        let joystick_y = read_adc(&peripherals.ADC, ADC_JOYSTICK_Y_CHANNEL) as i16 - 2048;
        
        // Update joystick in controller
        controller.update_stick(StickData { x: joystick_x, y: joystick_y });
        
        // Read trackpad data via SPI with filtering
        let left_pad = match left_trackpad.get_filtered_trackpad_data() {
            Ok(data) => data,
            Err(_) => TrackpadData::default(),
        };
        
        let right_pad = TrackpadData::default(); // Right trackpad disabled for now due to borrowing constraints
        // let right_pad = match right_trackpad.get_filtered_trackpad_data() {
        //     Ok(data) => data,
        //     Err(_) => TrackpadData::default(),
        // };
        
        controller.update_trackpads(left_pad, right_pad);
        
        // Read battery voltage via ADC (if on battery power)
        let battery_level = if !usb_connected {
            let battery_raw = read_adc(&peripherals.ADC, ADC_BATTERY_VOLTAGE_CHANNEL);
            // Convert to percentage (very simplified)
            // Assuming 12-bit ADC (0-4095) and voltage range of 0-3.3V
            // Fully charged battery ~4.2V, minimum ~3.0V
            // With voltage divider, this could be scaled to ADC range
            ((battery_raw as u32 * 100) / 4095) as u8
        } else {
            100 // On USB power, assume 100%
        };
        controller.update_battery(battery_level);
        
        // Update controller state
        controller.update(dt_ms);
        
        // Get current controller state
        let state = controller.get_controller_state();
        
        // Send HID reports over Bluetooth using nRF51822
        let _ = nrf51822.process_controller_state(&state);
        
        // Check for Bluetooth responses
        let _ = nrf51822.process_responses();
        
        // Process USB HID reports if USB is initialized
        if usb_initialized {
            UsbDriver::process_global(&state);
        }
        
        // Handle haptic feedback
        let (left_haptic, right_haptic) = controller.get_haptic_intensities();
        apply_haptic(&peripherals.GPIO0, &peripherals.GPIO1, HapticChannel::LeftTrackpad, left_haptic);
        apply_haptic(&peripherals.GPIO0, &peripherals.GPIO1, HapticChannel::RightTrackpad, right_haptic);
        
        // Simple delay to maintain loop timing
        // In a real implementation, use a proper timer
        for _ in 0..10000 {
            // Delay loop
        }
    }
}