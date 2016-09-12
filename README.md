Vm/play.c#L20
[![Build Status](https://travis-ci.com/Lexouu77/Corewar-42.svg?token=q2S96ySaNvqWCnFGoWGd&branch=master)](https://travis-ci.com/Lexouu77/Corewar-42)

##### How to install
```shell
git clone -b graphic https://github.com/Lexouu77/Corewar-42.git core && cd core
```

##### How to use
```shell
./corewar resources/bee_gees.cor resources/bigzork.cor resources/fluttershy.cor
```

##### Arena/VmData
```
* field (len: mem_size)
* color_field
* process_field (0 -> Empty, 1...4 => game)
* fresh_field () // veux faire une modif

* decrementing: char (1 -> cycle data down , N -> Nothing)
* cycles: int (number of current cycle)
* cycles_to_die: int (number of cycle after check)
* cycle_delta: int (N -> discriminent)
* number_of_checks: int (number of check)
* period_live_number: (all the player's period number)
* next_cycle_check: (Next check of period)

* pause: bool (depend of if `space` key is actived)
```

##### Player
```
* number_of_player: int
* number_of_process: int
* name: *const char (display with the color [number_of_player @ 1..4 -> color ] )
* comment: *const char
* cycle_of_last_live: int
* period_live_number: int
```
