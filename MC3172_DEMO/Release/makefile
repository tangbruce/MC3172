################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USER_CODE/subdir.mk
-include MC3172/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
MC3172.hex \

SECONDARY_SIZE += \
MC3172.siz \


# 所有目标
all: MC3172.elf secondary-outputs

# 工具调用
MC3172.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imc -mabi=ilp32 -mtune=size -msmall-data-limit=8 -mstrict-align -mno-save-restore -mno-div -mbranch-cost=1 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin  -g3 -T "E:\tanghuibin\MC3172\MC3172资料合集\MC3172资料合集\MC3172_Template\MC3172_Template\MC3172\MC3172.lds" -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Wl,-Map,"MC3172.map" --specs=nano.specs --specs=nosys.specs -o "MC3172.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
MC3172.hex: MC3172.elf
	@	riscv-none-embed-objcopy -O ihex "MC3172.elf"  "MC3172.hex"
	@	@
MC3172.siz: MC3172.elf
	@	riscv-none-embed-size --format=berkeley "MC3172.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) MC3172.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
