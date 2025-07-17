// Haptic feedback system for Steam Controller
// The Steam Controller uses linear actuators for haptic feedback

#[derive(Debug, Clone, Copy)]
pub enum HapticChannel {
    LeftTrackpad,
    RightTrackpad,
}

#[derive(Debug, Clone, Copy)]
pub struct HapticCommand {
    pub channel: HapticChannel,
    pub intensity: u8,    // 0-255
    pub duration_ms: u16, // Duration in milliseconds
    pub pattern: HapticPattern,
}

#[derive(Debug, Clone, Copy)]
pub enum HapticPattern {
    Constant,
    Pulse,
    Ramp,
    Click,
    Buzz,
}

pub struct HapticController {
    left_active: bool,
    right_active: bool,
    left_timer: u32,
    right_timer: u32,
    left_intensity: u8,
    right_intensity: u8,
}

impl HapticController {
    pub fn new() -> Self {
        HapticController {
            left_active: false,
            right_active: false,
            left_timer: 0,
            right_timer: 0,
            left_intensity: 0,
            right_intensity: 0,
        }
    }

    pub fn trigger_haptic(&mut self, command: HapticCommand) {
        match command.channel {
            HapticChannel::LeftTrackpad => {
                self.left_active = true;
                self.left_timer = command.duration_ms as u32;
                self.left_intensity = command.intensity;
            }
            HapticChannel::RightTrackpad => {
                self.right_active = true;
                self.right_timer = command.duration_ms as u32;
                self.right_intensity = command.intensity;
            }
        }
    }

    pub fn update(&mut self, dt_ms: u32) {
        // Update left haptic
        if self.left_active {
            if self.left_timer > dt_ms {
                self.left_timer -= dt_ms;
            } else {
                self.left_active = false;
                self.left_timer = 0;
                self.left_intensity = 0;
            }
        }

        // Update right haptic
        if self.right_active {
            if self.right_timer > dt_ms {
                self.right_timer -= dt_ms;
            } else {
                self.right_active = false;
                self.right_timer = 0;
                self.right_intensity = 0;
            }
        }
    }

    pub fn get_left_intensity(&self) -> u8 {
        if self.left_active {
            self.left_intensity
        } else {
            0
        }
    }

    pub fn get_right_intensity(&self) -> u8 {
        if self.right_active {
            self.right_intensity
        } else {
            0
        }
    }

    pub fn stop_all(&mut self) {
        self.left_active = false;
        self.right_active = false;
        self.left_timer = 0;
        self.right_timer = 0;
        self.left_intensity = 0;
        self.right_intensity = 0;
    }

    // Predefined haptic effects
    pub fn click_feedback(&mut self, channel: HapticChannel) {
        let command = HapticCommand {
            channel,
            intensity: 128,
            duration_ms: 50,
            pattern: HapticPattern::Click,
        };
        self.trigger_haptic(command);
    }

    pub fn trackpad_edge_feedback(&mut self, channel: HapticChannel) {
        let command = HapticCommand {
            channel,
            intensity: 64,
            duration_ms: 30,
            pattern: HapticPattern::Pulse,
        };
        self.trigger_haptic(command);
    }

    pub fn button_press_feedback(&mut self, channel: HapticChannel) {
        let command = HapticCommand {
            channel,
            intensity: 96,
            duration_ms: 40,
            pattern: HapticPattern::Click,
        };
        self.trigger_haptic(command);
    }
}
