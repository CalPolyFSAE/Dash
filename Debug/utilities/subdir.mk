################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_assert.c \
../utilities/fsl_debug_console.c \
../utilities/fsl_shell.c \
../utilities/fsl_str.c 

OBJS += \
./utilities/fsl_assert.o \
./utilities/fsl_debug_console.o \
./utilities/fsl_shell.o \
./utilities/fsl_str.o 

C_DEPS += \
./utilities/fsl_assert.d \
./utilities/fsl_debug_console.d \
./utilities/fsl_shell.d \
./utilities/fsl_str.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


