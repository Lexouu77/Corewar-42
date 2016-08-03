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
macro_rules! socket {
    ($protocol: expr) => ({
        socket!(::ffi::AF_INET, ::ffi::SOCK_STREAM, $protocol)
    });
    ($domain: expr, $ty: expr, $protocol: expr) => ({
        match $crate::ffi::socket($domain, $ty, $protocol) {
            -1 => None,
            s => Some(s),
        }
    });
}
```
