pub const MAX: usize = 4096;
pub const AXE: usize = 64;

pub mod fields;
pub mod colors;
pub mod procs;

use ::nalgebra;
use ::itertools::ZipSlices;
use ::std::iter;

pub struct Matrix <'a> {
  fields: &'a [fields::Field],
  colors: &'a [colors::Color],
  procs: &'a [procs::Proc],
  curr: usize,
  next: usize,
}

impl <'a> Matrix <'a> {
  pub fn new (
    fields: &'a nalgebra::DMatrix<fields::Field>,
    colors: &'a nalgebra::DMatrix<colors::Color>,
    procs: &'a nalgebra::DMatrix<procs::Proc>,
  ) -> Self {
    Matrix {
      fields: fields.as_vector(),
      colors: colors.as_vector(),
      procs: procs.as_vector(),
      curr: 0,
      next: 0,
    }
  }
}

impl <'a> iter::Iterator for Matrix <'a> {
  type Item = String;

  fn next(&mut self) -> Option<String> {
    if self.next >= MAX {
      None
    }
    else {
      self.curr = self.next;
      self.next += AXE;
      Some (
        ZipSlices::from_slices(
          &self.colors[self.curr..self.next],
          &self.fields[self.curr..self.next]
        ).map(|(c, f)| format!("{}{}", c, f))
         .collect::<String>()
      )
    }
  }
}
