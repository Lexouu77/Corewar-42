```rust
mod err;

pub use self::err::{ConnectError, Result};
use ::std::mem;

pub struct Connect {
    /// Socket.
    fd: ::ffi::c_int,
}

impl Connect {

    #[cfg(unix)]
    #[cfg(not(target_os = "macos"))]
    pub unsafe fn new (
		sock: ::ffi::c_int,
	) -> Result<Self> {
        if let Some(fd) = accept!(
            sock,
            &::ffi::sockaddr {
                sa_family: 0 as ::ffi::sa_family_t,
                sa_data: [0; 14],
            } as *const ::ffi::sockaddr,
            mem::size_of::<::ffi::sockaddr>() as *const ::ffi::socklen_t
        ) {
            Ok(Connect {
                fd: fd,
            })
        }
        else {
            Err(ConnectError::AcceptError)
        }
    }

    #[cfg(unix)]
    #[cfg(target_os = "macos")]
    pub unsafe fn new (
		sock: ::ffi::c_int,
	) -> Result<Self> {
        if let Some(fd) = accept!(
            sock,
            &::ffi::sockaddr {
                sa_len: mem::size_of::<::ffi::sockaddr>() as u8,
                sa_family: 0 as ::ffi::sa_family_t,
                sa_data: [0; 14],
            } as *const ::ffi::sockaddr,
            mem::size_of::<::ffi::sockaddr>() as *const ::ffi::socklen_t
        ) {
            Ok(Connect {
                fd: fd,
            })
        }
        else {
            Err(ConnectError::AcceptError)
        }
    }
}

impl Drop for Connect {

    /// The function `drop` closes the connect's socket.

	fn drop(&mut self) {
		unsafe {
            ::ffi::close(self.fd);
        }
	}
}
```
