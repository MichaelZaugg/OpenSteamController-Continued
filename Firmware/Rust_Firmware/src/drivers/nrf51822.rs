use crate::hal::UsartDriver;
use crate::controller::input::ControllerState;
use crate::hal::usb_hid::{SteamMouseReport, SteamKeyboardReport};

// Bluetooth HID Commands
const BT_HID_CMD_INIT: u8 = 0x01;
const BT_HID_CMD_SET_NAME: u8 = 0x02;
const BT_HID_CMD_ADVERTISE: u8 = 0x03;
const BT_HID_CMD_CONNECT: u8 = 0x04;
const BT_HID_CMD_DISCONNECT: u8 = 0x05;
const BT_HID_CMD_MOUSE_REPORT: u8 = 0x10;
const BT_HID_CMD_KEYBOARD_REPORT: u8 = 0x11;
const BT_HID_CMD_CONSUMER_REPORT: u8 = 0x12; // For media keys

// Bluetooth HID Response Codes
const BT_HID_RESP_SUCCESS: u8 = 0x00;
const BT_HID_RESP_ERROR: u8 = 0xFF;
const BT_HID_RESP_CONNECTED: u8 = 0x01;
const BT_HID_RESP_DISCONNECTED: u8 = 0x02;

pub struct Nrf51822 {
    uart: UsartDriver,
    connected: bool,
    advertising: bool,
}

impl Nrf51822 {
    pub fn new(uart: UsartDriver) -> Self {
        Nrf51822 { 
            uart,
            connected: false,
            advertising: false,
        }
    }

    pub fn init(&mut self) -> Result<(), ()> {
        // Send initialization command
        let init_cmd = [BT_HID_CMD_INIT];
        self.send_data(&init_cmd)?;
        
        // Set device name
        let name = b"Steam Controller";
        let mut name_cmd = [0u8; 17]; // Command byte + 16 bytes for name
        name_cmd[0] = BT_HID_CMD_SET_NAME;
        for (i, &byte) in name.iter().enumerate() {
            if i < 16 {
                name_cmd[i + 1] = byte;
            }
        }
        self.send_data(&name_cmd[0..name.len() + 1])?;
        
        // Start advertising
        self.start_advertising()?;
        
        Ok(())
    }
    
    pub fn start_advertising(&mut self) -> Result<(), ()> {
        let adv_cmd = [BT_HID_CMD_ADVERTISE];
        self.send_data(&adv_cmd)?;
        self.advertising = true;
        Ok(())
    }
    
    pub fn send_mouse_report(&mut self, report: &SteamMouseReport) -> Result<(), ()> {
        if !self.connected {
            return Ok(());
        }
        
        let cmd = [
            BT_HID_CMD_MOUSE_REPORT,
            report.buttons,
            report.x as u8,
            report.y as u8,
            report.wheel as u8
        ];
        
        self.send_data(&cmd)
    }
    
    pub fn send_keyboard_report(&mut self, report: &SteamKeyboardReport) -> Result<(), ()> {
        if !self.connected {
            return Ok(());
        }
        
        let mut cmd = [0u8; 9]; // 1 byte command + 2 bytes (modifier, reserved) + 6 bytes keycodes
        cmd[0] = BT_HID_CMD_KEYBOARD_REPORT;
        cmd[1] = report.modifier;
        cmd[2] = report.reserved;
        
        for i in 0..6 {
            cmd[3 + i] = report.keycodes[i];
        }
        
        self.send_data(&cmd)
    }
    
    pub fn process_controller_state(&mut self, state: &ControllerState) -> Result<(), ()> {
        // Create mouse and keyboard reports from controller state
        use crate::hal::usb_hid::{controller_to_mouse_report, controller_to_keyboard_report};
        
        let mouse_report = controller_to_mouse_report(state);
        let keyboard_report = controller_to_keyboard_report(state);
        
        // Send both reports
        self.send_mouse_report(&mouse_report)?;
        self.send_keyboard_report(&keyboard_report)?;
        
        Ok(())
    }

    pub fn send_data(&mut self, data: &[u8]) -> Result<(), ()> {
        self.uart.write_bytes(data)
    }

    pub fn read_data(&mut self, buffer: &mut [u8]) -> Result<usize, ()> {
        self.uart.read_bytes(buffer)
    }
    
    pub fn process_responses(&mut self) -> Result<(), ()> {
        // Check for incoming responses from nRF51822
        let mut resp_buffer = [0u8; 16]; // Buffer for responses
        
        match self.read_data(&mut resp_buffer) {
            Ok(bytes_read) if bytes_read > 0 => {
                match resp_buffer[0] {
                    BT_HID_RESP_CONNECTED => {
                        self.connected = true;
                        self.advertising = false;
                    },
                    BT_HID_RESP_DISCONNECTED => {
                        self.connected = false;
                        // Auto-restart advertising when disconnected
                        self.start_advertising()?;
                    },
                    BT_HID_RESP_ERROR => {
                        // Handle error response
                        // In a real implementation, you might want to log error details
                    },
                    _ => {
                        // Unknown response
                    }
                }
            },
            _ => {}
        }
        
        Ok(())
    }

    pub fn is_connected(&self) -> bool {
        self.connected
    }
    
    pub fn is_advertising(&self) -> bool {
        self.advertising
    }
}