file(GLOB_RECURSE SOURCES source/*.c)

add_library(fatfs ${SOURCES})
target_include_directories(fatfs PUBLIC source source/fsl_nand_disk source/fsl_ram_disk)
target_link_libraries(fatfs freertos mke)