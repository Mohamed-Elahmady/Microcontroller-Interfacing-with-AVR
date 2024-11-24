################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/CHAR\ LCD/CHR_LCD.c 

OBJS += \
./ECUAL/CHAR\ LCD/CHR_LCD.o 

C_DEPS += \
./ECUAL/CHAR\ LCD/CHR_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/CHAR\ LCD/CHR_LCD.o: ../ECUAL/CHAR\ LCD/CHR_LCD.c ECUAL/CHAR\ LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -v -Wl,-Ocoff -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"ECUAL/CHAR LCD/CHR_LCD.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


