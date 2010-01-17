################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Encoder.cpp \
../HardwareSerial.cpp \
../Print.cpp \
../WMath.cpp \
../communication.cpp \
../global.cpp \
../main.cpp \
../robot.cpp 

C_SRCS += \
../WInterrupts.c \
../motorcontrol.c \
../pins_arduino.c \
../pwm.c \
../wiring.c \
../wiring_analog.c \
../wiring_digital.c \
../wiring_pulse.c \
../wiring_shift.c 

OBJS += \
./Encoder.o \
./HardwareSerial.o \
./Print.o \
./WInterrupts.o \
./WMath.o \
./communication.o \
./global.o \
./main.o \
./motorcontrol.o \
./pins_arduino.o \
./pwm.o \
./robot.o \
./wiring.o \
./wiring_analog.o \
./wiring_digital.o \
./wiring_pulse.o \
./wiring_shift.o 

C_DEPS += \
./WInterrupts.d \
./motorcontrol.d \
./pins_arduino.d \
./pwm.d \
./wiring.d \
./wiring_analog.d \
./wiring_digital.d \
./wiring_pulse.d \
./wiring_shift.d 

CPP_DEPS += \
./Encoder.d \
./HardwareSerial.d \
./Print.d \
./WMath.d \
./communication.d \
./global.d \
./main.d \
./robot.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


