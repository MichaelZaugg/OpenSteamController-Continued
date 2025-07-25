use core::ptr;

// Represents the LPC11XX System Control block structure from sysctl_11xx.h
#[repr(C)]
pub struct SysctlRegisters {
    pub sysmemremap: u32,
    pub presetctrl: u32,
    pub syspllctrl: u32,
    pub syspllstat: u32,
    pub usbpllctrl: u32,
    pub usbpllstat: u32,
    _reserved1: [u32; 2],
    pub sysoscctrl: u32,
    pub wdtoscctrl: u32,
    pub ircctrl: u32,
    pub lfoscctrl: u32,
    pub sysrststat: u32,
    _reserved2: [u32; 3],
    pub syspllclksel: u32,
    pub syspllclkuen: u32,
    pub usbpllclksel: u32,
    pub usbpllclkuen: u32,
    _reserved3: [u32; 8],
    pub mainclksel: u32,
    pub mainclkuen: u32,
    pub sysahbclkdiv: u32,
    _reserved4: u32,
    pub sysahbclkctrl: u32,
    _reserved5: [u32; 4],
    pub ssp0clkdiv: u32,
    pub usartclkdiv: u32,
    pub ssp1clkdiv: u32,
    _reserved6: [u32; 8],
    pub usbclksel: u32,
    pub usbclkuen: u32,
    pub usbclkdiv: u32,
    _reserved7: u32,
    pub wdtclksel: u32,
    pub wdtclkuen: u32,
    pub wdtclkdiv: u32,
    _reserved8: u32,
    pub clkoutsel: u32,
    pub clkoutuen: u32,
    pub clkoutdiv: u32,
    _reserved9: [u32; 5],
    pub pioporcap: [u32; 2],
    _reserved10: [u32; 18],
    pub bodctrl: u32,
    pub systckcal: u32,
    _reserved11: [u32; 6],
    pub irqlatency: u32,
    pub nmisrc: u32,
    pub pintsel: [u32; 8],
    pub pdruncfg: u32,
    _reserved12: [u32; 2],
    pub usbclkctrl: u32,
    pub usbclkst: u32,
    _reserved13: [u32; 24],
    pub startaprp0: u32,
    pub starterp0: u32,
    pub startrsrp0clr: u32,
    pub startsrp0: u32,
    _reserved14: u32,
    pub starterp1: u32,
    // Assuming this is the end of the common registers. You'll need to verify total size.
}

#[repr(u32)]
#[derive(Clone, Copy)]
pub enum PowerDownId {
    IrcOut       = (1 << 0),
    Irc          = (1 << 1),
    Flash        = (1 << 2),
    Bod          = (1 << 3),
    Adc          = (1 << 4),
    SysOsc       = (1 << 5),
    WdtOsc       = (1 << 6),
    SysPll       = (1 << 7),
    UsbPll       = (1 << 8),
    UsbPad       = (1 << 10),
    LfOsc        = (1 << 13),
    Dac          = (1 << 14),
    Ts           = (1 << 15),
    Acmp         = (1 << 16),
}

// Peripheral clock IDs for SYSCTL_SYSAHBCLKCTRL register.
// These correspond to the SYSCTL_CLOCK_* defines in sysctl_11xx.h.
#[repr(u32)]
#[derive(Clone, Copy)] // Needed for use in enums if you want to pass them by value
pub enum ClockId {
    Sys        = (1 << 0),  // SYS peripheral clock
    Rom        = (1 << 1),  // ROM peripheral clock
    Ram        = (1 << 2),  // RAM peripheral clock
    FlashReg   = (1 << 3),  // FLASHREG peripheral clock
    FlashArray = (1 << 4),  // FLASHARRAY peripheral clock
    I2c        = (1 << 5),  // I2C peripheral clock
    Gpio       = (1 << 6),  // GPIO peripheral clock
    Ct16b0     = (1 << 7),  // 16-bit counter/timer 0 clock
    Ct16b1     = (1 << 8),  // 16-bit counter/timer 1 clock
    Ct32b0     = (1 << 9),  // 32-bit counter/timer 0 clock
    Ct32b1     = (1 << 10), // 32-bit counter/timer 1 clock
    Ssp0       = (1 << 11), // SSP0 peripheral clock
    Usart      = (1 << 12), // USART peripheral clock
    Adc        = (1 << 13), // ADC peripheral clock
    Wdt        = (1 << 15), // Watchdog timer clock
    Iocon      = (1 << 16), // IOCON peripheral clock
    Can        = (1 << 17), // CAN peripheral clock (only on CHIP_LPC11CXX)
    Ssp1       = (1 << 18), // SSP1 peripheral clock
    UsbReg     = (1 << 19), // USB register clock (LPC11UXX only)
    UsbRam     = (1 << 20), // USB RAM clock (LPC11UXX only)
    Pmu        = (1 << 21), // PMU peripheral clock
    Dac        = (1 << 22), // DAC peripheral clock (LPC11AXX only)
    Acmp       = (1 << 23), // ACMP peripheral clock (LPC11AXX only)
}

/// Peripheral Reset IDs for PRESETCTRL register.
/// These correspond to the RESET_* defines in sysctl_11xx.h.
#[repr(u32)]
#[derive(Clone, Copy)]
pub enum ResetId {
    Ssp0   = (1 << 0), // SSP0 reset
    I2c    = (1 << 1), // I2C reset
    Usb    = (1 << 2), // USB reset (LPC11UXX only)
    // Bit 3 is reserved
    Gpio   = (1 << 4), // GPIO reset
    Ct16b0 = (1 << 5), // 16-bit counter/timer 0 reset
    Ct16b1 = (1 << 6), // 16-bit counter/timer 1 reset
    Ct32b0 = (1 << 7), // 32-bit counter/timer 0 reset
    Ct32b1 = (1 << 8), // 32-bit counter/timer 1 reset
    Adc    = (1 << 9), // ADC reset
    Wdt    = (1 << 10), // Watchdog timer reset
    Can    = (1 << 11), // CAN reset (only on CHIP_LPC11CXX)
    Usart  = (1 << 12), // USART reset
    Ssp1   = (1 << 18), // SSP1 reset
}