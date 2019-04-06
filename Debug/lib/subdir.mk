################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/mugetronblue/Documents/MKELibrary/lib/adc.cpp \
/Users/mugetronblue/Documents/MKELibrary/lib/candrv.cpp \
/Users/mugetronblue/Documents/MKELibrary/lib/canlight.cpp \
/Users/mugetronblue/Documents/MKELibrary/lib/gpio.cpp \
/Users/mugetronblue/Documents/MKELibrary/lib/lpit.cpp \
/Users/mugetronblue/Documents/MKELibrary/lib/spi.cpp 

OBJS += \
./lib/adc.o \
./lib/candrv.o \
./lib/canlight.o \
./lib/gpio.o \
./lib/lpit.o \
./lib/spi.o 

CPP_DEPS += \
./lib/adc.d \
./lib/candrv.d \
./lib/canlight.d \
./lib/gpio.d \
./lib/lpit.d \
./lib/spi.d 


# Each subdirectory must supply rules for building sources it contributes
lib/adc.o: /Users/mugetronblue/Documents/MKELibrary/lib/adc.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/candrv.o: /Users/mugetronblue/Documents/MKELibrary/lib/candrv.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/canlight.o: /Users/mugetronblue/Documents/MKELibrary/lib/canlight.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/gpio.o: /Users/mugetronblue/Documents/MKELibrary/lib/gpio.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/lpit.o: /Users/mugetronblue/Documents/MKELibrary/lib/lpit.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/spi.o: /Users/mugetronblue/Documents/MKELibrary/lib/spi.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../utilities -I../utilities/utilities -I../component/lists -I../component/uart -I/Users/mugetronblue/Documents/MKELibrary/lib -I/Users/mugetronblue/Documents/MKELibrary -I/Users/mugetronblue/Documents/MKELibrary/System -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


