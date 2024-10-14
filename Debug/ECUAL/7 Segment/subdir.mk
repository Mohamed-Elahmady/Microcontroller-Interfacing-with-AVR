################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/7\ Segment/ECU_7_Segment.c 

OBJS += \
./ECUAL/7\ Segment/ECU_7_Segment.o 

C_DEPS += \
./ECUAL/7\ Segment/ECU_7_Segment.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/7\ Segment/ECU_7_Segment.o: ../ECUAL/7\ Segment/ECU_7_Segment.c ECUAL/7\ Segment/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -v -Wl,-Ocoff -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"ECUAL/7 Segment/ECU_7_Segment.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


