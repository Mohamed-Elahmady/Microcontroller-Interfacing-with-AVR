################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/LED/ECU_LED.c 

OBJS += \
./ECUAL/LED/ECU_LED.o 

C_DEPS += \
./ECUAL/LED/ECU_LED.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/LED/%.o: ../ECUAL/LED/%.c ECUAL/LED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -v -Wl,-Ocoff -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


