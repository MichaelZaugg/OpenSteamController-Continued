use crate::chip::sysctl::{SysctlRegisters, ClockId}; // Need access to SYSCTL registers
use core::ptr;

// Base address for SYSCTL peripheral, confirmed from chip.h
const SYSCTL_BASE: usize = 0x40048000;

#[derive(Clone, Copy)]
pub enum ClockSource {
    IrcOsc = 0, // IRC Oscillator
    SysPll = 1, // System PLL
    WdtOsc = 2, // Watchdog Oscillator
    // Add other sources from clock_11xx.h (e.g., external clock)
    ExtOsc = 3, // External Oscillator
}

#[derive(Clone, Copy)]
pub enum PllClockSource {
    IrcOsc = 0, // IRC Oscillator
    SysOsc = 1, // System Oscillator
}

pub struct Clock;

impl Clock {
    pub fn new() -> Self {
        Clock {}
    }

    fn sysctl_registers_ptr() -> *mut SysctlRegisters {
        SYSCTL_BASE as *mut SysctlRegisters
    }

    /// Sets the source for the main system clock.
    /// Corresponds to `Chip_Clock_SetMainClockSource(source)`.
    pub fn set_main_clock_source(&mut self, source: ClockSource) {
        unsafe {
            let regs = Self::sysctl_registers_ptr();
            ptr::write_volatile(&mut (*regs).mainclksel, source as u32);
            // After changing clock source, the C code often has a small delay or loop
            // to ensure the clock has settled. This is done by writing to the CLKUEN
            // register and waiting for it to be stable.
            ptr::write_volatile(&mut (*regs).mainclkuen, 0); // Disable update
            ptr::write_volatile(&mut (*regs).mainclkuen, 1); // Enable update
            // Wait for clock to be stable (implementation might involve a loop checking
            // a status bit or just a short delay for simple cases).
            // The C code often does: while ((Chip_SYSCTL_ReadMainClockSource() & 0x01) == 0);
            // Which means reading mainclkuen until bit 0 is set (stable).
            while (ptr::read_volatile(&mut (*regs).mainclkuen) & 0x01) == 0 {}
        }
    }

    /// Sets up the System PLL.
    /// Corresponds to `Chip_Clock_SetupSystemPLL(ctrl)`.
    pub fn setup_system_pll(&mut self, msel: u32, psel: u32) {
        unsafe {
            let regs = Self::sysctl_registers_ptr();
            // The C macro SYSCTL_SYSPLL_SETUP(M, P) combines M and P.
            // SYSCTL_SYSPLL_SETUP(M, P) (((M) & 0x1F) | (((P) & 0x3) << 5))
            let ctrl_val = (msel & 0x1F) | ((psel & 0x3) << 5);
            ptr::write_volatile(&mut (*regs).syspllctrl, ctrl_val);
        }
    }

    /// Sets the source for the System PLL.
    /// Corresponds to `Chip_Clock_SetSystemPLLSource(source)`.
    pub fn set_system_pll_source(&mut self, source: PllClockSource) {
        unsafe {
            let regs = Self::sysctl_registers_ptr();
            ptr::write_volatile(&mut (*regs).syspllclksel, source as u32);
            ptr::write_volatile(&mut (*regs).syspllclkuen, 0); // Disable update
            ptr::write_volatile(&mut (*regs).syspllclkuen, 1); // Enable update
            while (ptr::read_volatile(&mut (*regs).syspllclkuen) & 0x01) == 0 {}
        }
    }

    /// Gets the current system clock rate.
    /// Corresponds to `Chip_Clock_GetSystemClockRate()`.
    /// This function in C usually calculates the clock based on current settings.
    /// For now, we'll return a fixed value, but for a complete translation,
    /// this needs to be dynamically calculated based on PLL and divider settings.
    pub fn get_system_clock_rate(&self) -> u32 {
        // This requires reading multiple SYSCTL registers (mainclksel, sysahbclkdiv, PLL settings)
        // and calculating the rate. For a simple start, you might return a known default
        // or the target clock frequency from your system configuration.
        // For example, if you aim for 48MHz:
        48_000_000 // Placeholder
    }

    // You would add other clock functions like:
    // - Chip_Clock_EnablePeriphClock (already in Sysctl, maybe make this more robust here?)
    // - Chip_Clock_SetAHBClockDiv
    // - Chip_Clock_GetIRCClockRate, Chip_Clock_GetSystemOscRate, etc.
}