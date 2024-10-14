################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Relay/ECU_RELAY.c 

OBJS += \
./ECUAL/Relay/ECU_RELAY.o 

C_DEPS += \
./ECUAL/Relay/ECU_RELAY.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Relay/%.o: ../ECUAL/Relay/%.c ECUAL/Relay/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -v -Wl,-Ocoff -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


