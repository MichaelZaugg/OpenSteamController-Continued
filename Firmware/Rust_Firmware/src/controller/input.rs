use crate::drivers::mpu6500::{AccelData, GyroData};
use libm::sqrtf;

// Button mask enum for identifying individual buttons
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
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

// Advanced complementary filter for motion data with quaternion fusion
pub struct MotionFilter {
    quaternion: [f32; 4],
    gyro_bias: [f32; 3],
    accel_bias: [f32; 3],
    alpha: f32, // Filter coefficient
    beta: f32,  // Gyro bias learning rate
    initialized: bool,
}

impl MotionFilter {
    pub fn new() -> Self {
        MotionFilter {
            quaternion: [1.0, 0.0, 0.0, 0.0],
            gyro_bias: [0.0, 0.0, 0.0],
            accel_bias: [0.0, 0.0, 0.0],
            alpha: 0.02, // Small value favors gyroscope
            beta: 0.001, // Small bias learning rate
            initialized: false,
        }
    }
    
    pub fn initialize(&mut self, accel: AccelData) {
        // Initialize quaternion from accelerometer
        let ax = accel.x as f32;
        let ay = accel.y as f32;
        let az = accel.z as f32;
        
        let norm = sqrtf(ax * ax + ay * ay + az * az);
        if norm > 0.0 {
            let ax_norm = ax / norm;
            let ay_norm = ay / norm;
            let az_norm = az / norm;
            
            // Calculate initial quaternion from gravity vector
            // Assuming Z is up initially
            let roll = libm::atan2f(ay_norm, az_norm);
            let pitch = libm::atan2f(-ax_norm, sqrtf(ay_norm * ay_norm + az_norm * az_norm));
            
            let cr = libm::cosf(roll * 0.5);
            let sr = libm::sinf(roll * 0.5);
            let cp = libm::cosf(pitch * 0.5);
            let sp = libm::sinf(pitch * 0.5);
            
            self.quaternion[0] = cr * cp; // w
            self.quaternion[1] = sr * cp; // x
            self.quaternion[2] = cr * sp; // y
            self.quaternion[3] = 0.0;     // z (yaw = 0)
        }
        
        self.initialized = true;
    }

    pub fn update(&mut self, accel: AccelData, gyro: GyroData, dt: f32) -> [f32; 4] {
        if !self.initialized {
            self.initialize(accel);
            return self.quaternion;
        }
        
        // Convert to floating point and apply bias correction
        let gx = (gyro.x as f32) * (3.14159 / 180.0) / 131.0 - self.gyro_bias[0]; // Convert to rad/s
        let gy = (gyro.y as f32) * (3.14159 / 180.0) / 131.0 - self.gyro_bias[1];
        let gz = (gyro.z as f32) * (3.14159 / 180.0) / 131.0 - self.gyro_bias[2];
        
        let ax = (accel.x as f32) / 16384.0 - self.accel_bias[0]; // Convert to g
        let ay = (accel.y as f32) / 16384.0 - self.accel_bias[1];
        let az = (accel.z as f32) / 16384.0 - self.accel_bias[2];
        
        // Normalize accelerometer measurement
        let accel_norm = sqrtf(ax * ax + ay * ay + az * az);
        if accel_norm == 0.0 {
            return self.quaternion;
        }
        
        let ax_norm = ax / accel_norm;
        let ay_norm = ay / accel_norm;
        let az_norm = az / accel_norm;
        
        // Extract quaternion components
        let q0 = self.quaternion[0];
        let q1 = self.quaternion[1];
        let q2 = self.quaternion[2];
        let q3 = self.quaternion[3];
        
        // Estimated direction of gravity from quaternion
        let vx = 2.0 * (q1 * q3 - q0 * q2);
        let vy = 2.0 * (q0 * q1 + q2 * q3);
        let vz = q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3;
        
        // Error is cross product between estimated and measured direction of gravity
        let ex = ay_norm * vz - az_norm * vy;
        let ey = az_norm * vx - ax_norm * vz;
        let ez = ax_norm * vy - ay_norm * vx;
        
        // Apply proportional feedback to gyroscope bias
        self.gyro_bias[0] += self.beta * ex * dt;
        self.gyro_bias[1] += self.beta * ey * dt;
        self.gyro_bias[2] += self.beta * ez * dt;
        
        // Apply corrected gyroscope measurements
        let gx_corrected = gx + self.alpha * ex;
        let gy_corrected = gy + self.alpha * ey;
        let gz_corrected = gz + self.alpha * ez;
        
        // Integrate quaternion rate of change
        let q_dot0 = -0.5 * (q1 * gx_corrected + q2 * gy_corrected + q3 * gz_corrected);
        let q_dot1 = 0.5 * (q0 * gx_corrected + q2 * gz_corrected - q3 * gy_corrected);
        let q_dot2 = 0.5 * (q0 * gy_corrected - q1 * gz_corrected + q3 * gx_corrected);
        let q_dot3 = 0.5 * (q0 * gz_corrected + q1 * gy_corrected - q2 * gx_corrected);
        
        // Integrate to get new quaternion
        self.quaternion[0] += q_dot0 * dt;
        self.quaternion[1] += q_dot1 * dt;
        self.quaternion[2] += q_dot2 * dt;
        self.quaternion[3] += q_dot3 * dt;
        
        // Normalize quaternion
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
        
        self.quaternion
    }
    
    /// Get Euler angles from quaternion (roll, pitch, yaw in radians)
    pub fn get_euler_angles(&self) -> (f32, f32, f32) {
        let q0 = self.quaternion[0];
        let q1 = self.quaternion[1];
        let q2 = self.quaternion[2];
        let q3 = self.quaternion[3];
        
        let roll = libm::atan2f(2.0 * (q0 * q1 + q2 * q3), 1.0 - 2.0 * (q1 * q1 + q2 * q2));
        let pitch = libm::asinf(2.0 * (q0 * q2 - q3 * q1));
        let yaw = libm::atan2f(2.0 * (q0 * q3 + q1 * q2), 1.0 - 2.0 * (q2 * q2 + q3 * q3));
        
        (roll, pitch, yaw)
    }
    
    /// Get rotation matrix from quaternion
    pub fn get_rotation_matrix(&self) -> [[f32; 3]; 3] {
        let q0 = self.quaternion[0];
        let q1 = self.quaternion[1];
        let q2 = self.quaternion[2];
        let q3 = self.quaternion[3];
        
        [
            [1.0 - 2.0 * (q2 * q2 + q3 * q3), 2.0 * (q1 * q2 - q0 * q3), 2.0 * (q1 * q3 + q0 * q2)],
            [2.0 * (q1 * q2 + q0 * q3), 1.0 - 2.0 * (q1 * q1 + q3 * q3), 2.0 * (q2 * q3 - q0 * q1)],
            [2.0 * (q1 * q3 - q0 * q2), 2.0 * (q2 * q3 + q0 * q1), 1.0 - 2.0 * (q1 * q1 + q2 * q2)]
        ]
    }
    
    /// Reset the filter
    pub fn reset(&mut self) {
        self.quaternion = [1.0, 0.0, 0.0, 0.0];
        self.gyro_bias = [0.0, 0.0, 0.0];
        self.accel_bias = [0.0, 0.0, 0.0];
        self.initialized = false;
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
    
    pub fn update_battery(&mut self, level: u8) {
        self.current_state.battery_level = level;
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
    
    /// Advanced input processing methods
    
    /// Process trackpad gestures
    pub fn process_gestures(&mut self, left_pad: TrackpadData, right_pad: TrackpadData) {
        // Update trackpad data first
        self.update_trackpads(left_pad, right_pad);
        
        // Detect swipe gestures on trackpads
        let _left_swipe = self.detect_swipe(left_pad, true);
        let _right_swipe = self.detect_swipe(right_pad, false);
        
        // Store gesture information in current state
        // This would need additional fields in ControllerState
    }
    
    /// Detect swipe gesture on trackpad
    fn detect_swipe(&self, pad_data: TrackpadData, is_left: bool) -> Option<SwipeGesture> {
        // Simple swipe detection based on velocity and direction
        let previous_pad = if is_left {
            self.previous_state.left_trackpad
        } else {
            self.previous_state.right_trackpad
        };
        
        if pad_data.touching && previous_pad.touching {
            let dx = pad_data.x - previous_pad.x;
            let dy = pad_data.y - previous_pad.y;
            let velocity = sqrtf((dx * dx + dy * dy) as f32);
            
            // Threshold for swipe detection
            if velocity > 500.0 {
                // Determine swipe direction
                if dx.abs() > dy.abs() {
                    if dx > 0 {
                        Some(SwipeGesture::Right)
                    } else {
                        Some(SwipeGesture::Left)
                    }
                } else {
                    if dy > 0 {
                        Some(SwipeGesture::Up)
                    } else {
                        Some(SwipeGesture::Down)
                    }
                }
            } else {
                None
            }
        } else {
            None
        }
    }
    
    /// Get motion data with enhanced filtering
    pub fn get_enhanced_motion(&self) -> MotionData {
        let motion = self.current_state.motion;
        
        // Apply additional filtering if needed
        // For now, just return the current motion data
        motion
    }
    
    /// Detect if controller is being shaken
    pub fn detect_shake(&self) -> bool {
        let accel_magnitude = {
            let a = self.current_state.motion.accel;
            let x = a.x as f32;
            let y = a.y as f32;
            let z = a.z as f32;
            sqrtf(x * x + y * y + z * z)
        };
        
        // Simple shake detection based on acceleration magnitude
        // Threshold would need tuning based on actual hardware
        accel_magnitude > 20000.0 // Adjust threshold as needed
    }
    
    /// Get controller orientation as roll, pitch, yaw
    pub fn get_orientation(&self) -> (f32, f32, f32) {
        let q = self.current_state.motion.quaternion;
        let q0 = q[0];
        let q1 = q[1];
        let q2 = q[2];
        let q3 = q[3];
        
        let roll = libm::atan2f(2.0 * (q0 * q1 + q2 * q3), 1.0 - 2.0 * (q1 * q1 + q2 * q2));
        let pitch = libm::asinf(2.0 * (q0 * q2 - q3 * q1));
        let yaw = libm::atan2f(2.0 * (q0 * q3 + q1 * q2), 1.0 - 2.0 * (q2 * q2 + q3 * q3));
        
        (roll, pitch, yaw)
    }
}

/// Swipe gesture types
#[derive(Debug, Clone, Copy)]
pub enum SwipeGesture {
    Up,
    Down,
    Left,
    Right,
}
