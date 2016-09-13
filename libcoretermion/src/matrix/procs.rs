use super::{MAX_U, AXE_U};

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

impl Proc {
  pub fn new (
    p_procs: *const libc::c_int,
  ) -> Result<nalgebra::DMatrix<Proc>, io::Error> {
    let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_procs, MAX_U)
    };
    let mut slice: [Proc; MAX_U] = [Proc::None; MAX_U];

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
    Ok(nalgebra::DMatrix::from_row_vector(AXE_U, AXE_U, &slice))
  }
}

impl fmt::Display for Proc {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    match *self {
      Proc::None => Ok(()),
      Proc::Player1 => write!(f, "{}", termion::color::Bg(::BACKG_PLAYER1)),
      Proc::Player2 => write!(f, "{}", termion::color::Bg(::BACKG_PLAYER2)),
      Proc::Player3 => write!(f, "{}", termion::color::Bg(::BACKG_PLAYER3)),
      Proc::Player4 => write!(f, "{}", termion::color::Bg(::BACKG_PLAYER4)),
    }
  }
}