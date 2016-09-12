#![crate_type = "staticlib"]

#[macro_use] extern crate itertools;
extern crate collect_slice;
extern crate termion;
extern crate nalgebra;
extern crate libc;
extern crate openal;
extern crate vorbis;

mod matrix;
mod audio;

use std::io::{self, Write, stdout};
use std::ops::BitAnd;
use std::thread;

use matrix::Matrix;

pub const TOP: u16 = 10;
pub const TOP_U: usize = 10;

pub const TITLE_COLOR: termion::color::Rgb = termion::color::Rgb(0, 0, 0);
pub const TITLE_TEXT: &'static str = "\
\t  ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗  \n\
\t ██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗ \n\
\t ██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝ \n\
\t ██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗ \n\
\t ╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║ \n\
\t  ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝  By @ahamouda, @adjivas and @justasze. \n\
";

pub const FOREG_TITLE1: termion::color::Rgb = termion::color::Rgb(255, 0, 0);
pub const FOREG_TITLE2: termion::color::Rgb = termion::color::Rgb(0, 0, 0);
pub const FOREG_TITLE3: termion::color::Rgb = termion::color::Rgb(255, 0, 0);
pub const FOREG_TITLE4: termion::color::Rgb = termion::color::Rgb(153, 102, 51);

pub const FOREG_EMPTY: termion::color::Rgb = termion::color::Rgb(224, 255, 255);
pub const FOREG_PLAYER1: termion::color::Rgb = termion::color::Rgb(255, 215, 0);
pub const FOREG_PLAYER2: termion::color::Rgb = termion::color::Rgb(255, 255, 255);
pub const FOREG_PLAYER3: termion::color::Rgb = termion::color::Rgb(187, 130, 202);
pub const FOREG_PLAYER4: termion::color::Rgb = termion::color::Rgb(255, 222, 173);

pub const BACKG_EMPTY: termion::color::Rgb = termion::color::Rgb(224, 255, 255);
pub const BACKG_PLAYER1: termion::color::Rgb = termion::color::Rgb(255, 0, 222);
pub const BACKG_PLAYER2: termion::color::Rgb = termion::color::Rgb(0, 0, 0);
pub const BACKG_PLAYER3: termion::color::Rgb = termion::color::Rgb(0, 130, 202);
pub const BACKG_PLAYER4: termion::color::Rgb = termion::color::Rgb(0, 222, 0);

#[no_mangle]
pub extern fn core_init() -> i32 {
  if let Some((col, row)) = termion::terminal_size().ok() {
    if write!(io::stdout(), "{}{}",
      std::iter::repeat(
        format!("{} ",
          termion::color::Bg(::BACKG_EMPTY)
        )
      ).take({col * row} as usize)
       .collect::<String>(),
      termion::cursor::Goto(1, 1),
    ).is_ok() {
      libc::EXIT_SUCCESS
    }
    else {
      libc::EXIT_FAILURE
    }
  }
  else {
    libc::EXIT_FAILURE
  }
}

#[no_mangle]
pub extern fn core_start() -> i32 {
  if write!(io::stdout(), "{}{}{}{}{}{}{}",
            termion::cursor::Goto(3, 3),
            termion::color::Fg(TITLE_COLOR),
            TITLE_TEXT,
            termion::cursor::Goto(0, ::TOP),
            std::iter::repeat("≡").take(matrix::AXE_U * 2)
                                  .collect::<String>(),
            termion::cursor::Goto(0, {::TOP + matrix::AXE + 1}),
            std::iter::repeat("≡").take(matrix::AXE_U * 2)
                                  .collect::<String>(),
          ).is_ok() {
    thread::spawn(move || {
      audio::play("resources/Chiptune.ogg")
    });
    libc::EXIT_SUCCESS
  }
  else {
    libc::EXIT_FAILURE
  }
}

#[no_mangle]
pub extern fn core_end() -> i32 {
    libc::EXIT_SUCCESS
}

#[no_mangle]
pub extern fn core_idle(
  (p_fields, p_colors, p_procs): (*const libc::c_int, *const libc::c_int, *const libc::c_int),
) -> i32 {
  let mut stdout: io::Stdout = io::stdout();

  if let Some(matrix) = Matrix::from_ffi(p_fields, p_colors, p_procs).ok() {
    if stdout.flush().is_ok().bitand(
      write!(stdout, "{}{}",
        termion::cursor::Goto(0, ::TOP + 1),
        matrix,
      ).is_ok()) {
      libc::EXIT_SUCCESS
    }
    else { libc::EXIT_FAILURE }
  }
  else { libc::EXIT_FAILURE }
}
