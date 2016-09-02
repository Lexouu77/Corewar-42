use super::{MAX, AXE};

use ::termion;
use ::nalgebra;
use ::nalgebra::Transpose;
use ::collect_slice::CollectSlice;
use ::libc;
use ::std::{fmt, io, mem, slice};

#[derive(Copy, Clone)]
pub enum Color {
  Player1,
  Player2,
  Player3,
  Player4,
  None,
}

impl fmt::Display for Color {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    match *self {
      Color::None => write!(f, "{}", termion::color::Fg(termion::color::Black)),
      Color::Player1 => write!(f, "{}", termion::color::Fg(termion::color::Red)),
      Color::Player2 => write!(f, "{}", termion::color::Fg(termion::color::Green)),
      Color::Player3 => write!(f, "{}", termion::color::Fg(termion::color::Blue)),
      Color::Player4 => write!(f, "{}", termion::color::Fg(termion::color::Yellow)),
    }
  }
}

pub fn new (
  p_colors: *mut libc::c_int,
) -> Result<nalgebra::DMatrix<Color>, io::Error> {
  let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_colors, MAX)
  };
  let mut slice: [Color; MAX] = [Color::None; MAX];

  raw.iter().map(|i: &libc::c_int|
            match *i {
              0 => Color::None,
              1 => Color::Player1,
              2 => Color::Player2,
              3 => Color::Player3,
              4 => Color::Player4,
              _ => unimplemented!(),
            }
          ).collect_slice_checked(&mut slice[..]);

  mem::forget(raw);
  let matrix = nalgebra::DMatrix::from_row_vector(AXE, AXE, &slice)
                                 .transpose();
  Ok(matrix)
}