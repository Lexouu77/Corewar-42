#![crate_type = "staticlib"]
#![feature(const_fn)]

#[macro_use] extern crate itertools;
extern crate collect_slice;
extern crate termion;
extern crate nalgebra;
extern crate libc;

mod matrix;
mod display;

use termion::raw::IntoRawMode;
use std::io::*;

#[no_mangle]
pub extern fn core_start (
) -> i32 {
  let stdout = stdout();
  let mut stdout = stdout.lock().into_raw_mode().unwrap();
  let stdin = stdin();
  let stdin = stdin.lock();

  libc::EXIT_SUCCESS
}

#[no_mangle]
pub extern fn core_end (
) -> i32 {
  libc::EXIT_SUCCESS
}

#[no_mangle]
pub extern fn core_idle (
  p_fields: *mut libc::c_int,
  p_colors: *mut libc::c_int,
  p_procs: *mut libc::c_int,
) -> i32 {
  let mut stdout = stdout();

  write!(stdout, "{}{}", termion::cursor::Goto(0, 5), termion::clear::All).unwrap();
 
  if display::new(p_fields, p_colors, p_procs).is_ok() {
    stdout.flush().unwrap();
    libc::EXIT_SUCCESS
  }
  else {
    libc::EXIT_FAILURE
  }
}
