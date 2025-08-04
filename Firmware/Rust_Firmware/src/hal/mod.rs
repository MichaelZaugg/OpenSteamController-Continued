use core::cell::RefCell;

use cortex_m::interrupt::{self, Mutex};

use crate::hal::system::firmware::PinError;

pub mod peripherals;
pub mod system;
pub mod usb;

pub mod controller;
pub mod error;
pub mod init;

static PERIPHERALS: Mutex<RefCell<Option<lpc11xx::Peripherals>>> = Mutex::new(RefCell::new(None));




pub fn init_peripherals() -> Result<(), PinError>
{
    let dp = lpc11xx::Peripherals::take().ok_or(PinError::PeripheralsTaken)?; 
    interrupt::free(|cs| PERIPHERALS.borrow(cs).replace(Some(dp)));
    Ok(())
}



pub fn with_peripherals<F, R>(f: F) -> Result<R, PinError>
where
    F: FnOnce(&lpc11xx::Peripherals) -> R
{
    interrupt::free(|cs| 
    {
        let peripherals_ref = PERIPHERALS.borrow(cs);
        let peripherals = peripherals_ref.borrow();
        let dp = peripherals.as_ref().ok_or(PinError::PeripheralsTaken)?;
        Ok(f(dp))
    })
}