################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Timer0.c \
../Timer1.c \
../adc.c \
../lcd.c \
../motor_fan.c \
../uart.c 

OBJS += \
./Timer0.o \
./Timer1.o \
./adc.o \
./lcd.o \
./motor_fan.o \
./uart.o 

C_DEPS += \
./Timer0.d \
./Timer1.d \
./adc.d \
./lcd.d \
./motor_fan.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


