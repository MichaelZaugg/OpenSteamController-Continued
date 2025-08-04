#![no_std]
#![no_main]

use cortex_m_rt::{entry};
use panic_halt as _;

use crate::hal::{system::firmware::*};
use lpc11xx;

mod hal;


#[entry]
fn main() -> ! {
    hal::init_peripherals().unwrap();
    hal::init::init().unwrap();
    
    
    let led_pin = Pin::new(0, 21).unwrap();

    const IOCON_PIO0_21: *mut u32 = 0x4004_4054 as *mut u32;
    
    unsafe {
        core::ptr::write_volatile(IOCON_PIO0_21, 0x80);
    }

    set_pin_mode(led_pin, PinMode::Output).unwrap();

    loop {
        gpio_digital_write(led_pin, PinValue::LOW).unwrap();
        for _ in 0..6000000 {
        cortex_m::asm::nop();    
        }
        gpio_digital_write(led_pin, PinValue::HIGH).unwrap();
        for _ in 0..6000000 {
        cortex_m::asm::nop();    
        }
        
    }
}