#![no_std]
#![no_main]

use cortex_m_rt::{entry};
use panic_halt as _;

use crate::hal::{peripherals::led, system::firmware::*};


mod hal;


#[entry]
fn main() -> ! {

    hal::init::init();

    let led_pin = Pin::new(1, 19).unwrap();

    set_pin_mode(Pin::new(1, 19).unwrap(), PinMode::Output).unwrap();

    gpio_digital_write(led_pin, PinValue::HIGH).unwrap();

    loop {
        cortex_m::asm::nop();
    }
}