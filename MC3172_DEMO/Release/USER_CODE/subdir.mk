################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USER_CODE/fifo.c \
../USER_CODE/main.c \
../USER_CODE/uart.c 

OBJS += \
./USER_CODE/fifo.o \
./USER_CODE/main.o \
./USER_CODE/uart.o 

C_DEPS += \
./USER_CODE/fifo.d \
./USER_CODE/main.d \
./USER_CODE/uart.d 


# Each subdirectory must supply rules for building sources it contributes
USER_CODE/%.o: ../USER_CODE/%.c
	@	@	riscv-none-embed-gcc -march=rv32imc -mabi=ilp32 -mtune=size -msmall-data-limit=8 -mstrict-align -mno-save-restore -mno-div -mbranch-cost=1 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin  -g3 -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

