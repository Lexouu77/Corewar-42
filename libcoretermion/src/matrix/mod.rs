pub const MAX: usize = 4096;
pub const AXE: usize = 64;

pub mod fields;
pub mod colors;
pub mod procs;

use ::libc;
use ::nalgebra;
use ::itertools::Itertools;

use ::std::io;
use ::std::fmt;

pub struct Matrix {
  fields: Vec<fields::Field>,
  colors: Vec<colors::Color>,
  procs: Vec<procs::Proc>,
}

impl Matrix {
  pub fn new (
    fields: nalgebra::DMatrix<fields::Field>,
    colors: nalgebra::DMatrix<colors::Color>,
    procs: nalgebra::DMatrix<procs::Proc>,
  ) -> Self {
    Matrix {
      fields: Vec::from(fields.as_vector()),
      colors: Vec::from(colors.as_vector()),
      procs: Vec::from(procs.as_vector()),
    }
  }

  pub fn from_ffi (
    p_fields: *const libc::c_int,
    p_colors: *const libc::c_int,
    p_procs: *const libc::c_int,
  ) -> io::Result<Self> {
    Ok(Matrix::new(
      try!(fields::Field::new(p_fields)),
      try!(colors::Color::new(p_colors)),
      try!(procs::Proc::new(p_procs)),
    ))
  }
}

impl fmt::Display for Matrix {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "{}", izip!(&self.fields, &self.colors, &self.procs)
                        .map(|i| i).chunks_lazy(AXE)
                                   .into_iter().fold(Vec::with_capacity(MAX), |mut acc: Vec<String>, line| {
                                      acc.push(line.map(|(f, c, p)|
                                        format!("{}{}{}", c, p, f)
                                      ).collect::<Vec<String>>()
                                       .concat());
                                      acc
                                   }).iter().map(|l| format!("{}\n", l))
                                     .collect::<Vec<String>>()
                                     .concat()
    )
  }
}
