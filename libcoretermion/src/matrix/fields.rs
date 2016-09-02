use super::{MAX, AXE};

use ::nalgebra;
use ::collect_slice::CollectSlice;
use ::libc;
use ::std::{char, io, mem, slice};

pub type Field = char;

pub fn new (
  p_fields: *mut libc::c_int,
) -> Result<nalgebra::DMatrix<Field>, io::Error> {
  let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_fields, MAX)
  };
  let mut slice: [Field; MAX] = ['_'; MAX];

  raw.iter().map(|i: &libc::c_int| *i as libc::c_uint)
            .map(|u: libc::c_uint|
            match char::from_u32(u + 12352) {
                Some('\u{3040}') => '。',
                Some(c) => c,
                None => unimplemented!(),
            }
          ).collect_slice_checked(&mut slice[..]);
  mem::forget(raw);
  Ok(nalgebra::DMatrix::from_row_vector(AXE, AXE, &slice))
}
