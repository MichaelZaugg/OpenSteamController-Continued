use lpc11xx;


pub fn init()
{
    let dp = lpc11xx::Peripherals::take().unwrap();

    dp.SYSCON.sysahbclkctrl.modify(|_, w|   w.gpio().set_bit()
                                                                                    .adc().set_bit()
                                                                                    .i2c().set_bit()
                                                                                    .uart().set_bit()
                                                                                    .ssp0().set_bit()
                                                                                    .ssp1().set_bit()
                                                                                    .iocon().set_bit()
                                                                                );
}