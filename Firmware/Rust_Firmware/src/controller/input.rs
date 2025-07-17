use crate::drivers::mpu6500::{AccelData, GyroData};
use libm::sqrtf;

// Steam Controller button mapping
#[derive(Debug, Clone, Copy)]
pub struct ButtonState {
    pub a: bool,
    pub b: bool,
    pub x: bool,
    pub y: bool,
    pub lb: bool,
    pub rb: bool,
    pub lt: u8,        // Left trigger (0-255)
    pub rt: u8,        // Right trigger (0-255)
    pub back: bool,
    pub start: bool,
    pub steam: bool,
    pub left_stick_click: bool,
    pub right_pad_click: bool,
    pub left_pad_click: bool,
    pub left_grip: bool,
    pub right_grip: bool,
}

impl Default for ButtonState {
    fn default() -> Self {
        ButtonState {
            a: false,
            b: false,
            x: false,
            y: false,
            lb: false,
            rb: false,
            lt: 0,
            rt: 0,
            back: false,
            start: false,
            steam: false,
            left_stick_click: false,
            right_pad_click: false,
            left_pad_click: false,
            left_grip: false,
            right_grip: false,
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub struct TrackpadData {
    pub x: i16,
    pub y: i16,
    pub pressure: u8,
    pub touching: bool,
}

impl Default for TrackpadData {
    fn default() -> Self {
        TrackpadData {
            x: 0,
            y: 0,
            pressure: 0,
            touching: false,
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub struct StickData {
    pub x: i16,
    pub y: i16,
}

impl Default for StickData {
    fn default() -> Self {
        StickData {
            x: 0,
            y: 0,
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub struct MotionData {
    pub accel: AccelData,
    pub gyro: GyroData,
    pub quaternion: [f32; 4], // w, x, y, z
}

impl Default for MotionData {
    fn default() -> Self {
        MotionData {
            accel: AccelData { x: 0, y: 0, z: 0 },
            gyro: GyroData { x: 0, y: 0, z: 0 },
            quaternion: [1.0, 0.0, 0.0, 0.0], // Identity quaternion
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub struct ControllerState {
    pub buttons: ButtonState,
    pub left_trackpad: TrackpadData,
    pub right_trackpad: TrackpadData,
    pub left_stick: StickData,
    pub motion: MotionData,
    pub battery_level: u8,
    pub timestamp: u32,
}

impl Default for ControllerState {
    fn default() -> Self {
        ControllerState {
            buttons: ButtonState::default(),
            left_trackpad: TrackpadData::default(),
            right_trackpad: TrackpadData::default(),
            left_stick: StickData::default(),
            motion: MotionData::default(),
            battery_level: 100,
            timestamp: 0,
        }
    }
}

pub struct InputProcessor {
    current_state: ControllerState,
    previous_state: ControllerState,
    motion_filter: MotionFilter,
}

// Simple complementary filter for motion data
pub struct MotionFilter {
    quaternion: [f32; 4],
    alpha: f32, // Filter coefficient
}

impl MotionFilter {
    pub fn new() -> Self {
        MotionFilter {
            quaternion: [1.0, 0.0, 0.0, 0.0],
            alpha: 0.98, // Favor gyroscope data
        }
    }

    pub fn update(&mut self, accel: AccelData, gyro: GyroData, dt: f32) -> [f32; 4] {
        // Simplified complementary filter implementation
        // In a real implementation, you'd want a proper AHRS algorithm
        // For now, just return a simple quaternion based on accelerometer
        
        // Normalize accelerometer data (simplified)
        let accel_norm = sqrtf((accel.x as f32) * (accel.x as f32) + 
                              (accel.y as f32) * (accel.y as f32) + 
                              (accel.z as f32) * (accel.z as f32));
        
        if accel_norm > 0.0 {
            let ax = accel.x as f32 / accel_norm;
            let ay = accel.y as f32 / accel_norm;
            let az = accel.z as f32 / accel_norm;
            
            // Simplified orientation calculation
            // This is a very basic implementation - real AHRS would be more complex
            self.quaternion[0] = 0.9 * self.quaternion[0] + 0.1 * ax;
            self.quaternion[1] = 0.9 * self.quaternion[1] + 0.1 * ay;
            self.quaternion[2] = 0.9 * self.quaternion[2] + 0.1 * az;
            self.quaternion[3] = 0.9 * self.quaternion[3];
            
            // Simple normalization
            let norm = sqrtf(self.quaternion[0] * self.quaternion[0] + 
                            self.quaternion[1] * self.quaternion[1] + 
                            self.quaternion[2] * self.quaternion[2] + 
                            self.quaternion[3] * self.quaternion[3]);
            
            if norm > 0.0 {
                self.quaternion[0] /= norm;
                self.quaternion[1] /= norm;
                self.quaternion[2] /= norm;
                self.quaternion[3] /= norm;
            }
        }
        
        self.quaternion
    }
}

impl InputProcessor {
    pub fn new() -> Self {
        InputProcessor {
            current_state: ControllerState::default(),
            previous_state: ControllerState::default(),
            motion_filter: MotionFilter::new(),
        }
    }

    pub fn update_motion(&mut self, accel: AccelData, gyro: GyroData, dt: f32) {
        self.current_state.motion.accel = accel;
        self.current_state.motion.gyro = gyro;
        self.current_state.motion.quaternion = self.motion_filter.update(accel, gyro, dt);
    }

    pub fn update_buttons(&mut self, raw_button_data: u32) {
        // Parse button data from raw GPIO/ADC readings
        // This is a simplified implementation - real hardware would need proper pin mapping
        self.current_state.buttons.a = (raw_button_data & (1 << 0)) != 0;
        self.current_state.buttons.b = (raw_button_data & (1 << 1)) != 0;
        self.current_state.buttons.x = (raw_button_data & (1 << 2)) != 0;
        self.current_state.buttons.y = (raw_button_data & (1 << 3)) != 0;
        self.current_state.buttons.lb = (raw_button_data & (1 << 4)) != 0;
        self.current_state.buttons.rb = (raw_button_data & (1 << 5)) != 0;
        self.current_state.buttons.back = (raw_button_data & (1 << 6)) != 0;
        self.current_state.buttons.start = (raw_button_data & (1 << 7)) != 0;
        self.current_state.buttons.steam = (raw_button_data & (1 << 8)) != 0;
        self.current_state.buttons.left_stick_click = (raw_button_data & (1 << 9)) != 0;
        self.current_state.buttons.right_pad_click = (raw_button_data & (1 << 10)) != 0;
        self.current_state.buttons.left_pad_click = (raw_button_data & (1 << 11)) != 0;
        self.current_state.buttons.left_grip = (raw_button_data & (1 << 12)) != 0;
        self.current_state.buttons.right_grip = (raw_button_data & (1 << 13)) != 0;
    }

    pub fn update_triggers(&mut self, left_trigger: u8, right_trigger: u8) {
        self.current_state.buttons.lt = left_trigger;
        self.current_state.buttons.rt = right_trigger;
    }

    pub fn update_trackpads(&mut self, left_pad: TrackpadData, right_pad: TrackpadData) {
        self.current_state.left_trackpad = left_pad;
        self.current_state.right_trackpad = right_pad;
    }

    pub fn update_stick(&mut self, stick: StickData) {
        self.current_state.left_stick = stick;
    }

    pub fn update_timestamp(&mut self, timestamp: u32) {
        self.current_state.timestamp = timestamp;
    }

    pub fn get_current_state(&self) -> ControllerState {
        self.current_state
    }

    pub fn get_previous_state(&self) -> ControllerState {
        self.previous_state
    }

    pub fn commit_state(&mut self) {
        self.previous_state = self.current_state;
    }

    pub fn is_button_pressed(&self, button: ButtonMask) -> bool {
        match button {
            ButtonMask::A => self.current_state.buttons.a,
            ButtonMask::B => self.current_state.buttons.b,
            ButtonMask::X => self.current_state.buttons.x,
            ButtonMask::Y => self.current_state.buttons.y,
            ButtonMask::LB => self.current_state.buttons.lb,
            ButtonMask::RB => self.current_state.buttons.rb,
            ButtonMask::Back => self.current_state.buttons.back,
            ButtonMask::Start => self.current_state.buttons.start,
            ButtonMask::Steam => self.current_state.buttons.steam,
            ButtonMask::LeftStickClick => self.current_state.buttons.left_stick_click,
            ButtonMask::RightPadClick => self.current_state.buttons.right_pad_click,
            ButtonMask::LeftPadClick => self.current_state.buttons.left_pad_click,
            ButtonMask::LeftGrip => self.current_state.buttons.left_grip,
            ButtonMask::RightGrip => self.current_state.buttons.right_grip,
        }
    }

    pub fn is_button_just_pressed(&self, button: ButtonMask) -> bool {
        self.is_button_pressed(button) && !self.was_button_pressed(button)
    }

    pub fn is_button_just_released(&self, button: ButtonMask) -> bool {
        !self.is_button_pressed(button) && self.was_button_pressed(button)
    }

    fn was_button_pressed(&self, button: ButtonMask) -> bool {
        match button {
            ButtonMask::A => self.previous_state.buttons.a,
            ButtonMask::B => self.previous_state.buttons.b,
            ButtonMask::X => self.previous_state.buttons.x,
            ButtonMask::Y => self.previous_state.buttons.y,
            ButtonMask::LB => self.previous_state.buttons.lb,
            ButtonMask::RB => self.previous_state.buttons.rb,
            ButtonMask::Back => self.previous_state.buttons.back,
            ButtonMask::Start => self.previous_state.buttons.start,
            ButtonMask::Steam => self.previous_state.buttons.steam,
            ButtonMask::LeftStickClick => self.previous_state.buttons.left_stick_click,
            ButtonMask::RightPadClick => self.previous_state.buttons.right_pad_click,
            ButtonMask::LeftPadClick => self.previous_state.buttons.left_pad_click,
            ButtonMask::LeftGrip => self.previous_state.buttons.left_grip,
            ButtonMask::RightGrip => self.previous_state.buttons.right_grip,
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub enum ButtonMask {
    A,
    B,
    X,
    Y,
    LB,
    RB,
    Back,
    Start,
    Steam,
    LeftStickClick,
    RightPadClick,
    LeftPadClick,
    LeftGrip,
    RightGrip,
}
