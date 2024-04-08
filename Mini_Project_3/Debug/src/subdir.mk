################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc.c \
../src/gpio.c \
../src/lcd.c \
../src/lm35_sensor.c \
../src/main.c \
../src/motor.c \
../src/pwm.c 

OBJS += \
./src/adc.o \
./src/gpio.o \
./src/lcd.o \
./src/lm35_sensor.o \
./src/main.o \
./src/motor.o \
./src/pwm.o 

C_DEPS += \
./src/adc.d \
./src/gpio.d \
./src/lcd.d \
./src/lm35_sensor.d \
./src/main.d \
./src/motor.d \
./src/pwm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Youssef\Desktop\Youssef_Ahmed_85_All_Mini_Projects\Mini_Project_3\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


