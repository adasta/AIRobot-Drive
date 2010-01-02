################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AIRobot_DriveSide.lss \

FLASH_IMAGE += \
AIRobot_DriveSide.hex \

EEPROM_IMAGE += \
AIRobot_DriveSide.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AIRobot_DriveSide.elf secondary-outputs

# Tool invocations
AIRobot_DriveSide.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,AIRobot_DriveSide.map,--cref -mmcu=atmega328p -o"AIRobot_DriveSide.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AIRobot_DriveSide.lss: AIRobot_DriveSide.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AIRobot_DriveSide.elf  >"AIRobot_DriveSide.lss"
	@echo 'Finished building: $@'
	@echo ' '

AIRobot_DriveSide.hex: AIRobot_DriveSide.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex AIRobot_DriveSide.elf  "AIRobot_DriveSide.hex"
	@echo 'Finished building: $@'
	@echo ' '

AIRobot_DriveSide.eep: AIRobot_DriveSide.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AIRobot_DriveSide.elf  "AIRobot_DriveSide.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AIRobot_DriveSide.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p AIRobot_DriveSide.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(ELFS)$(FLASH_IMAGE)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) AIRobot_DriveSide.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
