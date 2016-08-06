```rust
use std::fmt;
use std::error::Error;

/// The alias `Result` learns `ClientError` possibility.

pub type Result<T> = ::std::result::Result<T, ClientError>;

#[derive(Clone, Copy, Debug)]
pub enum ClientError {
    /// If the pointer is null.
    GetProtoByNameNull,
    /// If the pointer is null.
    GetHostByNameNull,
    /// If a error is occured.
    SocketError,
    /// If a error is occured.
    ConnectError,
}


impl fmt::Display for ClientError {

    /// The function `fmt` formats the value using the given formatter.

    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self)
    }
}

impl Error for ClientError {

    /// The function `description` returns a short description of the error.

    fn description(&self) -> &str {
        match *self {
            ClientError::GetProtoByNameNull => "Null pointer (0) returned on EOF or error.",
            ClientError::GetHostByNameNull => "Null pointer (0) returned on EOF or error.",
            ClientError::SocketError => "A -1 is returned if an error occurs, otherwise the return\
                                         value is a descriptor referencing the socket.",
            ClientError::ConnectError => "On error, -1 is returned, and errno is set\
            appropriately."
        }
    }

    /// The function `cause` returns the lower-level cause of this error, if any.

    fn cause(&self) -> Option<&Error> {
        None
    }
}
```
