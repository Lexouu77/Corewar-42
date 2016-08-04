```rust
extern crate corewar_vm;

use corewar_vm::server::Server;
use corewar_vm::server::connection::Connect;

fn main() {
    let serv: Server = unsafe {
        Server::new(4242, 80)
    }.unwrap();

    loop {
        let _: Connect = unsafe {
            Connect::new(serv.fd)
        }.unwrap();
    }
}
```
