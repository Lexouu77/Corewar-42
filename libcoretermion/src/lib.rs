#![crate_type = "staticlib"]

#[macro_use] extern crate itertools;
extern crate collect_slice;
extern crate termion;
extern crate nalgebra;
extern crate libc;

mod matrix;
mod menu;

use matrix::Matrix;

use std::io::{self, Write, stdout};
use std::ops::BitAnd;
use std::env;

pub const FOREG_TITLE1: termion::color::Rgb = termion::color::Rgb(255, 0, 0);
pub const FOREG_TITLE2: termion::color::Rgb = termion::color::Rgb(0, 0, 0);
pub const FOREG_TITLE3: termion::color::Rgb = termion::color::Rgb(255, 0, 0);
pub const FOREG_TITLE4: termion::color::Rgb = termion::color::Rgb(153, 102, 51);

pub const FOREG_EMPTY: termion::color::Rgb = termion::color::Rgb(224, 255, 255);
pub const FOREG_PLAYER1: termion::color::Rgb = termion::color::Rgb(255, 215, 0);
pub const FOREG_PLAYER2: termion::color::Rgb = termion::color::Rgb(176, 196, 222);
pub const FOREG_PLAYER3: termion::color::Rgb = termion::color::Rgb(187, 130, 202);
pub const FOREG_PLAYER4: termion::color::Rgb = termion::color::Rgb(255, 222, 173);

pub const BACKG_EMPTY: termion::color::Rgb = termion::color::Rgb(224, 255, 255);
pub const BACKG_PLAYER1: termion::color::Rgb = termion::color::Rgb(255, 0, 222);
pub const BACKG_PLAYER2: termion::color::Rgb = termion::color::Rgb(176, 0, 0);
pub const BACKG_PLAYER3: termion::color::Rgb = termion::color::Rgb(0, 130, 202);
pub const BACKG_PLAYER4: termion::color::Rgb = termion::color::Rgb(0, 222, 0);
#[no_mangle]
pub extern fn core_start(
  p_nbr: libc::c_int,
) -> i32 {
  let mut stdout: io::Stdout = io::stdout();
  if write!(stdout, "{}",
    termion::clear::All,
  ).is_ok().bitand(
    write!(stdout, "{}{}{}{}",
      termion::cursor::Goto(1, 1),
      termion::color::Bg(::BACKG_EMPTY),
      termion::cursor::Goto(3, 3),
      env::args().next().unwrap_or_default()
                        .chars().skip(2)
                        .enumerate().map(|(i, c): (usize, _)|
                          format!("{}{}", match i {
                            c if c.checked_rem(1).unwrap_or_default()
                                  .checked_neg().is_none() => {
                              termion::color::Fg(::FOREG_TITLE1)
                            },
                            c if c.checked_rem(2).unwrap_or_default()
                                  .checked_neg().is_none() => {
                              termion::color::Fg(::FOREG_TITLE2)
                            },
                            c if c.checked_rem(3).unwrap_or_default()
                                  .checked_neg().is_none() => {
                              termion::color::Fg(::FOREG_TITLE3)
                            },
                            _ => termion::color::Fg(::FOREG_TITLE4),
                          }, c)
                        ).collect::<Vec<String>>()
                         .concat()
    ).is_ok()
  ) {
    menu::number_of_players(p_nbr).unwrap();
    libc::EXIT_SUCCESS
  }
  else {
    libc::EXIT_FAILURE
  }
}
/*
#[no_mangle]
pub extern fn core_start_playernames (
  p_name1: *mut libc::c_char,
  p_name2: *mut libc::c_char,
  p_name3: *mut libc::c_char,
  p_name4: *mut libc::c_char,
) -> i32 {
  let mut stdout: io::Stdout = io::stdout();

  if write!(stdout, "{}{}{}{}{}",
      termion::cursor::Goto(0, 5),
      CString::from_raw(p_name1),
      CString::from_raw(p_name2),
      CString::from_raw(p_name3),
      CString::from_raw(p_name4)
    ).is_ok() {
    libc::EXIT_SUCCESS
  }
  else { libc::EXIT_FAILURE }
}*/

#[no_mangle]
pub extern fn core_end (
) -> i32 {
    libc::EXIT_SUCCESS
}

#[no_mangle]
pub extern fn core_idle (
  (p_fields, p_colors, p_procs): (*const libc::c_int, *const libc::c_int, *const libc::c_int),
) -> i32 {
  let mut stdout: io::Stdout = io::stdout();

  if let Some(matrix) = Matrix::from_ffi(p_fields, p_colors, p_procs).ok() {
    if stdout.flush().is_ok().bitand(
      write!(stdout, "{}{}",
        termion::cursor::Goto(0, 5),
        matrix,
      ).is_ok()) {
      libc::EXIT_SUCCESS
    }
    else { libc::EXIT_FAILURE }
  }
  else { libc::EXIT_FAILURE }
}
