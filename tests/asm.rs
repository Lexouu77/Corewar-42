// @adjivas - github.com/adjivas. See the LICENSE
// file at the top-level directory of this distribution and at
// https://github.com/adjivas/krpsim
//
// This file may not be copied, modified, or distributed
// except according to those terms.

use std::process::Command;

macro_rules! asm {
  ($pathname: expr) => ({
    Command::new("Asm/asm").args(&[$pathname]).output().unwrap().stdout
  });
}

#[test]
fn test_simple () {
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/simple.s")),
    String::from("[live]\n\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}4\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/simple.s\u{1b}[0m\u{0} : No parameters used.\n")
  );
}

#[test]
fn test_empty () {
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/empty.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} \u{1b}[35m\u{0}resources/empty.s\u{1b}[0m\u{0} : Empty file.\n")
  );
}

#[test]
fn test_list () {
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test00.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} \u{1b}[35m\u{0}resources/test00.s\u{1b}[0m\u{0} : No [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test01.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test01.s\u{1b}[0m\u{0} : Missing dquotes during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test02.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}8\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test02.s\u{1b}[0m\u{0} : Empty name during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test03.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}11\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test03.s\u{1b}[0m\u{0} : Invalid character during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test04.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}7\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test04.s\u{1b}[0m\u{0} : Invalid character during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test05.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test05.s\u{1b}[0m\u{0} : Too many dquotes during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test06.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}8\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test06.s\u{1b}[0m\u{0} : Name too long during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test07.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} \u{1b}[35m\u{0}resources/test07.s\u{1b}[0m\u{0} : No [.comment] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test08.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} \u{1b}[35m\u{0}resources/test08.s\u{1b}[0m\u{0} : Multiple [.name] declaration. [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}2\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}3\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}4\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}5\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}6\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}7\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}8\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}9\u{1b}[0m\u{0}].\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test09.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}2\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}11\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test09.s\u{1b}[0m\u{0} : Empty comment during [.comment] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test10.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}2\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}11\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test10.s\u{1b}[0m\u{0} : comment too long during [.comment] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test11.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} \u{1b}[35m\u{0}resources/test11.s\u{1b}[0m\u{0} : Multiple [.comment] declaration. [\u{1b}[32m\u{0}2\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}3\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}4\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}5\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}6\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}7\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}8\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}9\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}10\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}11\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}12\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}13\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}14\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}15\u{1b}[0m\u{0}] | [\u{1b}[32m\u{0}16\u{1b}[0m\u{0}].\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test12.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} \u{1b}[35m\u{0}resources/test12.s\u{1b}[0m\u{0} : No instructions in the file.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test13.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}10\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test13.s\u{1b}[0m\u{0} : Invalid character during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test14.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}10\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test14.s\u{1b}[0m\u{0} : Invalid character during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test15.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}10\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test15.s\u{1b}[0m\u{0} : Invalid character during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test16.s")),
    String::from("\u{1b}[31m\u{0}\u{1b}[1m\u{0}ERROR\u{1b}[0m\u{0} \u{1b}[33m\u{0}\u{1b}[1m\u{0}->\u{1b}[0m\u{0} [\u{1b}[32m\u{0}1\u{1b}[0m\u{0}]~[\u{1b}[36m\u{0}10\u{1b}[0m\u{0}]\u{1b}[35m\u{0}resources/test16.s\u{1b}[0m\u{0} : Invalid character during [.name] declaration.\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test17.s")),
    String::from("[live]\n[live]\n\u{1b}[32m\u{0}SUCCESS\u{1b}[0m\u{0} : \u{1b}[33m\u{0}resources/test17.cor\u{1b}[0m\u{0} created!\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test18.s")),
    String::from("[live]\n[live]\n\u{1b}[32m\u{0}SUCCESS\u{1b}[0m\u{0} : \u{1b}[33m\u{0}resources/test18.cor\u{1b}[0m\u{0} created!\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test19.s")),
    String::from("[live]\n[live]\n\u{1b}[32m\u{0}SUCCESS\u{1b}[0m\u{0} : \u{1b}[33m\u{0}resources/test19.cor\u{1b}[0m\u{0} created!\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test20.s")),
    String::from("[and]\n[and]\n\u{1b}[32m\u{0}SUCCESS\u{1b}[0m\u{0} : \u{1b}[33m\u{0}resources/test20.cor\u{1b}[0m\u{0} created!\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test21.s")),
    String::from("[and]\n[and]\n\u{1b}[32m\u{0}SUCCESS\u{1b}[0m\u{0} : \u{1b}[33m\u{0}resources/test21.cor\u{1b}[0m\u{0} created!\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test22.s")),
    String::from("[and]\n[and]\n\u{1b}[32m\u{0}SUCCESS\u{1b}[0m\u{0} : \u{1b}[33m\u{0}resources/test22.cor\u{1b}[0m\u{0} created!\n")
  );
  assert_eq!(
    String::from_utf8_lossy(&asm!("resources/test23.s")),
    String::from("[live]\n[live]\n\u{1b}[32m\u{0}SUCCESS\u{1b}[0m\u{0} : \u{1b}[33m\u{0}resources/test23.cor\u{1b}[0m\u{0} created!\n")
  );
}
