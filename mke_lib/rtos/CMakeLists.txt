set(FREERTOS_ROOT amazon-freertos)
set(FREERTOS_INCLUDE ${FREERTOS_ROOT}/lib/include)

file(GLOB_RECURSE RTOS_SOURCE ${FREERTOS_ROOT}/lib/FreeRTOS/*.c)

message("RTOS SOURCE: " ${RTOS_SOURCE})

add_library(freertos ${RTOS_SOURCE})

target_include_directories(freertos PUBLIC 
    .
    ${FREERTOS_INCLUDE}
    ${FREERTOS_INCLUDE}/private
    ${FREERTOS_INCLUDE}/FreeRTOS_POISX
    ${FREERTOS_INCLUDE}/FreeRTOS_POISX/sys
    ${FREERTOS_ROOT}/lib/FreeRTOS/portable/GCC/ARM_CM4F
)