################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/button.c \
../Core/Src/buzzer.c \
../Core/Src/fsm_automatic.c \
../Core/Src/fsm_manual.c \
../Core/Src/fsm_ped.c \
../Core/Src/global.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/sched.c \
../Core/Src/software_timer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tim.c \
../Core/Src/traffic_light.c \
../Core/Src/uart_timer.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/buzzer.o \
./Core/Src/fsm_automatic.o \
./Core/Src/fsm_manual.o \
./Core/Src/fsm_ped.o \
./Core/Src/global.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/sched.o \
./Core/Src/software_timer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tim.o \
./Core/Src/traffic_light.o \
./Core/Src/uart_timer.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/buzzer.d \
./Core/Src/fsm_automatic.d \
./Core/Src/fsm_manual.d \
./Core/Src/fsm_ped.d \
./Core/Src/global.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/sched.d \
./Core/Src/software_timer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tim.d \
./Core/Src/traffic_light.d \
./Core/Src/uart_timer.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/button.cyclo ./Core/Src/button.d ./Core/Src/button.o ./Core/Src/button.su ./Core/Src/buzzer.cyclo ./Core/Src/buzzer.d ./Core/Src/buzzer.o ./Core/Src/buzzer.su ./Core/Src/fsm_automatic.cyclo ./Core/Src/fsm_automatic.d ./Core/Src/fsm_automatic.o ./Core/Src/fsm_automatic.su ./Core/Src/fsm_manual.cyclo ./Core/Src/fsm_manual.d ./Core/Src/fsm_manual.o ./Core/Src/fsm_manual.su ./Core/Src/fsm_ped.cyclo ./Core/Src/fsm_ped.d ./Core/Src/fsm_ped.o ./Core/Src/fsm_ped.su ./Core/Src/global.cyclo ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/sched.cyclo ./Core/Src/sched.d ./Core/Src/sched.o ./Core/Src/sched.su ./Core/Src/software_timer.cyclo ./Core/Src/software_timer.d ./Core/Src/software_timer.o ./Core/Src/software_timer.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/traffic_light.cyclo ./Core/Src/traffic_light.d ./Core/Src/traffic_light.o ./Core/Src/traffic_light.su ./Core/Src/uart_timer.cyclo ./Core/Src/uart_timer.d ./Core/Src/uart_timer.o ./Core/Src/uart_timer.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

