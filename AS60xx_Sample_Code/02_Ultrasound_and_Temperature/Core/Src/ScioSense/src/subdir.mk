################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/ScioSense/src/as60xx.cpp 

OBJS += \
./Core/Src/ScioSense/src/as60xx.o 

CPP_DEPS += \
./Core/Src/ScioSense/src/as60xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ScioSense/src/%.o Core/Src/ScioSense/src/%.su Core/Src/ScioSense/src/%.cyclo: ../Core/Src/ScioSense/src/%.cpp Core/Src/ScioSense/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DEXAMPLE_ULTRASOUND_AND_TEMPERATURE -DUSE_HAL_DRIVER -DSTM32U385xx -c -I../Core/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ScioSense-2f-src

clean-Core-2f-Src-2f-ScioSense-2f-src:
	-$(RM) ./Core/Src/ScioSense/src/as60xx.cyclo ./Core/Src/ScioSense/src/as60xx.d ./Core/Src/ScioSense/src/as60xx.o ./Core/Src/ScioSense/src/as60xx.su

.PHONY: clean-Core-2f-Src-2f-ScioSense-2f-src

