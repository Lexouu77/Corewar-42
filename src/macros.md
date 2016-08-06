```rust
#[macro_export]
macro_rules! is_not_null {
  ($ptr: expr) => ({
      if $ptr.is_null() {
          None
      }
      else {
          Some($ptr)
      }
  });
}

#[macro_export]
macro_rules! getprotobyname {
    () => ({ getprotobyname!(b"tcp") });
    ($name: expr) => ({ is_not_null!(
       $crate::ffi::getprotobyname(
           $name.as_ptr() as *const $crate::ffi::c_char
       )
    ) });
}

#[macro_export]
macro_rules! gethostbyname {
    () => ({ gethostbyname!(b"localhost") });
    ($addr: expr) => ({ is_not_null!(
       $crate::ffi::gethostbyname(
           $addr.as_ptr() as *const $crate::ffi::c_char
       )
    ) });
}

#[macro_export]
macro_rules! socket {
    ($protocol: expr) => ({
        socket! (
            $crate::ffi::AF_INET,
            $crate::ffi::SOCK_STREAM,
            $protocol
        )
    });
    ($domain: expr, $ty: expr, $protocol: expr) => ({
        match $crate::ffi::socket($domain, $ty, $protocol) {
            -1 => None,
            s => Some(s),
        }
    });
}

#[macro_export]
macro_rules! bind {
    ($sock: expr, $addr: expr, $len: expr) => ({
          match $crate::ffi::bind(
              $sock,
              $addr as *const $crate::ffi::sockaddr_in,
              $len as $crate::ffi::socklen_t
          ) {
              -1 => None,
              s => Some(s),
          }
    });
}

#[macro_export]
macro_rules! accept {
    ($sock: expr, $addr: expr) => ({
        bind!(
            $sock,
            $addr,
            &mem::size_of::<::ffi::sockaddr_in>()
        )
    });
    ($sock: expr, $addr: expr, $len: expr) => ({
          match $crate::ffi::accept(
              $sock,
              $addr as *const $crate::ffi::sockaddr,
              $len as *const $crate::ffi::socklen_t
          ) {
              -1 => None,
              s => Some(s),
          }
    });
}

#[macro_export]
macro_rules! connect {
    ($sock: expr, $addr: expr, $len: expr) => ({
          match $crate::ffi::connect(
              $sock,
              $addr,
              $len
          ) {
              -1 => None,
              s => Some(s),
          }
    });
}

#[macro_export]
macro_rules! htons {
    ($port: expr) => ({
        $crate::ffi::htons(
            $port as $crate::ffi::uint16_t
        )
    });
}

#[macro_export]
macro_rules! htonl {
    () => ({ htonl!(0) });
    ($port: expr) => ({
        $crate::ffi::htonl(
            $port as $crate::ffi::uint16_t
        )
    });
}

#[macro_export]
#[cfg(unix)]
#[cfg(not(target_os = "macos"))]
macro_rules! sockaddr_in {
    ($family: expr, $port: expr, $addr: expr) => ({
        sockaddr_in!($family, $port, $addr, [0; 8])
    });
    ($family: expr, $port: expr, $addr: expr, $zero: expr) => ({
        $crate::ffi::sockaddr_in {
            sin_family: $family as $crate::ffi::sa_family_t,
            sin_port: $port as $crate::ffi::in_port_t,
            sin_addr: $addr as $crate::ffi::in_addr,
            sin_zero: $zero,
        }
    });
}

#[cfg(unix)]
#[cfg(target_os = "macos")]
#[macro_export]
macro_rules! sockaddr_in {
    ($family: expr, $port: expr, $addr: expr) => ({
        sockaddr_in!($family, $port, $addr, [0; 8]),
    });
    ($family: expr, $port: expr, $addr: expr, $zero: expr) => ({
        sockaddr_in!($family, $port, $addr, $zero,
                     mem::size_of::<::ffi::sockaddr_in>()
        )
    });
    ($family: expr, $port: expr, $addr: expr, $zero: expr, $len: expr) => ({
        $crate::ffi::sockaddr_in {
            sin_len: $len as u8,
            sin_family: $family as $crate::ffi::sa_family_t,
            sin_port: $port as $crate::ffi::in_port_t,
            sin_addr: $addr as $crate::ffi::in_addr,
            sin_zero: $zero,
        }
    });
}

#[macro_export]
macro_rules! in_addr {
    ($addr: expr) => ({
        $crate::ffi::in_addr{
            s_addr: $addr as $crate::ffi::in_addr_t
        }
    });
}
```
