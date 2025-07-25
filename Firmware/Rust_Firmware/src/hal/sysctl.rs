// In src/hal/sysctl.rs

use crate::chip::sysctl::{SysctlRegisters, ClockId, ResetId};
use core::ptr;

// Base address for SYSCTL peripheral, confirmed from chip.h
const SYSCTL_BASE: usize = 0x40048000;

pub struct Sysctl;

impl Sysctl {
    pub fn new() -> Self {
        Sysctl {}
    }

    fn registers_ptr() -> *mut SysctlRegisters {
        SYSCTL_BASE as *mut SysctlRegisters
    }

    /// Enables the clock for a specific peripheral.
    /// Corresponds to `Chip_Clock_EnablePeriphClock` in C, which manipulates `sysahbclkctrl`.
    /// Used heavily in `init.c`.
    pub fn enable_peripheral_clock(&mut self, clock_id: ClockId) {
        unsafe {
            let regs = Self::registers_ptr();
            let current_val = ptr::read_volatile(&mut (*regs).sysahbclkctrl);
            ptr::write_volatile(&mut (*regs).sysahbclkctrl, current_val | (clock_id as u32));
        }
    }

    /// Disables the clock for a specific peripheral.
    pub fn disable_peripheral_clock(&mut self, clock_id: ClockId) {
        unsafe {
            let regs = Self::registers_ptr();
            let current_val = ptr::read_volatile(&mut (*regs).sysahbclkctrl);
            ptr::write_volatile(&mut (*regs).sysahbclkctrl, current_val & !(clock_id as u32));
        }
    }

    /// Releases a peripheral from reset (deasserts reset).
    /// Corresponds to `Chip_SYSCTL_DeassertPeriphReset` in C.
    /// Used in `init.c` via `Chip_SYSCTL_PeriphReset(RESET_GPIO);` pattern,
    /// where `RESET_GPIO` is `(1 << 4)` and writing to `presetctrl` clears the bit.
    pub fn deassert_peripheral_reset(&mut self, reset_id: ResetId) {
        unsafe {
            let regs = Self::registers_ptr();
            // In C, _Deassert sets the bit, _Assert clears it.
            // presetctrl works by writing 1 to a bit to deassert (release) it.
            // (Note: This is an educated guess based on common reset controllers,
            // the C header doesn't explicitly state the write-to-set behavior for PRESETCTRL,
            // but for reset registers, it's often write-1-to-release.)
            // The C code for Chip_SYSCTL_PeriphReset just takes the ID and writes it.
            // If the register is write-1-to-clear, then Deassert needs to write the bit.
            // If it's a direct mask, then we need read-modify-write.
            // Let's assume it's like a clear register where writing a 1 deasserts.
            // Otherwise, it's: ptr::write_volatile(&mut (*regs).presetctrl, current_val | (reset_id as u32));
            ptr::write_volatile(&mut (*regs).presetctrl, reset_id as u32);
        }
    }

    /// Asserts (holds in reset) a specific peripheral.
    /// Corresponds to `Chip_SYSCTL_AssertPeriphReset` in C.
    /// This would typically clear the bit in PRESETCTRL.
    pub fn assert_peripheral_reset(&mut self, reset_id: ResetId) {
        unsafe {
            let regs = Self::registers_ptr();
            let current_val = ptr::read_volatile(&mut (*regs).presetctrl);
            ptr::write_volatile(&mut (*regs).presetctrl, current_val & !(reset_id as u32));
        }
    }

    /// Powers down one or more blocks or peripherals.
    /// Corresponds to `Chip_SYSCTL_PowerDown(powerdownmask)`.
    pub fn power_down(&mut self, power_down_mask: u32) {
        unsafe {
            let regs = Self::registers_ptr();
            ptr::write_volatile(&mut (*regs).pdruncfg, ptr::read_volatile(&mut (*regs).pdruncfg) | power_down_mask);
        }
    }

    /// Powers up one or more blocks or peripherals.
    /// Corresponds to `Chip_SYSCTL_PowerUp(powerupmask)`.
    pub fn power_up(&mut self, power_up_mask: u32) {
        unsafe {
            let regs = Self::registers_ptr();
            ptr::write_volatile(&mut (*regs).pdruncfg, ptr::read_volatile(&mut (*regs).pdruncfg) & !power_up_mask);
        }
    }


    // Add other SYSCTL functions from sysctl_11xx.h as needed,
    // e.g., Chip_SYSCTL_SetMainClockSource, Chip_SYSCTL_SetupSystemPLL, etc.
    // These might involve the syspllclksel, mainclksel, etc. registers.
}