```rust
mod err;

pub use self::err::{ServerError, Result};

pub struct Server {
    sock: ::ffi::c_int,
}

impl Server {
    pub unsafe fn new () -> Result<Self> {
        if let Some(t) = getprotobyname!() {
            if let Some(s) = socket!((*t).p_proto) {
                Ok(Server {
                    sock: s
                })
            }
            else { Err(ServerError::SocketError) }
        }
        else { Err(ServerError::GetProtoByNameNull) }
    }
}

impl Default for Server {
    fn default() -> Server {
        unsafe {
            Server::new()
        }.unwrap()
    }
}
```
