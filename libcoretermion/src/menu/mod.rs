use ::termion;
use ::libc;

use ::std::io::{self, Write, stdout};
use ::std::ffi;

pub fn number_of_players (
  nbr: libc::c_int
) -> io::Result<()> {
  let mut stdout: io::Stdout = io::stdout();

  write!(stdout, "{}{}: {}",
    termion::cursor::Goto(11, 4),
    "number of players",
    nbr
  )
}

pub fn player_name (
  (p_name1, p_name2, p_name3, p_name4): (*const libc::c_char,
                                         *const libc::c_char,
                                         *const libc::c_char,
                                         *const libc::c_char),
) -> io::Result<()> {
  let mut stdout: io::Stdout = io::stdout();


 unsafe {       println!("ss {:p}", ffi::CStr::from_ptr(p_name1.offset(1)) );}
  match unsafe {
    (ffi::CStr::from_ptr(p_name1).to_str(), ffi::CStr::from_ptr(p_name2).to_str(),
     ffi::CStr::from_ptr(p_name3).to_str(), ffi::CStr::from_ptr(p_name4).to_str())
  } {
    (Ok(p1), Err(_), Err(_), Err(_)) => write!(stdout, "{}{}: {}",
      termion::cursor::Goto(31, 4),
      "players",
      p1,
    ),
    (Ok(p1), Ok(p2), Err(_), Err(_)) => write!(stdout, "{}{}: {}, {}",
      termion::cursor::Goto(31, 4),
      "players",
      p1,
      p2,
    ),
    (Ok(p1), Ok(p2), Ok(p3), Err(_)) => write!(stdout, "{}{}: {}, {}, {}",
      termion::cursor::Goto(31, 4),
      "players",
      p1,
      p2,
      p3,
    ),
    (Ok(p1), Ok(p2), Ok(p3), Ok(p4)) => {

        println!("ss");
        write!(stdout, "{}{}: {}, {}, {}, {}",
      termion::cursor::Goto(31, 4),
      "players",
      p1,
      p2,
      p3,
      p4,
    )},
    _ => Ok(()),
  }
}
