################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TOUCHSENSING/App/subdir.mk
-include Middlewares/ST/STM32_TouchSensing_Library/src/subdir.mk
-include Drivers/STM32L0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := jeu_moulin_L072CZU6_test
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
jeu_moulin_L072CZU6_test.elf \

MAP_FILES += \
jeu_moulin_L072CZU6_test.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
jeu_moulin_L072CZU6_test.list \


# All Target
all: main-build

# Main-build Target
main-build: jeu_moulin_L072CZU6_test.elf secondary-outputs

# Tool invocations
jeu_moulin_L072CZU6_test.elf jeu_moulin_L072CZU6_test.map: $(OBJS) $(USER_OBJS) D:\projet\jeu\ du\ moulin\jeu_du_moulin_2025_boura\jeu_du_moulin_boura\fwr\jeu_moulin_L072CZU6_test\STM32L073CZUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "jeu_moulin_L072CZU6_test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"D:\projet\jeu du moulin\jeu_du_moulin_2025_boura\jeu_du_moulin_boura\fwr\jeu_moulin_L072CZU6_test\STM32L073CZUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="jeu_moulin_L072CZU6_test.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

jeu_moulin_L072CZU6_test.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "jeu_moulin_L072CZU6_test.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout jeu_moulin_L072CZU6_test.elf jeu_moulin_L072CZU6_test.list jeu_moulin_L072CZU6_test.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
