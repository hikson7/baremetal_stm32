# Baremetal STM32

## Tools

| Command line tool | Description|
| - | - |
|```arm-none-eabi-gcc```| Compiler/linker|
|```arm-none-eabi-nm```| Lists the symbols in a file |
|```arm-none-eabi-objdump```| Dumps object file information |
|```arm-none-eabi-readelf```| Displays the information on elf (program) files |

```
$ arm-none-eabi-nm build/objs/minimal.o
```

```
$ arm-none-eabi-nm build/minimal.elf
```

```
$ arm-none-eabi-objdump -h build/minimal.elf
```

```
$ arm-none-eabi-objdump -h
```

## Compling
```
host   % ./run_docker
docker # cd project
docker # ./build.sh
```

## Flashing

Current uses CubeMX programmer to flash.

To-do: Flash from terminal.

## Debugging
Note: RUN THIS OUTSIDE OF DOCKER.

Both OpenOCD and GDB installations are from platformio packages ...

### OpenOCD
The config file was copied from ```~/.platformio/packages/tool-openocd/scripts/board/stm32f4discovert.cfg```

```
% ~/.platformio/packages/tool-openocd/bin/openocd --file openocd-config/stm32f4discovery.cfg
```

### arm-none-eabi-gdb
Once we have OpenOCD running, start GDB

https://stackoverflow.com/questions/38033130/how-to-use-the-gdb-gnu-debugger-and-openocd-for-microcontroller-debugging-fr
https://www.cse.unsw.edu.au/~learn/debugging/modules/all_gdb/
https://elrobotista.com/en/posts/stm32-debug-linux/
```
% ~/.platformio/packages/toolchain-gccarmnoneeabi/bin/arm-none-eabi-gdb
(gdb) target remote localhost:<OpenOCD-port>
(gdb) file resource/LED_blink/firmware.elf
(gdb) break 57
(gdb) continue
(gdb) break 60
(gdb) continue
...
```




