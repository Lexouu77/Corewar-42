#![crate_type = "staticlib"]

#[macro_use] extern crate itertools;
extern crate collect_slice;
extern crate termion;
extern crate nalgebra;
extern crate libc;

mod matrix;

use matrix::Matrix;

use std::ops::BitAnd;
use std::io::Write;
use std::io;

pub const FOREG_EMPTY: termion::color::Rgb = termion::color::Rgb(255, 255, 255);
pub const FOREG_PLAYER1: termion::color::Rgb = termion::color::Rgb(148, 0, 211);
pub const FOREG_PLAYER2: termion::color::Rgb = termion::color::Rgb(60, 179, 113);
pub const FOREG_PLAYER3: termion::color::Rgb = termion::color::Rgb(255, 0, 0);
pub const FOREG_PLAYER4: termion::color::Rgb = termion::color::Rgb(178, 34, 34);

#[no_mangle]
pub extern fn core_start (
) -> i32 {
  let mut stdout: io::Stdout = io::stdout();

  if write!(stdout, "{}", termion::clear::All).is_ok() {
    libc::EXIT_SUCCESS
  }
  else {
    libc::EXIT_FAILURE
  }
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
  let mut stdout: io::Stdout = io::stdout();

  if let Some(matrix) = Matrix::from_ffi(p_fields, p_colors, p_procs).ok() {
    if stdout.flush().is_ok().bitand(
      write!(stdout, "{}{}",
        termion::cursor::Goto(0, 5),
        matrix,
      ).is_ok()) {
      unsafe {
        libc::usleep(250);
      };
      libc::EXIT_SUCCESS
    }
    else { libc::EXIT_FAILURE }
  }
  else { libc::EXIT_FAILURE }
}
