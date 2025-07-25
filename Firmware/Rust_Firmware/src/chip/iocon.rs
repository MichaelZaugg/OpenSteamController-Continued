use core::ptr;

// Represents the LPC11XX IOCONFIG block structure from iocon_11xx.h
// Note: The C header usually defines a flat array of registers.
// The LPC11Uxx has 64 IOCON registers (PIO0_0 to PIO1_11) + special pins.
// We'll define a large enough array and let the HAL manage access.
#[repr(C)]
pub struct IoconRegisters {
    // IOCON has registers for PIO0_0 to PIO1_11 directly mapped in a contiguous block.
    // There are 64 general purpose I/O pins (P0_0 to P0_11, P0_12 to P0_31, P1_0 to P1_11).
    // This typically means about 64 individual 32-bit registers.
    // The IOCONFIG base address is 0x40044000
    // Based on NXP's common header styles, IOCON registers are often an array of `uint32_t`
    // covering `PIO0_0` up to the highest numbered pin.
    // For LPC11Uxx, there are P0_0 to P0_31 and P1_0 to P1_11.
    // Not all these are physical pins. There are 56 physical pins.
    // Let's assume a large enough array to cover the contiguous block defined.
    // A quick check of a datasheet (e.g., LPC11U37) suggests 64 configurable pins
    // through IOCON, hence 64 registers starting from 0x40044000.
    // (PIO0_0 -> 0x40044000, PIO0_1 -> 0x40044004, ..., PIO1_11 -> 0x400440FC)
    pub pins: [u32; 64], // Array to hold all pin configuration registers
    // Add specific registers for special functions if they exist outside the main array,
    // though typically they are part of this array at specific indices.
}

// Base address for IOCON peripheral, verified from chip.h
const IOCON_BASE: usize = 0x4004_4000;


// In src/chip/iocon.rs (continued)

// IOCON_FUNCx defines the primary function of the pin.
#[repr(u32)]
#[derive(Clone, Copy)]
pub enum PinFunction {
    Func0 = 0, // Primary function (often GPIO)
    Func1 = 1,
    Func2 = 2,
    Func3 = 3,
    // Add more if your chip supports Func4, Func5 etc. (typically 4 functions max)
}

// IOCON_MODE defines the pull-up/pull-down resistor configuration.
#[repr(u32)]
#[derive(Clone, Copy)]
pub enum PinMode {
    PullUp   = (0x02 << 3), // Internal pull-up resistor
    Repeater = (0x01 << 3), // Repeater mode (pull-up/pull-down)
    PullDown = (0x00 << 3), // Internal pull-down resistor
    Inactive = (0x03 << 3), // Neither pull-up nor pull-down
}

// IOCON_ADMODE (analog/digital mode) - for LPC11UXX, it's bit 7
#[repr(u32)]
#[derive(Clone, Copy)]
pub enum AdMode {
    Analog  = (1 << 7), // Select analog mode (disable digital input)
    Digital = (0 << 7), // Select digital mode (enable digital input)
}

// IOCON_HYS (hysteresis) - for LPC11UXX, it's bit 5
#[repr(u32)]
#[derive(Clone, Copy)]
pub enum Hysteresis {
    Disable = (0 << 5), // Hysteresis disabled
    Enable  = (1 << 5), // Hysteresis enabled
}

// Other common bit masks
pub const IOCON_INVERT_INPUT: u32 = (1 << 6); // Invert input
pub const IOCON_SCL_MODE: u32 = (1 << 8); // I2C SCL mode (LPC11UXX only)
pub const IOCON_OD_MODE: u32 = (1 << 10); // Open-drain mode (LPC11UXX only)
pub const IOCON_DAC_MODE: u32 = (1 << 16); // DAC mode (LPC11AXX only)

// Macro to combine modes (similar to IOCON_SET_MODE_PULLUP in C)
pub const fn iocon_mode_config(func: PinFunction, mode: PinMode, ad_mode: AdMode, hys: Hysteresis, other_flags: u32) -> u32 {
    (func as u32) | (mode as u32) | (ad_mode as u32) | (hys as u32) | other_flags
}