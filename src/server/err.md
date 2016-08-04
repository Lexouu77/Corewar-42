```rust
use std::fmt;
use std::error::Error;

/// The alias `Result` learns `ServerError` possibility.

pub type Result<T> = ::std::result::Result<T, ServerError>;

#[derive(Clone, Copy, Debug)]
pub enum ServerError {
    /// If the pointer is null.
    GetProtoByNameNull,
    /// If a error is occured.
    SocketError,
    /// If a error is occured.
    BindError,
}


impl fmt::Display for ServerError {

    /// The function `fmt` formats the value using the given formatter.

    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self)
    }
}

impl Error for ServerError {

    /// The function `description` returns a short description of the error.

    fn description(&self) -> &str {
        match *self {
            ServerError::GetProtoByNameNull => "Null pointer (0) returned on EOF or error.",
            ServerError::SocketError => "A -1 is returned if an error occurs, otherwise the return\
                                         value is a descriptor referencing the socket.",
            ServerError::BindError => "Otherwise, a value of -1 is returned and the global integer\
                                       variable errno is set to indicate the error.",
        }
    }

    /// The function `cause` returns the lower-level cause of this error, if any.

    fn cause(&self) -> Option<&Error> {
        None
    }
}
```
