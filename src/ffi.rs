// @adjivas - github.com/adjivas. See the LICENSE
// file at the top-level directory of this distribution and at
// https://github.com/adjivas/krpsim
//
// This file may not be copied, modified, or distributed
// except according to those terms.

use super::libc::{c_char, c_int};

extern {
    pub fn is_a_s_file(filename: *const c_char) -> c_int;
}
