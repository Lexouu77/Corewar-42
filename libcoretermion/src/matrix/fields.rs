use super::{MAX, AXE};

use ::nalgebra;
use ::collect_slice::CollectSlice;
use ::libc;

use ::std::{io, mem, slice};
use ::std::fmt;

#[derive(Clone, Copy)]
pub struct Field(libc::c_uint);

pub fn new (
  p_fields: *const libc::c_int,
) -> Result<nalgebra::DMatrix<Field>, io::Error> {
  let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_fields, MAX)
  };
  let mut slice: [Field; MAX] = [Field::default(); MAX];

  raw.iter().map(|i: &libc::c_int| *i as libc::c_uint)
            .map(|u: libc::c_uint|
            Field(u)
          ).collect_slice_checked(&mut slice[..]);
  mem::forget(raw);
  Ok(nalgebra::DMatrix::from_row_vector(AXE, AXE, &slice))
}

impl fmt::Display for Field {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "{:02X}", self.0)
  }
}

impl Default for Field {
  fn default() -> Field {
    Field(0)
  }
}
