// @adjivas - github.com/adjivas. See the LICENSE
// file at the top-level directory of this distribution and at
// https://github.com/adjivas/krpsim
//
// This file may not be copied, modified, or distributed
// except according to those terms.

use std::process::Command;

#[test]
fn test_simple () {
  let output = Command::new("Asm/asm").args(&["Asm/test.s"])
                                      .output()
                                      .unwrap();

  assert_eq!(
    String::from_utf8_lossy(&output.stdout),
    String::from("[live]\n\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}4\u{1b}[0m\u{0}]\u{1b}[35m\u{0}Asm/test.s\u{1b}[0m\u{0} : No parameters used.\n")
  );
}
