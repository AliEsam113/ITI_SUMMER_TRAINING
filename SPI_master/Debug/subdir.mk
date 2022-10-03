################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../INT.c \
../LCD.c \
../TIMER1_program.c \
../adc.c \
../main.c \
../spi.c \
../uart.c 

OBJS += \
./DIO_program.o \
./INT.o \
./LCD.o \
./TIMER1_program.o \
./adc.o \
./main.o \
./spi.o \
./uart.o 

C_DEPS += \
./DIO_program.d \
./INT.d \
./LCD.d \
./TIMER1_program.d \
./adc.d \
./main.d \
./spi.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


