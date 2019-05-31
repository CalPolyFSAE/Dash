################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/CAN.cpp \
../source/DashB.cpp \
../source/Gears.cpp \
../source/LCD.cpp \
../source/WarningLEDs.cpp 

C_SRCS += \
../source/semihost_hardfault.c 

OBJS += \
./source/CAN.o \
./source/DashB.o \
./source/Gears.o \
./source/LCD.o \
./source/WarningLEDs.o \
./source/semihost_hardfault.o 

CPP_DEPS += \
./source/CAN.d \
./source/DashB.d \
./source/Gears.d \
./source/LCD.d \
./source/WarningLEDs.d 

C_DEPS += \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


