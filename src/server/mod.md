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
        if let Some(t) = getprotobyname!() {
            if let Some(sock) = socket!((*t).p_proto) {
				if bind!(
                    sock,
                    &::ffi::sockaddr_in {
                        sin_len: mem::size_of::<::ffi::sockaddr_in>() as u8,
			            sin_family: ::ffi::AF_INET as ::ffi::sa_family_t,
    			        sin_port: ::ffi::htons(port as ::ffi::uint16_t) as ::ffi::in_port_t,
    			        sin_addr: ::ffi::in_addr {
	    					s_addr: ::ffi::htonl(0 as ::ffi::uint16_t) as ::ffi::in_addr_t
		    			} as ::ffi::in_addr,
			            sin_zero: [0; 8],
				    } as *const ::ffi::sockaddr_in,
                    mem::size_of::<::ffi::sockaddr_in>() as ::ffi::socklen_t
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
