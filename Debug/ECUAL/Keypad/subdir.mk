################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Keypad/ECU_KEYPAD.c 

OBJS += \
./ECUAL/Keypad/ECU_KEYPAD.o 

C_DEPS += \
./ECUAL/Keypad/ECU_KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Keypad/%.o: ../ECUAL/Keypad/%.c ECUAL/Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -v -Wl,-Ocoff -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


