file(GLOB_RECURSE SOURCE src/*.c src/*.cpp)

add_executable(dash_app.elf ${SOURCE})
target_include_directories(dash_app.elf PUBLIC include)

target_link_libraries(dash_app.elf mke)

target_link_libraries(dash_app.elf -Wl,--start-group)
target_link_libraries(dash_app.elf debug m)
target_link_libraries(dash_app.elf debug c)
target_link_libraries(dash_app.elf debug gcc)
target_link_libraries(dash_app.elf debug nosys)
target_link_libraries(dash_app.elf optimized m)
target_link_libraries(dash_app.elf optimized c)
target_link_libraries(dash_app.elf optimized gcc)
target_link_libraries(dash_app.elf optimized nosys)
target_link_libraries(dash_app.elf -Wl,--end-group)