################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/CPP/dc_motor.cpp \
../Core/CPP/pid_controller.cpp \
../Core/CPP/robot.cpp 

OBJS += \
./Core/CPP/dc_motor.o \
./Core/CPP/pid_controller.o \
./Core/CPP/robot.o 

CPP_DEPS += \
./Core/CPP/dc_motor.d \
./Core/CPP/pid_controller.d \
./Core/CPP/robot.d 


# Each subdirectory must supply rules for building sources it contributes
Core/CPP/%.o Core/CPP/%.su Core/CPP/%.cyclo: ../Core/CPP/%.cpp Core/CPP/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/dat/Documents/STM32/diff_drive/Core/CPP/Inc" -I"C:/Users/dat/Documents/STM32/diff_drive/Core/CPP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-CPP

clean-Core-2f-CPP:
	-$(RM) ./Core/CPP/dc_motor.cyclo ./Core/CPP/dc_motor.d ./Core/CPP/dc_motor.o ./Core/CPP/dc_motor.su ./Core/CPP/pid_controller.cyclo ./Core/CPP/pid_controller.d ./Core/CPP/pid_controller.o ./Core/CPP/pid_controller.su ./Core/CPP/robot.cyclo ./Core/CPP/robot.d ./Core/CPP/robot.o ./Core/CPP/robot.su

.PHONY: clean-Core-2f-CPP

