################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Interrupt/HAL_EXT_INTERRUPT.c \
../MCAL/Interrupt/HAL_INTERRUPT_MNG.c \
../MCAL/Interrupt/HAL_INT_INTERRUPT.c 

OBJS += \
./MCAL/Interrupt/HAL_EXT_INTERRUPT.o \
./MCAL/Interrupt/HAL_INTERRUPT_MNG.o \
./MCAL/Interrupt/HAL_INT_INTERRUPT.o 

C_DEPS += \
./MCAL/Interrupt/HAL_EXT_INTERRUPT.d \
./MCAL/Interrupt/HAL_INTERRUPT_MNG.d \
./MCAL/Interrupt/HAL_INT_INTERRUPT.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Interrupt/%.o: ../MCAL/Interrupt/%.c MCAL/Interrupt/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -v -Wl,-Ocoff -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


