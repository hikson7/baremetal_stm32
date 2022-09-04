
PROJ_NAME="baremetal-stm32-blinky"
LINKER_PATH=linker_script.ld


STARTUP_FILE="stm32f446xx_startup"
arm-none-eabi-gcc \
    -mcpu=cortex-m4 \
    -g3 \
    -DDEBUG \
    -c \
    -x \
    assembler-with-cpp \
    --specs=nano.specs \
    -mfpu=fpv4-sp-d16 \
    -mfloat-abi=hard \
    -mthumb \
    -o "build/obj/$STARTUP_FILE.o" \
    "startup/$STARTUP_FILE.s"

TARGET_FILE="minimal"

arm-none-eabi-gcc \
    "src/$TARGET_FILE.c" \
    -mcpu=cortex-m4 \
    -std=gnu11 \
    -g3 \
    -DDEBUG \
    -DSTM32 \
    -DSTM32F4 \
    -DSTM32F446RETx \
    -c \
    -I"inc" \
    -O0 \
    -ffunction-sections \
    -fdata-sections \
    -Wall \
    -fstack-usage \
    --specs=nano.specs \
    -mfpu=fpv4-sp-d16 \
    -mfloat-abi=hard \
    -mthumb \
    -o "build/obj/$TARGET_FILE.o"

TARGET_FILE="syscall"
arm-none-eabi-gcc \
    "src/$TARGET_FILE.c" \
    -mcpu=cortex-m4 \
    -std=gnu11 \
    -g3 \
    -DDEBUG \
    -DSTM32 \
    -DSTM32F4 \
    -DSTM32F446RETx \
    -c \
    -I"inc" \
    -O0 \
    -ffunction-sections \
    -fdata-sections \
    -Wall \
    -fstack-usage \
    --specs=nano.specs \
    -mfpu=fpv4-sp-d16 \
    -mfloat-abi=hard \
    -mthumb \
    -o "build/obj/$TARGET_FILE.o"

TARGET_FILE="sysmem"
arm-none-eabi-gcc \
    "src/$TARGET_FILE.c" \
    -mcpu=cortex-m4 \
    -std=gnu11 \
    -g3 \
    -DDEBUG \
    -DSTM32 \
    -DSTM32F4 \
    -DSTM32F446RETx \
    -c \
    -I"inc" \
    -O0 \
    -ffunction-sections \
    -fdata-sections \
    -Wall \
    -fstack-usage \
    --specs=nano.specs \
    -mfpu=fpv4-sp-d16 \
    -mfloat-abi=hard \
    -mthumb \
    -o "build/obj/$TARGET_FILE.o"


# arm-none-eabi-gcc "../Src/syscalls.c" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"Src/syscalls.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "Src/syscalls.o"
# arm-none-eabi-gcc "../Src/sysmem.c" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"Src/sysmem.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "Src/sysmem.o"


echo "Linking"
OBJ_PATH=build/obj
arm-none-eabi-gcc -o \
    "build/$PROJ_NAME.elf" \
    -mcpu=cortex-m4 \
    -T$LINKER_PATH \
    build/obj/minimal.o \
    build/obj/stm32f446xx_startup.o \
    build/obj/syscall.o \
    build/obj/sysmem.o \
    --specs=nosys.specs \
    -Wl,-Map=build/"$PROJ_NAME.map" \
    -Wl,--gc-sections \
    -static \
    --specs=nano.specs \
    -mfpu=fpv4-sp-d16 \
    -mfloat-abi=hard \
    -mthumb \
    -Wl,--start-group \
    -lc \
    -lm \
    -Wl,--end-group

echo "Finished building target: $PROJ_NAME.elf"
# echo "Creating objdump for debugging"
# arm-none-eabi-objdump -h -S  nucleo-f446re-empty-blinky.elf  > PROJ_NAME".list"
# echo "Done"
