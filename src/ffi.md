```rust
#![allow(dead_code)]

/// Primitive types
pub use libc::{
    pid_t,
    size_t,
    ssize_t,
    c_int,
    uint16_t,
    c_char,
    c_void,
    sockaddr,
    socklen_t,
    sockaddr_in,
    in_addr,
    in_addr_t,
    sa_family_t,
    in_port_t,
    hostent,
};

/// Primitive constents.
pub use libc::{AF_INET, SOCK_STREAM};

#[repr(C)]
pub struct protoent {
      /// Official protocol name.
      p_name: *const c_char,
      /// Alias list.
      p_aliases: *const *const c_char,
      /// Protocol number.
      pub p_proto: c_int,
}

extern "C" {
    /// Get protocol entry:
    pub fn getprotobyname(name: *const c_char) -> *const protoent;
    pub fn gethostbyname(address: *const c_char) -> *const hostent;
    /// **fork** create a new process:
    fn fork() -> pid_t;
    /// Receive a message from a socket:
    fn recv(socket: c_int, buf: *mut c_void, len: size_t, flags: c_int) -> ssize_t;
    /// Send a message from a socket:
    fn send(socket: c_int, buf: *const c_void, len: size_t, flags: c_int) -> ssize_t;
    /// Open or create a file for reading or writing:
    fn open(path: *const c_char, oflag: c_int, ...) -> c_int;
    /// Delete a descriptor:
    pub fn close(fd: c_int) -> c_int;
    /// Create an endpoint for communication:
    pub fn socket(domain: c_int, ty: c_int, protocol: c_int) -> c_int;
    pub fn connect(sockfd: c_int, addr: *const sockaddr_in, addrlen: socklen_t) -> c_int;
    /// Convert values between host and network byte order:
    pub fn htons(hostshort: uint16_t) -> uint16_t;
    pub fn htonl(hostshort: uint16_t) -> uint16_t;
    pub fn inet_addr(cp: *const c_char) -> in_addr_t;
    pub fn inet_ntoa(addr: in_addr_t) -> *const c_char;
    /// Bind a name to a socket:
    pub fn bind(socket: c_int, address: *const sockaddr_in, address_len: socklen_t) -> c_int;
    /// Listen for connections on a socket:
    pub fn listen(socket: c_int, backlog: c_int) -> c_int;
    /// Accept a connection on a socket:
    pub fn accept(socket: c_int, address: *const sockaddr, address_len: *const socklen_t) -> c_int;
}
```
