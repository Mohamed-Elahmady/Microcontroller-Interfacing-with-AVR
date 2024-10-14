################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Main/BTN_main.c \
../Main/LED_main.c \
../Main/Relay_main.c 

OBJS += \
./Main/BTN_main.o \
./Main/LED_main.o \
./Main/Relay_main.o 

C_DEPS += \
./Main/BTN_main.d \
./Main/LED_main.d \
./Main/Relay_main.d 


# Each subdirectory must supply rules for building sources it contributes
Main/%.o: ../Main/%.c Main/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


