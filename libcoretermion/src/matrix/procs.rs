use super::{MAX, AXE};

use ::termion;
use ::nalgebra;
use ::collect_slice::CollectSlice;
use ::libc;
use ::std::{fmt, io, mem, slice};

#[derive(Copy, Clone)]
pub enum Proc {
  Player1,
  Player2,
  Player3,
  Player4,
  None,
}

impl fmt::Display for Proc {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    match *self {
      Proc::None => write!(f, "{}", termion::color::Fg(::BACKG_EMPTY)),
      Proc::Player1 => write!(f, "{}", termion::color::Fg(::BACKG_PLAYER1)),
      Proc::Player2 => write!(f, "{}", termion::color::Fg(::BACKG_PLAYER2)),
      Proc::Player3 => write!(f, "{}", termion::color::Fg(::BACKG_PLAYER3)),
      Proc::Player4 => write!(f, "{}", termion::color::Fg(::BACKG_PLAYER4)),
    }
  }
}

pub fn new (
  p_procs: *const libc::c_int,
) -> Result<nalgebra::DMatrix<Proc>, io::Error> {
  let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_procs, MAX)
  };
  let mut slice: [Proc; MAX] = [Proc::None; MAX];

  raw.iter().map(|i: &libc::c_int|
             match *i {
              0 => Proc::None,
              1 => Proc::Player1,
              2 => Proc::Player2,
              3 => Proc::Player3,
              4 => Proc::Player4,
              _ => unimplemented!(),
             }
           ).collect_slice_checked(&mut slice[..]);

  mem::forget(raw);
  Ok(nalgebra::DMatrix::from_row_vector(AXE, AXE, &slice))
}
