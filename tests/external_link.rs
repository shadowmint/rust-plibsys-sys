extern crate plibsys_sys;

use plibsys_sys::p_libsys_init;
use plibsys_sys::p_libsys_shutdown;

fn main() {
    unsafe {
        p_libsys_init();
        p_libsys_shutdown();
    }
}
