```rust
#![allow(dead_code)]

/// Primitive types
pub use libc::{pid_t, size_t, ssize_t, c_int, uint16_t, c_char, c_void, sockaddr, socklen_t};

/// Primitive constents.
pub use libc::{AF_INET, SOCK_STREAM};
```

**fork** create a new process:
```rust
extern "C" {
    fn fork() -> pid_t;
}
```

Receive a message from a socket:
```rust
extern "C" {
    fn recv(socket: c_int, buf: *mut c_void, len: size_t, flags: c_int) -> ssize_t;
}
```

Send a message from a socket:
```rust
extern "C" {
    fn send(socket: c_int, buf: *const c_void, len: size_t, flags: c_int) -> ssize_t;
}
```

Open or create a file for reading or writing:
```rust
extern "C" {
    fn open(path: *const c_char, oflag: c_int, ...) -> c_int;
}
```

Delete a descriptor:
```rust
extern "C" {
    fn close(fd: c_int) -> c_int;
}
```

Get protocol entry:

```rust
#[repr(C)]
pub struct Protoent {
  /// Official protocol name.
  p_name: *const c_char,
  /// Alias list.
  p_aliases: *const *const c_char,
  /// Protocol number.
  pub p_proto: c_int,
}

extern "C" {
    pub fn getprotobyname(name: *const c_char) -> *const Protoent;
}
```

Create an endpoint for communication:
```rust
extern "C" {
    pub fn socket(domain: c_int, ty: c_int, protocol: c_int) -> c_int;
}
```

Convert values between host and network byte order:
```rust
extern "C" {
    fn htons(hostshort: uint16_t) -> uint16_t;
    fn htonl(hostshort: uint16_t) -> uint16_t;
}
```

Bind a name to a socket:
```rust
extern "C" {
    fn bind(socket: c_int, address: *const sockaddr, address_len: socklen_t) -> c_int;
}
```

Listen for connections on a socket:
```rust
extern "C" {
    fn listen(socket: c_int, backlog: c_int) -> c_int;
}
```

Accept a connection on a socket:
```rust
extern "C" {
    fn accept(socket: c_int, address: *mut sockaddr, address_len: *mut socklen_t) -> c_int;
}
```
