use ::libc;
use ::std::io;
use super::matrix;

pub fn new (
  p_fields: *mut libc::c_int,
  p_colors: *mut libc::c_int,
  p_procs: *mut libc::c_int,
) -> io::Result<()> {
  let field = try!(matrix::fields::new(p_fields));
  let color = try!(matrix::colors::new(p_colors));
  let procs = try!(matrix::procs::new(p_procs));
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
