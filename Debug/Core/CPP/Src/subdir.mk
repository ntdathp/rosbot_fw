################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/CPP/Src/dc_motor.cpp \
../Core/CPP/Src/main.cpp \
../Core/CPP/Src/pid_controller.cpp \
../Core/CPP/Src/robot.cpp 

OBJS += \
./Core/CPP/Src/dc_motor.o \
./Core/CPP/Src/main.o \
./Core/CPP/Src/pid_controller.o \
./Core/CPP/Src/robot.o 

CPP_DEPS += \
./Core/CPP/Src/dc_motor.d \
./Core/CPP/Src/main.d \
./Core/CPP/Src/pid_controller.d \
./Core/CPP/Src/robot.d 


# Each subdirectory must supply rules for building sources it contributes
Core/CPP/Src/%.o Core/CPP/Src/%.su Core/CPP/Src/%.cyclo: ../Core/CPP/Src/%.cpp Core/CPP/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/dat/Documents/STM32/diff_drive/Core/CPP/Inc" -I"C:/Users/dat/Documents/STM32/diff_drive/Core/CPP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-CPP-2f-Src

clean-Core-2f-CPP-2f-Src:
	-$(RM) ./Core/CPP/Src/dc_motor.cyclo ./Core/CPP/Src/dc_motor.d ./Core/CPP/Src/dc_motor.o ./Core/CPP/Src/dc_motor.su ./Core/CPP/Src/main.cyclo ./Core/CPP/Src/main.d ./Core/CPP/Src/main.o ./Core/CPP/Src/main.su ./Core/CPP/Src/pid_controller.cyclo ./Core/CPP/Src/pid_controller.d ./Core/CPP/Src/pid_controller.o ./Core/CPP/Src/pid_controller.su ./Core/CPP/Src/robot.cyclo ./Core/CPP/Src/robot.d ./Core/CPP/Src/robot.o ./Core/CPP/Src/robot.su

.PHONY: clean-Core-2f-CPP-2f-Src

