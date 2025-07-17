pub mod input;
pub mod haptics;

pub use input::{InputProcessor, ControllerState, ButtonMask};
pub use haptics::{HapticController, HapticCommand, HapticChannel};

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

    pub fn handle_button_press(&mut self, button: ButtonMask) {
        if self.input_processor.is_button_just_pressed(button) {
            // Trigger haptic feedback for button press
            match button {
                ButtonMask::LeftPadClick => {
                    self.haptic_controller.click_feedback(HapticChannel::LeftTrackpad);
                }
                ButtonMask::RightPadClick => {
                    self.haptic_controller.click_feedback(HapticChannel::RightTrackpad);
                }
                _ => {
                    // For other buttons, could trigger feedback on both trackpads or none
                }
            }
        }
    }

    pub fn is_button_pressed(&self, button: ButtonMask) -> bool {
        self.input_processor.is_button_pressed(button)
    }

    pub fn is_button_just_pressed(&self, button: ButtonMask) -> bool {
        self.input_processor.is_button_just_pressed(button)
    }

    pub fn is_button_just_released(&self, button: ButtonMask) -> bool {
        self.input_processor.is_button_just_released(button)
    }
}