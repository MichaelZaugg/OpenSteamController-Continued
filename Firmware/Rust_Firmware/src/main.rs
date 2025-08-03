#![no_std]
#![no_main]

use lpc11xx;
use cortex_m_rt::{entry, exception, ExceptionFrame};
use panic_halt as _;


mod hal;


#[entry]
fn main() -> ! {

    let dp = lpc11xx::Peripherals::take().unwrap();

    hal::init::init();

    loop {

        dp.GPIO0.dir.modify(|r, w| unsafe { w.bits(r.bits() ^ (1 << 5)) });

        cortex_m::asm::nop();
    }
}