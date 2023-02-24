################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/GitHub/EmbedSoftProjects/Proj_G031J/GPIO_IOToggle/Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.c 

OBJS += \
./Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.o 

C_DEPS += \
./Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.o: D:/GitHub/EmbedSoftProjects/Proj_G031J/GPIO_IOToggle/Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.c Drivers/BSP/STM32G0316-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32G031xx -c -I../../Inc -I../../Drivers/STM32G0xx_HAL_Driver/Inc -I../../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/STM32G0316-DISCO -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32G0316-2d-DISCO

clean-Drivers-2f-BSP-2f-STM32G0316-2d-DISCO:
	-$(RM) ./Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.d ./Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.o ./Drivers/BSP/STM32G0316-DISCO/stm32g0316_discovery.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32G0316-2d-DISCO

