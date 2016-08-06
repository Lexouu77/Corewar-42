```rust
extern crate corewar_vm;

use corewar_vm::client::Client;

fn main() {
    let _: Client = unsafe {
        Client::new("localhost", 4242)
    }.unwrap();
}
```
