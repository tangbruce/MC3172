################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MC3172/thread_start.c 

OBJS += \
./MC3172/thread_start.o 

C_DEPS += \
./MC3172/thread_start.d 


# Each subdirectory must supply rules for building sources it contributes
MC3172/%.o: ../MC3172/%.c
	@	@	riscv-none-embed-gcc -march=rv32imc -mabi=ilp32 -mtune=size -msmall-data-limit=8 -mstrict-align -mno-save-restore -mno-div -mbranch-cost=1 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin  -g3 -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

