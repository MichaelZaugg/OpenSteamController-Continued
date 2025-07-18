// Steam Controller Pin Configuration - Hardware Verified
// This file contains the ACTUAL pin assignments based on the schematic
// Updated to match the real hardware layout

// =============================================================================
// LPC11U37F/501 Pin Assignments (Based on Schematic Analysis)
// =============================================================================

// Main processor - LPC11U37F/501 (U1)
// Pin format: (port, pin) where port is 0 or 1, pin is 0-31

// =============================================================================
// BUTTON INPUTS (Active Low with Pull-ups)
// =============================================================================
pub const BUTTON_A: (u8, u8) = (0, 17);           // S1 - A Button
pub const BUTTON_B: (u8, u8) = (1, 22);           // S4 - B Button  
pub const BUTTON_X: (u8, u8) = (1, 9);            // S7 - X Button
pub const BUTTON_Y: (u8, u8) = (1, 11);           // S9 - Y Button
pub const BUTTON_STEAM: (u8, u8) = (1, 19);       // S18 - Steam Button
pub const BUTTON_LEFT_BUMPER: (u8, u8) = (1, 6);  // S8 - Left Bumper
pub const BUTTON_RIGHT_BUMPER: (u8, u8) = (1, 14); // S10 - Right Bumper
pub const BUTTON_LEFT_TRIGGER_DIGITAL: (u8, u8) = (1, 27); // S3 - Left Trigger Digital
pub const BUTTON_RIGHT_TRIGGER_DIGITAL: (u8, u8) = (1, 13); // S6 - Right Trigger Digital
pub const BUTTON_LEFT_TRACKPAD_CLICK: (u8, u8) = (1, 26);  // S2 - Left Trackpad Click
pub const BUTTON_RIGHT_TRACKPAD_CLICK: (u8, u8) = (1, 21); // S5 - Right Trackpad Click
pub const BUTTON_LEFT_GRIP: (u8, u8) = (1, 25);    // S14 - Left Inner Grip
pub const BUTTON_RIGHT_GRIP: (u8, u8) = (1, 3);    // S16 - Right Inner Grip
pub const BUTTON_FRONT_LEFT: (u8, u8) = (1, 4);    // S20 - Front Left (Back Button)
pub const BUTTON_FRONT_RIGHT: (u8, u8) = (1, 2);   // S19 - Front Right (Back Button)
pub const BUTTON_JOYSTICK_CLICK: (u8, u8) = (1, 0); // S11 - Analog Joystick Click

// Backward compatibility aliases
pub const BUTTON_ANALOG_JOY_CLICK: (u8, u8) = BUTTON_JOYSTICK_CLICK;
pub const BUTTON_LEFT_TRACKPAD: (u8, u8) = BUTTON_LEFT_TRACKPAD_CLICK;
pub const BUTTON_RIGHT_TRACKPAD: (u8, u8) = BUTTON_RIGHT_TRACKPAD_CLICK;
pub const BUTTON_LEFT_TRIGGER: (u8, u8) = BUTTON_LEFT_TRIGGER_DIGITAL;
pub const BUTTON_RIGHT_TRIGGER: (u8, u8) = BUTTON_RIGHT_TRIGGER_DIGITAL;

// Analog Inputs (ADC)
pub const ANALOG_LEFT_TRIGGER: (u8, u8) = (0, 11);      // Pin 42 - TDI/PIO0_11/AD0
pub const ANALOG_RIGHT_TRIGGER: (u8, u8) = (0, 13);     // Pin 45 - TDO/PIO0_13/AD2
pub const ANALOG_JOYSTICK_X: (u8, u8) = (0, 12);        // Pin 44 - TMS/PIO0_12/AD1
pub const ANALOG_JOYSTICK_Y: (u8, u8) = (0, 14);        // Pin 46 - nTRST/PIO0_14/AD3

// I2C Interface (MPU-6500)
pub const I2C_SCL: (u8, u8) = (0, 4);                   // Pin 16 - PIO0_4/SCL
pub const I2C_SDA: (u8, u8) = (0, 5);                   // Pin 17 - PIO0_5/SDA

// SPI Interface (Trackpads)
pub const SPI_SCK: (u8, u8) = (1, 29);                  // Pin 41 - PIO1_29/SCK0
pub const SPI_MISO: (u8, u8) = (0, 8);                  // Pin 22 - PIO0_8/MISO0
pub const SPI_MOSI: (u8, u8) = (0, 9);                  // Pin 23 - PIO0_9/MOSI0

// Trackpad Chip Select pins
pub const TRACKPAD_RIGHT_CS: (u8, u8) = (1, 15);        // Pin 57 - PIO1_15
pub const TRACKPAD_LEFT_CS: (u8, u8) = (1, 16);         // Pin 38 - PIO1_16

// Trackpad Data Ready pins
pub const TRACKPAD_RIGHT_DR: (u8, u8) = (0, 23);        // Pin 56 - PIO0_23
pub const TRACKPAD_LEFT_DR: (u8, u8) = (1, 23);         // Pin 37 - PIO1_23

// UART Interface (nRF51822)
pub const UART_RX: (u8, u8) = (1, 17);                  // Pin 36 - PIO1_17/RXD
pub const UART_TX: (u8, u8) = (1, 18);                  // Pin 28 - PIO1_18/TXD

// Haptic Control
pub const HAPTIC_LEFT_ENABLE: (u8, u8) = (1, 7);        // Pin 6 - PIO1_7
pub const HAPTIC_RIGHT_ENABLE: (u8, u8) = (1, 12);      // Pin 59 - PIO1_12
pub const HAPTIC_LEFT_ACTIVATE: (u8, u8) = (0, 18);     // Pin 25 - PIO0_18
pub const HAPTIC_RIGHT_ACTIVATE: (u8, u8) = (0, 2);     // Pin 13 - PIO0_2 (alt function)

// Power Management
pub const POWER_BATTERY_ENABLE: (u8, u8) = (1, 10);     // Pin 12 - PIO1_10
pub const POWER_USB_DETECT: (u8, u8) = (0, 3);          // Pin 18 - PIO0_3

// LED Control
pub const LED_CONTROL: (u8, u8) = (1, 8);               // Pin 26 - PIO1_8

// USB Interface
pub const USB_CONNECT: (u8, u8) = (0, 6);               // Pin 29 - PIO0_6/USB_CONNECT
pub const USB_VBUS: (u8, u8) = (0, 3);                  // Pin 18 - PIO0_3/USB_VBUS

// Debug Interface
pub const DEBUG_SWDIO: (u8, u8) = (0, 15);              // Pin 52 - SWDIO/PIO0_15
pub const DEBUG_SWCLK: (u8, u8) = (0, 10);              // Pin 24 - SWCLK/PIO0_10

// Joystick Power Enable
pub const JOYSTICK_POWER_ENABLE: (u8, u8) = (0, 19);    // Pin 19 - PIO0_19

// Miscellaneous
pub const MISC_GPIO1_28: (u8, u8) = (1, 28);            // Pin 31 - PIO1_28
pub const MISC_GPIO0_7: (u8, u8) = (0, 7);              // Pin 30 - PIO0_7
pub const MISC_GPIO1_24: (u8, u8) = (1, 24);            // Pin 27 - PIO1_24
pub const MISC_GPIO1_5: (u8, u8) = (1, 5);              // Pin 32 - PIO1_5

// Radio/nRF51822 related
pub const RADIO_GPIO1_5: (u8, u8) = (1, 5);             // Pin 32 - PIO1_5 (PINT2 monitored)

// Default pin configurations
pub mod pin_config {
    use super::*;
    
    pub struct PinConfig {
        pub port: u8,
        pub pin: u8,
        pub direction: bool,  // true = output, false = input
        pub pull_up: bool,
        pub pull_down: bool,
        pub function: u8,     // 0 = GPIO, 1-7 = alternate functions
    }
    
    // Button configurations (all inputs with pull-up)
    pub const BUTTON_CONFIGS: &[(&str, PinConfig)] = &[
        ("ANALOG_JOY_CLICK", PinConfig { port: 1, pin: 0, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("LEFT_GRIP", PinConfig { port: 1, pin: 25, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("STEAM", PinConfig { port: 1, pin: 19, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("LEFT_TRACKPAD", PinConfig { port: 1, pin: 26, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("LEFT_TRIGGER", PinConfig { port: 1, pin: 27, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("RIGHT_TRACKPAD", PinConfig { port: 1, pin: 21, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("RIGHT_TRIGGER", PinConfig { port: 1, pin: 13, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("RIGHT_BUMPER", PinConfig { port: 1, pin: 14, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("RIGHT_GRIP", PinConfig { port: 1, pin: 3, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("BUTTON_B", PinConfig { port: 1, pin: 22, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("BUTTON_X", PinConfig { port: 1, pin: 9, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("BUTTON_A", PinConfig { port: 0, pin: 17, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("BUTTON_Y", PinConfig { port: 1, pin: 11, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("FRONT_RIGHT", PinConfig { port: 1, pin: 2, direction: false, pull_up: true, pull_down: false, function: 0 }),
        ("FRONT_LEFT", PinConfig { port: 1, pin: 4, direction: false, pull_up: true, pull_down: false, function: 0 }),
    ];
    
    // I2C configurations
    pub const I2C_CONFIGS: &[(&str, PinConfig)] = &[
        ("I2C_SCL", PinConfig { port: 0, pin: 4, direction: false, pull_up: false, pull_down: false, function: 1 }),
        ("I2C_SDA", PinConfig { port: 0, pin: 5, direction: false, pull_up: false, pull_down: false, function: 1 }),
    ];
    
    // SPI configurations
    pub const SPI_CONFIGS: &[(&str, PinConfig)] = &[
        ("SPI_SCK", PinConfig { port: 1, pin: 29, direction: true, pull_up: false, pull_down: false, function: 1 }),
        ("SPI_MISO", PinConfig { port: 0, pin: 8, direction: false, pull_up: false, pull_down: false, function: 1 }),
        ("SPI_MOSI", PinConfig { port: 0, pin: 9, direction: true, pull_up: false, pull_down: false, function: 1 }),
        ("RIGHT_CS", PinConfig { port: 1, pin: 15, direction: true, pull_up: false, pull_down: false, function: 0 }),
        ("LEFT_CS", PinConfig { port: 1, pin: 16, direction: true, pull_up: false, pull_down: false, function: 0 }),
        ("RIGHT_DR", PinConfig { port: 0, pin: 23, direction: false, pull_up: false, pull_down: true, function: 0 }),
        ("LEFT_DR", PinConfig { port: 1, pin: 23, direction: false, pull_up: false, pull_down: true, function: 0 }),
    ];
    
    // UART configurations
    pub const UART_CONFIGS: &[(&str, PinConfig)] = &[
        ("UART_RX", PinConfig { port: 1, pin: 17, direction: false, pull_up: false, pull_down: false, function: 2 }),
        ("UART_TX", PinConfig { port: 1, pin: 18, direction: true, pull_up: false, pull_down: false, function: 2 }),
    ];
    
    // Haptic configurations
    pub const HAPTIC_CONFIGS: &[(&str, PinConfig)] = &[
        ("LEFT_ENABLE", PinConfig { port: 1, pin: 7, direction: true, pull_up: false, pull_down: false, function: 0 }),
        ("RIGHT_ENABLE", PinConfig { port: 1, pin: 12, direction: true, pull_up: false, pull_down: false, function: 0 }),
        ("LEFT_ACTIVATE", PinConfig { port: 0, pin: 18, direction: true, pull_up: false, pull_down: false, function: 0 }),
        ("RIGHT_ACTIVATE", PinConfig { port: 0, pin: 2, direction: true, pull_up: false, pull_down: false, function: 0 }),
    ];
    
    // Power management configurations
    pub const POWER_CONFIGS: &[(&str, PinConfig)] = &[
        ("BATTERY_ENABLE", PinConfig { port: 1, pin: 10, direction: true, pull_up: false, pull_down: false, function: 0 }),
        ("USB_DETECT", PinConfig { port: 0, pin: 3, direction: false, pull_up: false, pull_down: true, function: 0 }),
        ("USB_CONNECT", PinConfig { port: 0, pin: 6, direction: true, pull_up: false, pull_down: false, function: 1 }),
        ("JOYSTICK_POWER", PinConfig { port: 0, pin: 19, direction: true, pull_up: false, pull_down: false, function: 0 }),
    ];
    
    // ADC configurations (for analog triggers and joystick)
    pub const ADC_CONFIGS: &[(&str, PinConfig)] = &[
        ("LEFT_TRIGGER_ADC", PinConfig { port: 0, pin: 11, direction: false, pull_up: false, pull_down: false, function: 2 }),
        ("RIGHT_TRIGGER_ADC", PinConfig { port: 0, pin: 13, direction: false, pull_up: false, pull_down: false, function: 2 }),
        ("JOYSTICK_X_ADC", PinConfig { port: 0, pin: 12, direction: false, pull_up: false, pull_down: false, function: 2 }),
        ("JOYSTICK_Y_ADC", PinConfig { port: 0, pin: 14, direction: false, pull_up: false, pull_down: false, function: 2 }),
    ];
}
