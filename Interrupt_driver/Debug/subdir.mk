################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../INT.c \
../KPD_prog.c \
../LCD.c \
../adc.c \
../main.c 

OBJS += \
./DIO_program.o \
./INT.o \
./KPD_prog.o \
./LCD.o \
./adc.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./INT.d \
./KPD_prog.d \
./LCD.d \
./adc.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


