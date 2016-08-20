#![crate_type = "staticlib"]
#![feature(const_fn)]

#[macro_use] extern crate itertools;
extern crate collect_slice;
extern crate termion;
extern crate nalgebra;
extern crate libc;

pub const MAX: usize = 4096;
pub const AXE: usize = 64;

use itertools::Itertools;

use std::mem;
use std::char;

use termion::event::{Key, Event, MouseEvent};
use termion::input::{TermRead, MouseTerminal};
use termion::raw::IntoRawMode;
use std::io::{Write, stdout, stdin};

use std::slice;
use std::io;

use collect_slice::CollectSlice;

use nalgebra::{Cast, Column, ColumnSlice, Row, RowSlice, Diagonal, Eye, Indexable, Shape, BaseNum};
use nalgebra::{ApproxEq, Inverse, Transpose, Mean, Covariance};

fn matrix (
  p_fields: *mut libc::c_int,
) -> Result<nalgebra::DMatrix<char>, io::Error> {
  let raw: &[libc::c_int] = unsafe {
      slice::from_raw_parts(p_fields, MAX)
  };
  let mut slice: [char; MAX] = ['_'; MAX];
  raw.iter().map(|i: &libc::c_int| *i as libc::c_uint)
            .map(|u: libc::c_uint|
            match char::from_u32(u + 12352) {
                Some('\u{3040}') => '。',
                Some(c) => c,
                None => panic!("{}", u),
            }
          ).collect_slice_checked(&mut slice[..]);
  mem::forget(raw);
  let matrix = nalgebra::DMatrix::from_row_vector(AXE, AXE, &slice)
                                 .transpose();
  Ok(matrix)
}

#[no_mangle]
pub extern fn core_termion (
  p_fields: *mut libc::c_int,
  p_colors: *mut libc::c_int,
) -> i32 {
  let stdin = stdin();
  let mut stdout = stdout();

  write!(stdout, "{}{}", termion::cursor::Goto(0, 5), termion::clear::All).unwrap();

  let matrix = matrix(p_fields).unwrap();
  let (nrows, ncols): (u16, u16) = termion::terminal_size().unwrap();
  let (nrows, ncols): (usize, usize) = (nrows as usize, ncols as usize);

  let m: &[char] = matrix.as_vector();
  
  {0..matrix.nrows()}.foreach(|i| {
      {0..matrix.ncols()}.foreach(|j| {
        print!("{}", m[i + j * AXE]);
      });
      println!("");
    }
  );

  use std::thread;
  use std::time::Duration;
  thread::sleep(Duration::from_millis(500));
  0
}
