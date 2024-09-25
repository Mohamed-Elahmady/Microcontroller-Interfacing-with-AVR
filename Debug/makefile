################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GPIO/subdir.mk
-include MCAL/subdir.mk
-include ECUAL/LED/subdir.mk
-include ECUAL/BTN/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := AVR_ATMEGA32_DRIVERS
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVR_ATMEGA32_DRIVERS.lss \

FLASH_IMAGE += \
AVR_ATMEGA32_DRIVERS.hex \

EEPROM_IMAGE += \
AVR_ATMEGA32_DRIVERS.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: AVR_ATMEGA32_DRIVERS.elf secondary-outputs

# Tool invocations
AVR_ATMEGA32_DRIVERS.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_ATMEGA32_DRIVERS.map -mmcu=atmega32 -o "AVR_ATMEGA32_DRIVERS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_ATMEGA32_DRIVERS.lss: AVR_ATMEGA32_DRIVERS.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_ATMEGA32_DRIVERS.elf  >"AVR_ATMEGA32_DRIVERS.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_ATMEGA32_DRIVERS.hex: AVR_ATMEGA32_DRIVERS.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_ATMEGA32_DRIVERS.elf  "AVR_ATMEGA32_DRIVERS.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVR_ATMEGA32_DRIVERS.eep: AVR_ATMEGA32_DRIVERS.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVR_ATMEGA32_DRIVERS.elf  "AVR_ATMEGA32_DRIVERS.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_ATMEGA32_DRIVERS.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_ATMEGA32_DRIVERS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_ATMEGA32_DRIVERS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
