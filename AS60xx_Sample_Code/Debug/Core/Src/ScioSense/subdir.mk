################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/ScioSense/01_AS60xx_Example_Basic_Ultrasound.cpp \
../Core/Src/ScioSense/02_AS60xx_Example_Ultrasound_and_Temperature.cpp 

OBJS += \
./Core/Src/ScioSense/01_AS60xx_Example_Basic_Ultrasound.o \
./Core/Src/ScioSense/02_AS60xx_Example_Ultrasound_and_Temperature.o 

CPP_DEPS += \
./Core/Src/ScioSense/01_AS60xx_Example_Basic_Ultrasound.d \
./Core/Src/ScioSense/02_AS60xx_Example_Ultrasound_and_Temperature.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ScioSense/%.o Core/Src/ScioSense/%.su Core/Src/ScioSense/%.cyclo: ../Core/Src/ScioSense/%.cpp Core/Src/ScioSense/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U385xx -c -I../Core/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ScioSense

clean-Core-2f-Src-2f-ScioSense:
	-$(RM) ./Core/Src/ScioSense/01_AS60xx_Example_Basic_Ultrasound.cyclo ./Core/Src/ScioSense/01_AS60xx_Example_Basic_Ultrasound.d ./Core/Src/ScioSense/01_AS60xx_Example_Basic_Ultrasound.o ./Core/Src/ScioSense/01_AS60xx_Example_Basic_Ultrasound.su ./Core/Src/ScioSense/02_AS60xx_Example_Ultrasound_and_Temperature.cyclo ./Core/Src/ScioSense/02_AS60xx_Example_Ultrasound_and_Temperature.d ./Core/Src/ScioSense/02_AS60xx_Example_Ultrasound_and_Temperature.o ./Core/Src/ScioSense/02_AS60xx_Example_Ultrasound_and_Temperature.su

.PHONY: clean-Core-2f-Src-2f-ScioSense

