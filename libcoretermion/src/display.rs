use ::libc;
use ::std::io;
use ::nalgebra;

use super::matrix;
use super::matrix::{fields, colors, procs};

pub fn new (
  p_fields: *mut libc::c_int,
  p_colors: *mut libc::c_int,
  p_procs: *mut libc::c_int,
) -> io::Result<()> {
  let field: nalgebra::DMatrix<fields::Field> = try!(matrix::fields::new(p_fields));
  let color: nalgebra::DMatrix<colors::Color> = try!(matrix::colors::new(p_colors));
  let procs: nalgebra::DMatrix<procs::Proc> = try!(matrix::procs::new(p_procs));
  let mut matrix: matrix::Matrix = matrix::Matrix::new(
    &field,
    &color,
    &procs,
  );

  while let Some(line) = matrix.next() {
    println!("{}", line);
  }
  Ok(())
}
