PROJ_ROOT=$PWD

# arm-none-eabi-gcc -c \
#     $PROJ_ROOT/src/minimal.c \
#     -I$PROJ_ROOT/inc \
#     -o $PROJ_ROOT/build/objs/minimal.o


# Generate object files
arm-none-eabi-gcc -c \
    -o $PROJ_ROOT/build/objs/minimal.o \
    $PROJ_ROOT/src/minimal.c \
    -I$PROJ_ROOT/inc \
    -ffunction-sections \
    -fdata-sections \
    -O0

arm-none-eabi-gcc -c \
    -o $PROJ_ROOT/build/objs/stm32f446xx_startup.o \
    $PROJ_ROOT/startup/stm32f446xx_startup.s

# arm-none-eabi-gcc -c \
#     -o $PROJ_ROOT/build/objs/stm32f446xx_startup.o \
#     $PROJ_ROOT/stm32f446xx_startup.c \
#     -I$PROJ_ROOT/inc

arm-none-eabi-gcc -c \
    -o $PROJ_ROOT/build/objs/system_stm32f4xx.o \
    $PROJ_ROOT/startup/system_stm32f4xx.c \
    -I$PROJ_ROOT/inc

arm-none-eabi-gcc -c \
    -o $PROJ_ROOT/build/objs/syscalls.o \
    $PROJ_ROOT/startup/syscalls.c \
    -I$PROJ_ROOT/inc

# arm-none-eabi-gcc -c \
#     -o $PROJ_ROOT/build/objs/stm32f4xx_it.o \
#     $PROJ_ROOT/startup/stm32f4xx_it.c \
#     -I$PROJ_ROOT/inc

# Link the object files, provide memory addresses
# according to given linker scripts.
echo "Linking now"
# arm-none-eabi-gcc \
#     -T $PROJ_ROOT/build/linker_script.ld \
#     $PROJ_ROOT/build/objs/minimal.o \
#     $PROJ_ROOT/build/objs/stm32f446xx_startup.o \
#     $PROJ_ROOT/build/objs/system_stm32f4xx.o \
#     $PROJ_ROOT/build/objs/syscalls.o \
#     $PROJ_ROOT/build/objs/stm32f4xx_it.o \
#     -o $PROJ_ROOT/build/minimal.elf

arm-none-eabi-gcc \
    -T $PROJ_ROOT/build/linker_script.ld \
    $PROJ_ROOT/build/objs/minimal.o \
    $PROJ_ROOT/build/objs/stm32f446xx_startup.o \
    $PROJ_ROOT/build/objs/system_stm32f4xx.o \
    $PROJ_ROOT/build/objs/syscalls.o \
    -o $PROJ_ROOT/build/minimal.elf