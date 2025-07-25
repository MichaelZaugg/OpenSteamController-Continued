#![no_std]
#![no_main]


use cortex_m_rt::{entry, exception, ExceptionFrame};
use panic_halt as _;


mod hal;
mod chip;


#[entry]
fn main() -> ! {
    loop {
        cortex_m::asm::nop();
    }
}