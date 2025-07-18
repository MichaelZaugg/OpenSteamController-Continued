// USB HID reports for the Steam Controller
//
// This module defines the HID report formats for the Steam Controller.
// In a real implementation, this would be generated using usbd-hid macros,
// but here we provide simplified structures without the external dependencies.

use crate::controller::input::ControllerState;

/// Mouse report structure (4 bytes)
#[derive(Default, Clone, Copy)]
#[allow(dead_code)]
pub struct SteamMouseReport {
    pub buttons: u8,  // Bit 0: Left, Bit 1: Right, Bit 2: Middle
    pub x: i8,        // Relative X movement
    pub y: i8,        // Relative Y movement
    pub wheel: i8,    // Wheel movement
}

/// Keyboard report structure (8 bytes)
#[derive(Default, Clone, Copy)]
#[allow(dead_code)]
pub struct SteamKeyboardReport {
    pub modifier: u8,       // Modifier keys (ctrl, shift, etc.)
    pub reserved: u8,       // Reserved byte
    pub keycodes: [u8; 6],  // Up to 6 simultaneous key presses
}

/// Helper function to convert controller state to mouse report
#[allow(dead_code)]
pub fn controller_to_mouse_report(state: &ControllerState) -> SteamMouseReport {
    // Map right trackpad to mouse movement
    let (x, y) = if state.right_trackpad.touching {
        // Scale trackpad inputs to mouse movement
        // The trackpad provides absolute coordinates, we convert to relative
        (
            (state.right_trackpad.x / 100) as i8,  // Scale down the trackpad range
            (state.right_trackpad.y / 100) as i8
        )
    } else {
        (0, 0)
    };
    
    // Map controller buttons to mouse buttons
    let mut buttons = 0u8;
    if state.buttons.right_pad_click {
        buttons |= 1;  // Left click on right pad click
    }
    if state.buttons.left_pad_click {
        buttons |= 2;  // Right click on left pad click
    }
    if state.buttons.left_grip {
        buttons |= 4;  // Middle click on left grip
    }
    
    // Use left pad vertical movement for scrolling
    let wheel = if state.left_trackpad.touching {
        (state.left_trackpad.y / 200) as i8
    } else {
        0
    };
    
    SteamMouseReport {
        buttons,
        x,
        y,
        wheel,
    }
}

/// Helper function to convert controller state to keyboard report
#[allow(dead_code, unused_assignments)]
pub fn controller_to_keyboard_report(state: &ControllerState) -> SteamKeyboardReport {
    let mut report = SteamKeyboardReport::default();
    let mut keycode_index = 0;
    
    // Map ABXY to keys (A=Z, B=X, X=A, Y=S as an example mapping)
    if state.buttons.a && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x1D;  // Z key
        keycode_index += 1;
    }
    if state.buttons.b && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x1B;  // X key
        keycode_index += 1;
    }
    if state.buttons.x && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x04;  // A key
        keycode_index += 1;
    }
    if state.buttons.y && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x16;  // S key
        keycode_index += 1;
    }
    
    // Map directional controls (like WASD)
    // This would typically use the left stick or D-pad
    let dpad_up = state.left_stick.y > 1000;
    let dpad_down = state.left_stick.y < -1000;
    let dpad_left = state.left_stick.x < -1000;
    let dpad_right = state.left_stick.x > 1000;
    
    if dpad_up && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x1A;  // W key
        keycode_index += 1;
    }
    if dpad_left && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x04;  // A key
        keycode_index += 1;
    }
    if dpad_down && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x16;  // S key
        keycode_index += 1;
    }
    if dpad_right && keycode_index < 6 {
        report.keycodes[keycode_index] = 0x07;  // D key
        keycode_index += 1;
    }
    
    // Modifiers (Ctrl, Shift, etc.)
    if state.buttons.left_grip {
        report.modifier |= 0x01;  // Left Ctrl
    }
    if state.buttons.right_grip {
        report.modifier |= 0x02;  // Left Shift
    }
    
    report
}
