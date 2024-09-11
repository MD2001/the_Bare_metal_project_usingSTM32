################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AFIO_Programe.c \
../Src/EXTI_programe.c \
../Src/GPIO_programe.c \
../Src/LCD_programe.c \
../Src/NVIC_programe.c \
../Src/RCC_programe.c \
../Src/SysTic_Programe.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AFIO_Programe.o \
./Src/EXTI_programe.o \
./Src/GPIO_programe.o \
./Src/LCD_programe.o \
./Src/NVIC_programe.o \
./Src/RCC_programe.o \
./Src/SysTic_Programe.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AFIO_Programe.d \
./Src/EXTI_programe.d \
./Src/GPIO_programe.d \
./Src/LCD_programe.d \
./Src/NVIC_programe.d \
./Src/RCC_programe.d \
./Src/SysTic_Programe.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AFIO_Programe.cyclo ./Src/AFIO_Programe.d ./Src/AFIO_Programe.o ./Src/AFIO_Programe.su ./Src/EXTI_programe.cyclo ./Src/EXTI_programe.d ./Src/EXTI_programe.o ./Src/EXTI_programe.su ./Src/GPIO_programe.cyclo ./Src/GPIO_programe.d ./Src/GPIO_programe.o ./Src/GPIO_programe.su ./Src/LCD_programe.cyclo ./Src/LCD_programe.d ./Src/LCD_programe.o ./Src/LCD_programe.su ./Src/NVIC_programe.cyclo ./Src/NVIC_programe.d ./Src/NVIC_programe.o ./Src/NVIC_programe.su ./Src/RCC_programe.cyclo ./Src/RCC_programe.d ./Src/RCC_programe.o ./Src/RCC_programe.su ./Src/SysTic_Programe.cyclo ./Src/SysTic_Programe.d ./Src/SysTic_Programe.o ./Src/SysTic_Programe.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

