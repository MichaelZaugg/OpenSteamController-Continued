#![no_std]
#![no_main]

use cortex_m_rt::entry;
use panic_halt as _;
use nrf51::{Peripherals, interrupt};
use nrf51_hal::{gpio::{p0, Output, PushPull}, prelude::*};
use rubble::{
    gatt::{
        characteristic::{Characteristic, Properties},
        service::Service,
        GattServer,
    },
    hid::{
        HidDevice, HidCountry, HidReportType, HidCategory, HidProtocolMode, HidReport
    },
    l2cap::{BleChannelMap, L2CAPState},
    link::{
        ad_structure::{AdStructure, ServiceUuid},
        MIN_PDU_BUF,
    },
    security::NoSecurity,
    uuid::{Uuid16, Uuid},
    bytes::{ByteWriter, ToBytes},
};
use rubble_nrf5x::radio::{BleRadio, PacketBuffer};

// UART buffer size
const UART_BUF_SIZE: usize = 64;

// HID Report IDs
const HID_REPORT_ID_KEYBOARD: u8 = 0x01;
const HID_REPORT_ID_MOUSE: u8 = 0x02;
const HID_REPORT_ID_CONSUMER: u8 = 0x03;

// HID Report Sizes
const HID_REPORT_KEYBOARD_SIZE: usize = 8; // 1 byte report ID + 8 bytes data
const HID_REPORT_MOUSE_SIZE: usize = 5;    // 1 byte report ID + 4 bytes data
const HID_REPORT_CONSUMER_SIZE: usize = 3; // 1 byte report ID + 2 bytes data

// BLE Advertising Parameters
const BLE_ADVERTISING_INTERVAL_MS: u32 = 100;
const BLE_ADVERTISING_DURATION_MS: u32 = 0; // Advertise indefinitely

// Define the Bluetooth HID device name
const DEVICE_NAME: &str = "Steam Controller";

// HID Service UUIDs
const HID_SERVICE_UUID: Uuid16 = Uuid16(0x1812);
const HID_INFORMATION_UUID: Uuid16 = Uuid16(0x2A4A);
const HID_REPORT_MAP_UUID: Uuid16 = Uuid16(0x2A4B);
const HID_CONTROL_POINT_UUID: Uuid16 = Uuid16(0x2A4C);
const HID_REPORT_UUID: Uuid16 = Uuid16(0x2A4D);
const HID_PROTOCOL_MODE_UUID: Uuid16 = Uuid16(0x2A4E);

// HID Report Descriptor for a Mouse and Keyboard
static HID_REPORT_DESCRIPTOR: &[u8] = &[
    // Mouse descriptor
    0x05, 0x01,        // USAGE_PAGE (Generic Desktop)
    0x09, 0x02,        // USAGE (Mouse)
    0xA1, 0x01,        // COLLECTION (Application)
    0x09, 0x01,        //   USAGE (Pointer)
    0xA1, 0x00,        //   COLLECTION (Physical)
    0x85, 0x02,        //     REPORT_ID (2)
    0x05, 0x09,        //     USAGE_PAGE (Button)
    0x19, 0x01,        //     USAGE_MINIMUM (Button 1)
    0x29, 0x03,        //     USAGE_MAXIMUM (Button 3)
    0x15, 0x00,        //     LOGICAL_MINIMUM (0)
    0x25, 0x01,        //     LOGICAL_MAXIMUM (1)
    0x95, 0x03,        //     REPORT_COUNT (3)
    0x75, 0x01,        //     REPORT_SIZE (1)
    0x81, 0x02,        //     INPUT (Data,Var,Abs)
    0x95, 0x01,        //     REPORT_COUNT (1)
    0x75, 0x05,        //     REPORT_SIZE (5)
    0x81, 0x03,        //     INPUT (Cnst,Var,Abs)
    0x05, 0x01,        //     USAGE_PAGE (Generic Desktop)
    0x09, 0x30,        //     USAGE (X)
    0x09, 0x31,        //     USAGE (Y)
    0x09, 0x38,        //     USAGE (Wheel)
    0x15, 0x81,        //     LOGICAL_MINIMUM (-127)
    0x25, 0x7F,        //     LOGICAL_MAXIMUM (127)
    0x75, 0x08,        //     REPORT_SIZE (8)
    0x95, 0x03,        //     REPORT_COUNT (3)
    0x81, 0x06,        //     INPUT (Data,Var,Rel)
    0xC0,              //   END_COLLECTION
    0xC0,              // END_COLLECTION

    // Keyboard descriptor
    0x05, 0x01,        // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,        // USAGE (Keyboard)
    0xA1, 0x01,        // COLLECTION (Application)
    0x85, 0x01,        //   REPORT_ID (1)
    0x05, 0x07,        //   USAGE_PAGE (Keyboard)
    0x19, 0xE0,        //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xE7,        //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,        //   LOGICAL_MINIMUM (0)
    0x25, 0x01,        //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,        //   REPORT_SIZE (1)
    0x95, 0x08,        //   REPORT_COUNT (8)
    0x81, 0x02,        //   INPUT (Data,Var,Abs)
    0x95, 0x01,        //   REPORT_COUNT (1)
    0x75, 0x08,        //   REPORT_SIZE (8)
    0x81, 0x03,        //   INPUT (Cnst,Var,Abs)
    0x95, 0x06,        //   REPORT_COUNT (6)
    0x75, 0x08,        //   REPORT_SIZE (8)
    0x15, 0x00,        //   LOGICAL_MINIMUM (0)
    0x25, 0x65,        //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,        //   USAGE_PAGE (Keyboard)
    0x19, 0x00,        //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,        //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,        //   INPUT (Data,Ary,Abs)
    0xC0,              // END_COLLECTION
    
    // Consumer control descriptor
    0x05, 0x0C,        // USAGE_PAGE (Consumer Devices)
    0x09, 0x01,        // USAGE (Consumer Control)
    0xA1, 0x01,        // COLLECTION (Application)
    0x85, 0x03,        //   REPORT_ID (3)
    0x15, 0x00,        //   LOGICAL_MINIMUM (0)
    0x25, 0x01,        //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,        //   REPORT_SIZE (1)
    0x95, 0x10,        //   REPORT_COUNT (16)
    0x09, 0xB5,        //   USAGE (Scan Next Track)
    0x09, 0xB6,        //   USAGE (Scan Previous Track)
    0x09, 0xB7,        //   USAGE (Stop)
    0x09, 0xB8,        //   USAGE (Eject)
    0x09, 0xCD,        //   USAGE (Play/Pause)
    0x09, 0xE2,        //   USAGE (Mute)
    0x09, 0xE9,        //   USAGE (Volume Increment)
    0x09, 0xEA,        //   USAGE (Volume Decrement)
    0x0A, 0x83, 0x01,  //   USAGE (AL Consumer Control Config)
    0x0A, 0x8A, 0x01,  //   USAGE (AL Email Reader)
    0x0A, 0x92, 0x01,  //   USAGE (AL Calculator)
    0x0A, 0x94, 0x01,  //   USAGE (AL Local Browser)
    0x0A, 0x21, 0x02,  //   USAGE (AC Search)
    0x0A, 0x23, 0x02,  //   USAGE (AC Home)
    0x0A, 0x24, 0x02,  //   USAGE (AC Back)
    0x0A, 0x25, 0x02,  //   USAGE (AC Forward)
    0x81, 0x02,        //   INPUT (Data,Var,Abs)
    0xC0               // END_COLLECTION
];

// UART Commands from the LPC11U37F
const CMD_HID_MOUSE_REPORT: u8 = 0x10;
const CMD_HID_KEYBOARD_REPORT: u8 = 0x11;
const CMD_HID_CONSUMER_REPORT: u8 = 0x12;

// UART Response Codes to the LPC11U37F
const RESP_SUCCESS: u8 = 0x00;
const RESP_ERROR: u8 = 0xFF;
const RESP_CONNECTED: u8 = 0x01;
const RESP_DISCONNECTED: u8 = 0x02;

// Global variables
static mut UART_RX_BUFFER: [u8; UART_BUF_SIZE] = [0; UART_BUF_SIZE];
static mut UART_RX_IDX: usize = 0;

// Reports
static mut MOUSE_REPORT: [u8; HID_REPORT_MOUSE_SIZE] = [HID_REPORT_ID_MOUSE, 0, 0, 0, 0];
static mut KEYBOARD_REPORT: [u8; HID_REPORT_KEYBOARD_SIZE] = [HID_REPORT_ID_KEYBOARD, 0, 0, 0, 0, 0, 0, 0];
static mut CONSUMER_REPORT: [u8; HID_REPORT_CONSUMER_SIZE] = [HID_REPORT_ID_CONSUMER, 0, 0];

#[entry]
fn main() -> ! {
    let p = Peripherals::take().unwrap();
    
    // Configure UART for communication with the LPC11U37F
    configure_uart(&p);
    
    // Configure BLE radio
    let mut radio = setup_ble_radio(&p);
    
    // Configure GPIO
    let pins = p0::Parts::new(p.GPIO);
    let mut led = pins.p0_21.into_push_pull_output(nrf51_hal::gpio::Level::Low);
    
    // Initialize HID GATT service
    let mut gatt_server = setup_hid_service();
    
    // Start advertising
    start_advertising(&mut radio, &gatt_server);
    
    let mut connected = false;
    
    loop {
        // Process any received UART data
        let cmd = process_uart();
        
        match cmd {
            Some(CMD_HID_MOUSE_REPORT) => {
                // Process mouse report received from LPC11U37F
                if connected {
                    send_hid_report(&mut radio, &gatt_server, HID_REPORT_ID_MOUSE);
                }
                // Send acknowledgement
                send_uart_response(RESP_SUCCESS);
            },
            Some(CMD_HID_KEYBOARD_REPORT) => {
                // Process keyboard report received from LPC11U37F
                if connected {
                    send_hid_report(&mut radio, &gatt_server, HID_REPORT_ID_KEYBOARD);
                }
                // Send acknowledgement
                send_uart_response(RESP_SUCCESS);
            },
            Some(CMD_HID_CONSUMER_REPORT) => {
                // Process consumer control report received from LPC11U37F
                if connected {
                    send_hid_report(&mut radio, &gatt_server, HID_REPORT_ID_CONSUMER);
                }
                // Send acknowledgement
                send_uart_response(RESP_SUCCESS);
            },
            Some(_) => {
                // Unknown command
                send_uart_response(RESP_ERROR);
            },
            None => {
                // No command to process
            }
        }
        
        // Process any BLE events
        match process_ble_events(&mut radio, &mut gatt_server) {
            BleEvent::Connected => {
                connected = true;
                led.set_high().ok();
                send_uart_response(RESP_CONNECTED);
            },
            BleEvent::Disconnected => {
                connected = false;
                led.set_low().ok();
                send_uart_response(RESP_DISCONNECTED);
                
                // Restart advertising when disconnected
                start_advertising(&mut radio, &gatt_server);
            },
            BleEvent::None => {},
        }
    }
}

fn configure_uart(p: &Peripherals) {
    // Configure UART pins
    let pins = p0::Parts::new(p.GPIO);
    
    // TODO: Configure the actual UART pins according to the nRF51822 pinout
    // This will depend on the specific pins used in the Steam Controller
    
    // Configure UART peripheral
    p.UART0.baudrate.write(|w| w.baudrate().baud115200());
    p.UART0.enable.write(|w| w.enable().enabled());
    
    // Enable UART interrupts
    p.UART0.intenset.write(|w| w.rxdrdy().set_bit());
    
    unsafe {
        // Enable the UART interrupt in the NVIC
        cortex_m::peripheral::NVIC::unmask(nrf51::Interrupt::UART0);
    }
}

fn setup_ble_radio(p: &Peripherals) -> BleRadio {
    // Initialize the BLE radio
    let mut radio = unsafe { BleRadio::new(p.RADIO, p.TIMER0) };
    
    // Configure radio parameters
    // TODO: Set appropriate radio parameters for the Steam Controller
    
    radio
}

fn setup_hid_service() -> GattServer<NoSecurity> {
    let mut services = Vec::new();
    
    // Create HID Service
    let mut hid_service = Service::new(HID_SERVICE_UUID);
    
    // HID Report Map Characteristic
    let report_map_char = Characteristic::new(
        HID_REPORT_MAP_UUID,
        Properties::READ,
        HID_REPORT_DESCRIPTOR.to_vec(),
        None,
    );
    hid_service.add_characteristic(report_map_char);
    
    // HID Information Characteristic (version 1.1, country code = 0, not normally connectable)
    let hid_info_data = [0x01, 0x01, 0x00, 0x00];
    let hid_info_char = Characteristic::new(
        HID_INFORMATION_UUID,
        Properties::READ,
        hid_info_data.to_vec(),
        None,
    );
    hid_service.add_characteristic(hid_info_char);
    
    // HID Protocol Mode Characteristic (default = report mode)
    let protocol_mode_data = [0x01]; // Report mode
    let protocol_mode_char = Characteristic::new(
        HID_PROTOCOL_MODE_UUID,
        Properties::READ | Properties::WRITE_WITHOUT_RESPONSE,
        protocol_mode_data.to_vec(),
        None,
    );
    hid_service.add_characteristic(protocol_mode_char);
    
    // HID Control Point Characteristic
    let control_point_data = [0x00]; // No suspend
    let control_point_char = Characteristic::new(
        HID_CONTROL_POINT_UUID,
        Properties::WRITE_WITHOUT_RESPONSE,
        control_point_data.to_vec(),
        None,
    );
    hid_service.add_characteristic(control_point_char);
    
    // HID Report Characteristic for Mouse
    let mouse_report_ref_data = [HID_REPORT_ID_MOUSE, 0x01]; // Input report
    let mouse_report_char = Characteristic::new(
        HID_REPORT_UUID,
        Properties::READ | Properties::NOTIFY,
        [0, 0, 0, 0].to_vec(), // Initial report data
        Some(mouse_report_ref_data.to_vec()),
    );
    hid_service.add_characteristic(mouse_report_char);
    
    // HID Report Characteristic for Keyboard
    let keyboard_report_ref_data = [HID_REPORT_ID_KEYBOARD, 0x01]; // Input report
    let keyboard_report_char = Characteristic::new(
        HID_REPORT_UUID,
        Properties::READ | Properties::NOTIFY,
        [0, 0, 0, 0, 0, 0, 0, 0].to_vec(), // Initial report data
        Some(keyboard_report_ref_data.to_vec()),
    );
    hid_service.add_characteristic(keyboard_report_char);
    
    // HID Report Characteristic for Consumer Control
    let consumer_report_ref_data = [HID_REPORT_ID_CONSUMER, 0x01]; // Input report
    let consumer_report_char = Characteristic::new(
        HID_REPORT_UUID,
        Properties::READ | Properties::NOTIFY,
        [0, 0, 0].to_vec(), // Initial report data
        Some(consumer_report_ref_data.to_vec()),
    );
    hid_service.add_characteristic(consumer_report_char);
    
    services.push(hid_service);
    
    // Create GATT server
    GattServer::new(services)
}

fn start_advertising(radio: &mut BleRadio, gatt_server: &GattServer<NoSecurity>) {
    // Create advertising data
    let mut adv_data = [0u8; 31];
    let mut adv_writer = ByteWriter::new(&mut adv_data);
    
    // Add flags
    AdStructure::Flags(rubble::link::ad_structure::Flags::LE_GENERAL_DISCOVERABLE | rubble::link::ad_structure::Flags::BR_EDR_NOT_SUPPORTED)
        .write(&mut adv_writer)
        .unwrap();
    
    // Add service UUID
    AdStructure::ServiceUuids16(ServiceUuid::Complete(&[HID_SERVICE_UUID]))
        .write(&mut adv_writer)
        .unwrap();
    
    // Add device name
    AdStructure::CompleteLocalName(DEVICE_NAME)
        .write(&mut adv_writer)
        .unwrap();
    
    // Start advertising
    radio.start_advertise(
        rubble::link::advertising::ConnectableAdvertisement::ScannableUndirected {
            adv_data: adv_writer.into_vec(),
        },
        BLE_ADVERTISING_INTERVAL_MS,
        BLE_ADVERTISING_DURATION_MS,
    );
}

enum BleEvent {
    Connected,
    Disconnected,
    None,
}

fn process_ble_events(radio: &mut BleRadio, gatt_server: &mut GattServer<NoSecurity>) -> BleEvent {
    match radio.poll() {
        Some(evt) => match evt {
            rubble::link::RadioEvent::LinkEvent(evt) => match evt {
                rubble::link::LinkEvent::Connected(conn) => {
                    // Handle connection
                    BleEvent::Connected
                },
                rubble::link::LinkEvent::Disconnected => {
                    // Handle disconnection
                    BleEvent::Disconnected
                },
                _ => BleEvent::None,
            },
            _ => BleEvent::None,
        },
        None => BleEvent::None,
    }
}

fn send_hid_report(radio: &mut BleRadio, gatt_server: &GattServer<NoSecurity>, report_id: u8) {
    // Get the appropriate report data based on report ID
    let report_data = match report_id {
        HID_REPORT_ID_MOUSE => unsafe { &MOUSE_REPORT },
        HID_REPORT_ID_KEYBOARD => unsafe { &KEYBOARD_REPORT },
        HID_REPORT_ID_CONSUMER => unsafe { &CONSUMER_REPORT },
        _ => return,
    };
    
    // Send the HID report via BLE
    // TODO: Implement actual report sending via BLE GATT notification
}

fn process_uart() -> Option<u8> {
    // Process any received UART data
    // Return a command if one is found
    unsafe {
        if UART_RX_IDX > 0 {
            let cmd = UART_RX_BUFFER[0];
            
            // Process command based on type
            match cmd {
                CMD_HID_MOUSE_REPORT => {
                    // Copy mouse report data
                    if UART_RX_IDX >= 5 {
                        MOUSE_REPORT[0] = HID_REPORT_ID_MOUSE;
                        MOUSE_REPORT[1] = UART_RX_BUFFER[1]; // buttons
                        MOUSE_REPORT[2] = UART_RX_BUFFER[2]; // x
                        MOUSE_REPORT[3] = UART_RX_BUFFER[3]; // y
                        MOUSE_REPORT[4] = UART_RX_BUFFER[4]; // wheel
                        
                        // Reset buffer
                        UART_RX_IDX = 0;
                        return Some(CMD_HID_MOUSE_REPORT);
                    }
                },
                CMD_HID_KEYBOARD_REPORT => {
                    // Copy keyboard report data
                    if UART_RX_IDX >= 9 {
                        KEYBOARD_REPORT[0] = HID_REPORT_ID_KEYBOARD;
                        KEYBOARD_REPORT[1] = UART_RX_BUFFER[1]; // modifier
                        KEYBOARD_REPORT[2] = UART_RX_BUFFER[2]; // reserved
                        
                        // Copy 6 keycodes
                        for i in 0..6 {
                            KEYBOARD_REPORT[3 + i] = UART_RX_BUFFER[3 + i];
                        }
                        
                        // Reset buffer
                        UART_RX_IDX = 0;
                        return Some(CMD_HID_KEYBOARD_REPORT);
                    }
                },
                CMD_HID_CONSUMER_REPORT => {
                    // Copy consumer report data
                    if UART_RX_IDX >= 3 {
                        CONSUMER_REPORT[0] = HID_REPORT_ID_CONSUMER;
                        CONSUMER_REPORT[1] = UART_RX_BUFFER[1]; // LSB
                        CONSUMER_REPORT[2] = UART_RX_BUFFER[2]; // MSB
                        
                        // Reset buffer
                        UART_RX_IDX = 0;
                        return Some(CMD_HID_CONSUMER_REPORT);
                    }
                },
                _ => {
                    // Unknown command
                    UART_RX_IDX = 0;
                    return Some(0xFF);
                }
            }
        }
    }
    
    None
}

fn send_uart_response(response: u8) {
    // Send response to LPC11U37F
    unsafe {
        // Wait until UART is ready to transmit
        while !p.UART0.events_txdrdy.read().bits() & 1 != 0 {}
        
        // Send response byte
        p.UART0.txd.write(|w| w.txd().bits(response));
        
        // Clear the event
        p.UART0.events_txdrdy.reset();
    }
}

#[interrupt]
fn UART0() {
    static mut P: Option<nrf51::Peripherals> = None;
    
    let p = P.get_or_insert_with(|| unsafe { nrf51::Peripherals::steal() });
    
    // Check if data received
    if p.UART0.events_rxdrdy.read().bits() & 1 != 0 {
        // Read data
        let data = p.UART0.rxd.read().bits() as u8;
        
        unsafe {
            // Store data in buffer if there's space
            if UART_RX_IDX < UART_BUF_SIZE {
                UART_RX_BUFFER[UART_RX_IDX] = data;
                UART_RX_IDX += 1;
            }
        }
        
        // Clear the event
        p.UART0.events_rxdrdy.reset();
    }
}
