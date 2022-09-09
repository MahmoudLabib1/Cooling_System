################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/EHAL/DC_MOTOR/dc_motor.c 

OBJS += \
./SRC/EHAL/DC_MOTOR/dc_motor.o 

C_DEPS += \
./SRC/EHAL/DC_MOTOR/dc_motor.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/EHAL/DC_MOTOR/%.o: ../SRC/EHAL/DC_MOTOR/%.c SRC/EHAL/DC_MOTOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


