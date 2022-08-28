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
    $PROJ_ROOT/stm32f446xx_startup.c

# Link the object files, provide memory addresses
# according to given linker scripts.
arm-none-eabi-gcc \
    -nostartfiles \
    -T $PROJ_ROOT/build/linker_script.ld \
    $PROJ_ROOT/build/objs/minimal.o \
    $PROJ_ROOT/build/objs/stm32f446xx_startup.o \
    -o $PROJ_ROOT/build/minimal.elf

# arm-none-eabi-gcc \
#     -nostartfiles \
#     -T $PROJ_ROOT/build/linker_script.ld \
#     $PROJ_ROOT/build/objs/minimal.o \
#     -o $PROJ_ROOT/build/minimal.elf