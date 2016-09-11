use super::{MAX_U, AXE_U};

use ::nalgebra;
use ::collect_slice::CollectSlice;
use ::libc;

use ::std::{io, mem, slice, char};
use ::std::fmt;

#[derive(Clone, Copy)]
pub struct Field(Option<char>);

impl Field {
  pub fn new (
    p_fields: *const libc::c_int,
  ) -> Result<nalgebra::DMatrix<Field>, io::Error> {
    let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_fields, MAX_U)
    };
    let mut slice: [Field; MAX_U] = [Field::default(); MAX_U];

    raw.iter().map(|i: &libc::c_int| *i as libc::c_uint)
              .map(|u: libc::c_uint|
            match char::from_u32(u + 12352) {
                Some('\u{3040}') => Field::default(),
                Some(c) => Field(Some(c)),
                None => Field(None),
            }
          ).collect_slice_checked(&mut slice[..]);
    mem::forget(raw);
    Ok(nalgebra::DMatrix::from_row_vector(AXE_U, AXE_U, &slice))
  }
}

impl fmt::Display for Field {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    match self.0 {
      None => write!(f, "  "),
      Some(c) => write!(f, "{}", c),
    }
  }
}

impl Default for Field {
  fn default() -> Field {
    Field(None)
  }
}
