################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/CMakeCCompilerId.c 

OBJS += \
./cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/CMakeCCompilerId.o 

C_DEPS += \
./cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/CMakeCCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/%.o: ../cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


