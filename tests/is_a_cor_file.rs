// @adjivas - github.com/adjivas. See the LICENSE
// file at the top-level directory of this distribution and at
// https://github.com/adjivas/krpsim
//
// This file may not be copied, modified, or distributed
// except according to those terms.

extern crate asm_test;
extern crate libc;

use self::asm_test::ffi::is_a_cor_file;
use self::libc::c_char;

#[test]
fn test_is_a_cor_file () {
   assert_eq!(1, unsafe {
           is_a_cor_file(".cor\0".as_ptr() as *const c_char)
   });
   assert_eq!(1, unsafe {
           is_a_cor_file("_.cor\0".as_ptr() as *const c_char)
   });
   assert_eq!(1, unsafe {
           is_a_cor_file("___________.cor.cor\0".as_ptr() as *const c_char)
   });
   assert_eq!(1, unsafe {
           is_a_cor_file("_.cor.cor\0".as_ptr() as *const c_char)
   });
}

#[test]
fn test_is_not_a_cor_file () {
   assert_eq!(0, unsafe {
           is_a_cor_file(".r\0".as_ptr() as *const c_char)
   });
   assert_eq!(0, unsafe {
           is_a_cor_file("_.r\0".as_ptr() as *const c_char)
   });
   assert_eq!(0, unsafe {
           is_a_cor_file("___________.c.or\0".as_ptr() as *const c_char)
   });
   assert_eq!(0, unsafe {
           is_a_cor_file("_.c.or\0".as_ptr() as *const c_char)
   });
   assert_eq!(0, unsafe {
           is_a_cor_file("_co.r\0".as_ptr() as *const c_char)
   });
   assert_eq!(0, unsafe {
           is_a_cor_file("cor.\0".as_ptr() as *const c_char)
   });
   assert_eq!(0, unsafe {
           is_a_cor_file("cor\0".as_ptr() as *const c_char)
   });
   assert_eq!(0, unsafe {
           is_a_cor_file("\0".as_ptr() as *const c_char)
   });
}
