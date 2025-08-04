use crate::hal::{system::firmware::PinError, with_peripherals};


pub fn init() -> Result<(), PinError>
{
    with_peripherals(|dp|
    {

        // Stage 1

        dp.SYSCON.pdruncfg.modify(|r, w| unsafe { 
            w.bits(r.bits() & !(1 << 5)) // Clear SYSOSC_PD bit
        });

        // Delay Oscillator Startup
        for _ in 0..0x1600 { cortex_m::asm::nop(); }

        dp.SYSCON.syspllclksel.write(|w| w.sel().system_oscillator());
        dp.SYSCON.syspllclkuen.write(|w| w.ena().no_change());
        dp.SYSCON.syspllclkuen.write(|w| w.ena().update_clock_source());

        dp.SYSCON.pdruncfg.modify(|r, w| unsafe { w.bits(r.bits() | (1 << 7)) });

        dp.SYSCON.syspllctrl.write(|w| unsafe { w.msel().bits(3).psel().bits(1) });

        dp.SYSCON.pdruncfg.modify(|r, w| unsafe { w.bits(r.bits() & !(1 << 7)) });

        while dp.SYSCON.syspllstat.read().lock().bit_is_clear() {}

        dp.SYSCON.sysahbclkdiv.write(|w| unsafe { w.div().bits(1) });

        dp.FLASHCTRL.flashcfg.write(|w| w.flashtim()._3_system_clocks_flas());

        dp.SYSCON.mainclksel.write(|w| w.sel().system_pll_clock_out());
        dp.SYSCON.mainclkuen.write(|w| w.ena().no_change());
        dp.SYSCON.mainclkuen.write(|w| w.ena().update_clock_source());


        dp.SYSCON.sysahbclkctrl.modify(|_, w|w.gpio().set_bit()
                                                                                    .adc().set_bit()
                                                                                    .i2c().set_bit()
                                                                                    .uart().set_bit()
                                                                                    .ssp0().set_bit()
                                                                                    .ssp1().set_bit()
                                                                                    .iocon().set_bit()
                                                                                );

        dp.GPIO0.dir.write(|w| unsafe { w.bits(0) });
        dp.GPIO1.dir.write(|w| unsafe { w.bits(0) });

        dp.GPIO0.data.write(|w| unsafe { w.bits(0x00000000) });
        dp.GPIO1.data.write(|w| unsafe { w.bits(0x00000000) });


        // Stage 2

        static mut PIO0_3_START_VAL: bool = false;
        static mut PIO0_2_START_VAL: bool = false;

        let usb_volt_detect = dp.GPIO0.data.read().bits() & (1 << 3) != 0;

        unsafe {PIO0_3_START_VAL = usb_volt_detect;}

        // Loop forever because we're not using battery power
        if !usb_volt_detect {loop {}}

        dp.GPIO1.data.modify(|r, w| unsafe { w.bits(r.bits() | (1 << 10)) });

        // Set PIO1_10 (~Battery Power Enable?) to output
        dp.GPIO1.dir.modify(|r, w| unsafe { w.bits(r.bits() | (1 << 10)) });

        // Set GPREG1 to 0
        dp.PMU.gpreg[1].write(|w| unsafe { w.bits(0) });

        // Enable pull down resistor on PIO0_3
        dp.IOCON.iocon_pio0_3.write(|w| w.mode().pull_down_resistor_e());

    })?;

    Ok(())
    
}