```rust
mod err;

pub use self::err::{ClientError, Result};
use ::std::mem;

pub struct Client {
    /// Socket.
    pub fd: ::ffi::c_int,
}

impl Client {

    pub unsafe fn new (
		address: &str,
		port: ::ffi::c_int,
	) -> Result<Self> {
        if let Some(proto) = getprotobyname!() {
            if let Some(host) = gethostbyname!(address) {
                if let Some(sock) = socket!((*proto).p_proto) {
                    if connect!(
                        sock,
                        &sockaddr_in!(
                            ::ffi::AF_INET,
                            htons!(port),
                            in_addr!(::ffi::inet_addr(::ffi::inet_ntoa(
                                (*host).h_addrtype as ::libc::in_addr_t
                            )))
                        ) as *const ::ffi::sockaddr_in,
                        mem::size_of::<::ffi::sockaddr>() as ::ffi::socklen_t
                    ).is_some() {
                       Ok(Client {
                           fd: sock,
                       })                   
                    }
                    else { Err(ClientError::ConnectError) }
                }
                else { Err(ClientError::SocketError) }
            }
            else { Err(ClientError::GetHostByNameNull) }
        }
        else { Err(ClientError::GetProtoByNameNull) }
    }
}

impl Drop for Client {

    /// The function `drop` closes the client's connection.

	fn drop(&mut self) {
		unsafe {
            ::ffi::close(self.fd);
        }
	}
}
```
