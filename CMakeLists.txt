cmake_minimum_required(VERSION 3.15)

project(2020_dash_experimental C CXX ASM)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MAIN_TARGET ${PROJECT_NAME}.elf)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_definitions(
    __STARTUP_CLEAR_BSS
    __STARTUP_INITIALIZE_NONCACHEDATA
    CPU_MKE18F512VLL16
    ARM_MATH_CM4
    __VFP_FP__
)
add_link_options(
    --specs=nano.specs
    --specs=nosys.specs
    -Wall
    -fno-common
    -ffunction-sections
    -fdata-sections
    -ffreestanding
    -fno-builtin
    -mthumb
    -mapcs
    -Xlinker
    --gc-sections
    -Xlinker
    -static
    -Xlinker
    -z
    -Xlinker
    muldefs
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -T${CMAKE_SOURCE_DIR}/ldscript/MKE18F512xxx16_flash.ld
    -static
)

add_compile_options(
    -Wall
    -fno-common
    -ffunction-sections
    -fdata-sections
    -ffreestanding
    -fno-builtin
    -mthumb
    -mapcs
    -fno-rtti
    -fno-exceptions
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -MMD
    -MP
)

if(${CMAKE_BUILD_TYPE} MATCHES Release)
    add_compile_definitions(
        NDEBUG
    )
    add_compile_options(-O3)
ELSEIF(${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_compile_definitions(
        DEBUG
    )
    add_link_options(-g)
    add_compile_options(-g -O0)
ELSEIF(${CMAKE_BUILD_TYPE} MATCHES RelWithDebInfo)
    add_compile_definitions(
        DEBUG
    )
    add_link_options(-g)
    add_compile_options(-g -O3)
ELSEIF(${CMAKE_BUILD_TYPE} MATCHES MinSizeRel)
    add_compile_definitions(
        NDEBUG
    )
    add_compile_options(-O3)
ENDIF()


message("FLAGS CXX DEBUG " ${CMAKE_CXX_FLAGS_DEBUG})
message("FLAGS LINKER DEBUG " ${CMAKE_EXE_LINKER_FLAGS_DEBUG})
message("CMAKE_CXX_FLAGS_DEBUG" ${CMAKE_CXX_FLAGS_DEBUG})

# will output in DEBUG or RELEASE dir under build directory
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})

# sub dirs
add_subdirectory(mke_lib)
add_subdirectory(dash_app)
