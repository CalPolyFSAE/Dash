file(GLOB_RECURSE MKE_SOURCES startup/*.c startup/*.S board/*.c drivers/*.c utilities/*.c lib/*.c lib/*.cpp)

message("MKE_SOURCES: " ${MKE_SOURCES})

add_subdirectory(rtos)

add_library(mke ${MKE_SOURCES})
target_include_directories(mke PUBLIC CMSIS drivers board utilities lib)
target_link_libraries(mke PUBLIC freertos)

add_subdirectory(middleware)


