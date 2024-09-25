################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/BTN/ECU_BTN.c 

OBJS += \
./ECUAL/BTN/ECU_BTN.o 

C_DEPS += \
./ECUAL/BTN/ECU_BTN.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/BTN/%.o: ../ECUAL/BTN/%.c ECUAL/BTN/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


