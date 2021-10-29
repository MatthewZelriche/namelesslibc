cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_COMPILER_WORKS ON)

project(namelesslibk_tests C)

set(SOURCES "main.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Vendor/unity/src/unity.c")

add_executable(namelesslibk_tests ${SOURCES})

target_compile_options(namelesslibk_tests PRIVATE -g -Wall -fno-builtin -Wextra -fno-stack-protector -mno-red-zone -fPIC -Werror-implicit-function-declaration)
target_link_options(namelesslibk_tests PRIVATE -g)
target_link_libraries(namelesslibk_tests "${CMAKE_CURRENT_SOURCE_DIR}/../../build/Release/namelesslibc/bin/libnamelesslibkfortesting.so" dl)
target_include_directories(namelesslibk_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../Vendor/unity/src/")