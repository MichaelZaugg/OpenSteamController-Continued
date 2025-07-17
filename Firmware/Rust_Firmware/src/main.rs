#![no_std]
#![no_main]

use cortex_m_rt::entry;
use panic_halt as _;
use lpc11xx::Peripherals;

mod hal;
mod drivers;
mod controller;
mod utils;

use hal::{I2cDriver, UsartDriver};
use drivers::Mpu6500;
use controller::SteamController;

#[entry]
fn main() -> ! {
    let dp = Peripherals::take().unwrap();
    
    // Initialize I2C for MPU-6500
    let mut i2c = I2cDriver::new(dp.I2C);
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
    let mut usart = UsartDriver::new(dp.UART);
    usart.init(115200); // Common baud rate
    
    // Initialize Steam Controller
    let mut controller = SteamController::new();
    
    // GPIO setup for other pins
    let gpio = dp.GPIO0;
    gpio.dir.modify(|r, w| unsafe { w.bits(r.bits() | (1 << 7)) });

    let mut loop_counter = 0u32;
    let dt_ms = 10; // 10ms loop time for ~100Hz update rate

    loop {
        // Process motion data from MPU-6500
        match controller.process_motion_data(&mut mpu, dt_ms) {
            Ok(_) => {
                // Motion data processed successfully
            }
            Err(_) => {
                // Handle motion sensor error
            }
        }
        
        // Read button states (simplified - would need actual GPIO reading)
        let button_state = gpio.data.read().bits();
        controller.process_button_input(button_state);
        
        // Process analog inputs (triggers - would need ADC in real implementation)
        controller.process_analog_input(0, 0); // Placeholder values
        
        // Update controller state
        controller.update(dt_ms);
        
        // Get current controller state
        let state = controller.get_controller_state();
        
        // Send controller state via UART to nRF51822
        // This would be a serialized packet in a real implementation
        
        // Handle haptic feedback
        let (left_haptic, right_haptic) = controller.get_haptic_intensities();
        // Apply haptic intensities to hardware (GPIO/PWM)
        
        loop_counter += 1;
        
        // Simple delay to maintain loop timing
        for _ in 0..10000 {
            // Delay loop - in real implementation, use proper timer
        }
    }
}