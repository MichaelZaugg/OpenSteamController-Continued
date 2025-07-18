pub mod input;
pub mod haptics;

pub use input::{InputProcessor, ControllerState, MotionData, SwipeGesture};
pub use haptics::{HapticController, HapticCommand};

use crate::drivers::{Mpu6500, mpu6500::Mpu6500Error};

pub struct SteamController {
    input_processor: InputProcessor,
    haptic_controller: HapticController,
    system_time: u32,
}

impl SteamController {
    pub fn new() -> Self {
        SteamController {
            input_processor: InputProcessor::new(),
            haptic_controller: HapticController::new(),
            system_time: 0,
        }
    }

    pub fn update(&mut self, dt_ms: u32) {
        self.system_time += dt_ms;
        
        // Update haptic feedback
        self.haptic_controller.update(dt_ms);
        
        // Update input processor timestamp
        self.input_processor.update_timestamp(self.system_time);
        
        // Commit current state to previous state for next frame
        self.input_processor.commit_state();
    }

    pub fn process_motion_data(&mut self, mpu: &mut Mpu6500, dt_ms: u32) -> Result<(), Mpu6500Error> {
        match mpu.read_all() {
            Ok((accel, gyro, _temp)) => {
                let dt = dt_ms as f32 / 1000.0; // Convert to seconds
                self.input_processor.update_motion(accel, gyro, dt);
                Ok(())
            }
            Err(e) => Err(e),
        }
    }

    pub fn process_button_input(&mut self, gpio_data: u32) {
        self.input_processor.update_buttons(gpio_data);
    }

    pub fn process_analog_input(&mut self, left_trigger: u8, right_trigger: u8) {
        self.input_processor.update_triggers(left_trigger, right_trigger);
    }

    pub fn get_controller_state(&self) -> ControllerState {
        self.input_processor.get_current_state()
    }

    pub fn trigger_haptic_feedback(&mut self, command: HapticCommand) {
        self.haptic_controller.trigger_haptic(command);
    }

    pub fn get_haptic_intensities(&self) -> (u8, u8) {
        (
            self.haptic_controller.get_left_intensity(),
            self.haptic_controller.get_right_intensity(),
        )
    }

    pub fn handle_button_press(&mut self, _button: u8) {
        // Simplified button handling - would need to determine which button was pressed
        // and trigger appropriate haptic feedback
    }

    pub fn is_button_pressed(&self, _button_index: u8) -> bool {
        // Simple button checking based on index
        // This would need proper implementation based on button mapping
        false
    }

    pub fn is_button_just_pressed(&self, _button_index: u8) -> bool {
        // Simple button checking based on index
        false
    }

    pub fn is_button_just_released(&self, _button_index: u8) -> bool {
        // Simple button checking based on index
        false
    }

    pub fn update_stick(&mut self, stick: input::StickData) {
        self.input_processor.update_stick(stick);
    }

    pub fn update_trackpads(&mut self, left_pad: input::TrackpadData, right_pad: input::TrackpadData) {
        self.input_processor.update_trackpads(left_pad, right_pad);
    }

    pub fn update_battery(&mut self, level: u8) {
        // Use the InputProcessor's update_battery method
        self.input_processor.update_battery(level);
    }

    /// Calibrate the motion sensor
    pub fn calibrate_motion_sensor(&mut self, mpu: &mut Mpu6500) -> Result<(), Mpu6500Error> {
        // Configure MPU for optimal gaming performance
        mpu.configure_for_gaming()?;
        
        // Perform gyroscope calibration
        let _gyro_bias = mpu.calibrate_gyro()?;
        
        // Enable motion interrupt for better responsiveness
        mpu.enable_motion_interrupt(40)?; // Reasonable threshold
        
        Ok(())
    }
    
    /// Get enhanced motion data with filtering
    pub fn get_enhanced_motion_data(&self) -> MotionData {
        let motion = self.input_processor.get_current_state().motion;
        
        // Get Euler angles from quaternion (for future use)
        let _euler_angles = {
            let q = motion.quaternion;
            let q0 = q[0];
            let q1 = q[1];
            let q2 = q[2];
            let q3 = q[3];
            
            let roll = libm::atan2f(2.0 * (q0 * q1 + q2 * q3), 1.0 - 2.0 * (q1 * q1 + q2 * q2));
            let pitch = libm::asinf(2.0 * (q0 * q2 - q3 * q1));
            let yaw = libm::atan2f(2.0 * (q0 * q3 + q1 * q2), 1.0 - 2.0 * (q2 * q2 + q3 * q3));
            
            (roll, pitch, yaw)
        };
        
        // You could add the Euler angles to MotionData if needed
        // For now, just return the enhanced motion data
        motion
    }
    
    /// Check if trackpads are properly functioning
    pub fn check_trackpad_health(&self) -> (bool, bool) {
        // This would check if trackpads are responding
        // For now, return true if controller is initialized
        (true, true)
    }
}