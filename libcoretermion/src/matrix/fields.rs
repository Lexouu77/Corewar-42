use super::{MAX_U, AXE_U};

use ::nalgebra;
use ::collect_slice::CollectSlice;
use ::libc;

use ::std::*;

#[derive(Clone, Copy)]
#[cfg(not(feature = "jap"))]
pub struct Field(libc::c_uint);

#[cfg(not(feature = "jap"))]
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
                Field(u)
            ).collect_slice_checked(&mut slice[..]);
    mem::forget(raw);
    Ok(nalgebra::DMatrix::from_row_vector(AXE_U, AXE_U, &slice))
  }
}

#[cfg(not(feature = "jap"))]
impl fmt::Display for Field {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "{:02X}", self.0)
  }
}

#[cfg(not(feature = "jap"))]
impl Default for Field {
  fn default() -> Field {
    Field(0)
  }
}

#[derive(Clone, Copy)]
#[cfg(feature = "jap")]
pub struct Field(Option<char>);

#[cfg(feature = "jap")]
impl Field {
  pub fn new (
    p_fields: *const libc::c_int,
  ) -> Result<nalgebra::DMatrix<Field>, io::Error> {
    let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_fields, MAX_U)
    };
    let mut slice: [Field; MAX_U] = [Field::default(); MAX_U];

    raw.iter().map(|u: &libc::c_int| {
            match char::from_u32({*u + 12352} as u32) {
                Some('\u{3040}') => Field::default(),
                Some(c) => Field(Some(c)),
                None => Field(None),
            }
    }).collect_slice_checked(&mut slice[..]);
    mem::forget(raw);
    Ok(nalgebra::DMatrix::from_row_vector(AXE_U, AXE_U, &slice))
  }
}

#[cfg(feature = "jap")]
impl fmt::Display for Field {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    match self.0 {
      None => write!(f, "  "),
      Some(c) => write!(f, "{}", c),
    }
  }
}

#[cfg(feature = "jap")]
impl Default for Field {
  fn default() -> Field {
    Field(None)
  }
}
