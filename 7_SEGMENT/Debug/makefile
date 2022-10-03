################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include cmake-build-debug/CMakeFiles/7_SEGMENT.dir/subdir.mk
-include cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
7_SEGMENT.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: 7_SEGMENT.elf secondary-outputs

# Tool invocations
7_SEGMENT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,7_SEGMENT.map -mmcu=atmega32 -o "7_SEGMENT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

7_SEGMENT.lss: 7_SEGMENT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 7_SEGMENT.elf  >"7_SEGMENT.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 7_SEGMENT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 7_SEGMENT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 7_SEGMENT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
