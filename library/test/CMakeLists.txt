cmake_minimum_required(VERSION 3.27)

project(equationSolving)

add_executable(fsdfsdf main.c)

#link main to ../build/libequationSolving.dylib
target_link_libraries(main ${CMAKE_SOURCE_DIR}/../build/libequationSolving.dylib)