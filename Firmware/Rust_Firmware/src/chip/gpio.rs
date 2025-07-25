// In src/hal/gpio.rs


use core::ptr;  // We explicitly need this now for volatile access
use crate::chip::registers::GpioRegisters;

// Define the base address for the GPIO peripheral. This value is usually
// found in a central chip header (like chip.h or a linker script).
// You'll need to confirm this from your chip's datasheet or the C project's main chip setup.
const GPIO_BASE: usize = 0x5000_0000;

pub struct Gpio;

impl Gpio {
    /// Creates a new GPIO instance. This effectively provides access to the GPIO registers.
    /// It ensures only one instance can access the hardware registers at a time (software singleton).
    pub fn new() -> Self {
        Gpio {}
    }

    // A low-level, unsafe way to get a raw mutable pointer to the register block.
    // This is where the single `unsafe` entry point for register access begins.
    fn registers_ptr() -> *mut GpioRegisters {
        GPIO_BASE as *mut GpioRegisters
    }

    /// Initializes the GPIO block.
    pub fn init(&mut self) {
        // As before, this is a placeholder. Translate specific C init logic here.
    }

    /// De-initializes the GPIO block.
    pub fn deinit(&mut self) {
        // Placeholder for de-initialization.
    }

    /// Sets the state of a specific GPIO pin.
    /// Corresponds to Chip_GPIO_SetPinState(pGPIO, port, pin, setting).
    pub fn set_pin_state(&mut self, port: u8, pin: u8, setting: bool) {
        // All raw pointer dereferences and volatile accesses *must* be in an unsafe block.
        unsafe {
            let regs = Self::registers_ptr();
            // Accessing the 'b' (Byte) register array
            // C: pGPIO->B[port][pin] = setting;
            // Here, we're writing a u8 value (0 or 1) to a specific byte address.
            ptr::write_volatile(
                &mut (*regs).b[port as usize][pin as usize],
                setting as u8,
            );
        }
    }

    /// Reads the state of a specific GPIO pin.
    /// Corresponds to Chip_GPIO_GetPinState(pGPIO, port, pin).
    pub fn get_pin_state(&self, port: u8, pin: u8) -> bool {
        unsafe {
            let regs = Self::registers_ptr();
            // C: return (bool) pGPIO->B[port][pin];
            ptr::read_volatile(&(*regs).b[port as usize][pin as usize]) != 0
        }
    }

    /// Sets the direction of a specific GPIO pin to output.
    /// Corresponds to Chip_GPIO_SetPinDIROutput(pGPIO, port, pin).
    pub fn set_pin_dir_output(&mut self, port: u8, pin: u8) {
        unsafe {
            let regs = Self::registers_ptr();
            let dir_ptr = &mut (*regs).dir[port as usize];
            // C: pGPIO->DIR[port] |= 1UL << pin;
            // We need to read, modify, then write back volatilely.
            let current_val = ptr::read_volatile(dir_ptr);
            ptr::write_volatile(dir_ptr, current_val | (1 << pin));
        }
    }

    /// Sets the direction of a specific GPIO pin to input.
    /// Corresponds to Chip_GPIO_SetPinDIRInput(pGPIO, port, pin).
    pub fn set_pin_dir_input(&mut self, port: u8, pin: u8) {
        unsafe {
            let regs = Self::registers_ptr();
            let dir_ptr = &mut (*regs).dir[port as usize];
            // C: pGPIO->DIR[port] &= ~(1UL << pin);
            let current_val = ptr::read_volatile(dir_ptr);
            ptr::write_volatile(dir_ptr, current_val & !(1 << pin));
        }
    }

    /// Gets the direction of a specific GPIO pin.
    /// Corresponds to Chip_GPIO_GetPinDIR(pGPIO, port, pin).
    pub fn get_pin_dir(&self, port: u8, pin: u8) -> bool {
        unsafe {
            let regs = Self::registers_ptr();
            // C: (bool) (((pGPIO->DIR[port]) >> pin) & 1);
            ((ptr::read_volatile(&(*regs).dir[port as usize]) >> pin) & 1) != 0
        }
    }

    /// Sets selected GPIO output pins to the high state.
    /// Corresponds to Chip_GPIO_SetPortOutHigh(pGPIO, port, pins).
    pub fn set_port_out_high(&mut self, port: u8, pins: u32) {
        unsafe {
            let regs = Self::registers_ptr();
            // C: pGPIO->SET[port] = pins;
            ptr::write_volatile(&mut (*regs).set[port as usize], pins);
        }
    }

    /// Sets an individual GPIO output pin to the high state.
    /// Corresponds to Chip_GPIO_SetPinOutHigh(pGPIO, port, pin).
    pub fn set_pin_out_high(&mut self, port: u8, pin: u8) {
        self.set_port_out_high(port, 1 << pin);
    }

    /// Sets selected GPIO output pins to the low state.
    /// Corresponds to Chip_GPIO_SetPortOutLow(pGPIO, port, pins).
    pub fn set_port_out_low(&mut self, port: u8, pins: u32) {
        unsafe {
            let regs = Self::registers_ptr();
            // C: pGPIO->CLR[port] = pins;
            ptr::write_volatile(&mut (*regs).clr[port as usize], pins);
        }
    }

    /// Sets an individual GPIO output pin to the low state.
    /// Corresponds to Chip_GPIO_SetPinOutLow(pGPIO, port, pin).
    pub fn set_pin_out_low(&mut self, port: u8, pin: u8) {
        self.set_port_out_low(port, 1 << pin);
    }

    /// Toggles selected GPIO output pins to the opposite state.
    /// Corresponds to Chip_GPIO_SetPortToggle(pGPIO, port, pins).
    pub fn set_port_toggle(&mut self, port: u8, pins: u32) {
        unsafe {
            let regs = Self::registers_ptr();
            // C: pGPIO->NOT[port] = pins;
            ptr::write_volatile(&mut (*regs).not[port as usize], pins);
        }
    }

    /// Toggles an individual GPIO output pin to the opposite state.
    /// Corresponds to Chip_GPIO_SetPinToggle(pGPIO, port, pin).
    pub fn set_pin_toggle(&mut self, port: u8, pin: u8) {
        self.set_port_toggle(port, 1 << pin);
    }

    /// Reads current bit states for the selected port.
    /// Corresponds to Chip_GPIO_ReadValue(pGPIO, portNum).
    pub fn read_port_value(&self, port: u8) -> u32 {
        unsafe {
            let regs = Self::registers_ptr();
            // C: return pGPIO->PIN[portNum];
            ptr::read_volatile(&(*regs).pin[port as usize])
        }
    }

    // Continue translating other functions like Chip_GPIO_SetPortMask, Chip_GPIO_GetPortMask, etc.
    // They will follow the same pattern of unsafe blocks and ptr::read_volatile/write_volatile.
}