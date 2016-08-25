use super::{MAX, AXE};

use ::nalgebra;
use ::nalgebra::Transpose;
use ::collect_slice::CollectSlice;
use ::libc;
use ::std::{fmt, io, mem, slice};

#[derive(Copy, Clone)]
pub enum Proc {
  Is,
  None,
}

impl fmt::Display for Proc {
  fn fmt(&self, _: &mut fmt::Formatter) -> fmt::Result {
    Ok(())
  }
}

pub fn new (
  p_procs: *mut libc::c_int,
) -> Result<nalgebra::DMatrix<Proc>, io::Error> {
  let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_procs, MAX)
  };
  let mut slice: [Proc; MAX] = [Proc::None; MAX];

  raw.iter().map(|i: &libc::c_int|
             match *i {
               0 | 1 | 2 | 3 | 4 => Proc::None,
               n => {
                   println!("{}", n);
                 unimplemented!();
               },
             }
           ).collect_slice_checked(&mut slice[..]);

  mem::forget(raw);
  let matrix = nalgebra::DMatrix::from_row_vector(AXE, AXE, &slice)
                                 .transpose();
  Ok(matrix)
}
