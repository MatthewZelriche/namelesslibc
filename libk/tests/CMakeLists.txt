cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_COMPILER_WORKS ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
project(namelesslibk_tests C)

set(SOURCES "main.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Vendor/unity/src/unity.c")

add_executable(namelesslibk_tests ${SOURCES})

target_compile_options(namelesslibk_tests PRIVATE -g -fno-stack-protector -mno-red-zone -fPIC)
target_link_options(namelesslibk_tests PRIVATE -g -fPIC)
target_include_directories(namelesslibk_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../Vendor/unity/src/")