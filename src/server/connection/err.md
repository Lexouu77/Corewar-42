```rust
use std::fmt;
use std::error::Error;

/// The alias `Result` learns `ConnectError` possibility.

pub type Result<T> = ::std::result::Result<T, ConnectError>;

#[derive(Clone, Copy, Debug)]
pub enum ConnectError {
    /// If a error is occured.
    AcceptError,
}


impl fmt::Display for ConnectError {

    /// The function `fmt` formats the value using the given formatter.

    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self)
    }
}

impl Error for ConnectError {

    /// The function `description` returns a short description of the error.

    fn description(&self) -> &str {
        match *self {
            ConnectError::AcceptError => "The call returns -1 on error and the global variable\
                                          errno is set to indicate the error.",
        }
    }

    /// The function `cause` returns the lower-level cause of this error, if any.

    fn cause(&self) -> Option<&Error> {
        None
    }
}
```
