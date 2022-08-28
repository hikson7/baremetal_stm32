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