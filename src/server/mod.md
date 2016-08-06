```rust
mod err;
pub mod connection;

pub use self::err::{ServerError, Result};
use ::std::mem;

pub struct Server {
    /// Socket.
    pub fd: ::ffi::c_int,
}

impl Server {

    pub unsafe fn new (
		port: ::ffi::c_int,
		limit: ::ffi::c_int,
	) -> Result<Self> {
        if let Some(proto) = getprotobyname!() {
            if let Some(sock) = socket!((*proto).p_proto) {
				if bind!(
                    sock,
                    &sockaddr_in!(
                        ::ffi::AF_INET,
    			        htons!(port),
                        in_addr! (
                            htonl!()
                        )
				    ),
                    mem::size_of::<::ffi::sockaddr_in>()
                ).is_some() {
					::ffi::listen(sock, limit);
 	               	Ok(Server {
    	              fd: sock,
        	       	})
		    	}
                else { Err(ServerError::BindError) }
            }
            else { Err(ServerError::SocketError) }
        }
        else { Err(ServerError::GetProtoByNameNull) }
    }
}

impl Drop for Server {

    /// The function `drop` closes the server's socket.

	fn drop(&mut self) {
		unsafe {
            ::ffi::close(self.fd);
        }
	}
}
```
