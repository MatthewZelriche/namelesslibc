cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_COMPILER_WORKS ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
project(namelesslibk C)

set(SOURCES "src/string.c")

add_library(namelesslibk ${SOURCES})

target_compile_options(namelesslibk PRIVATE -g -ffreestanding -fno-stack-protector -mno-red-zone -fPIC)
target_link_options(namelesslibk PRIVATE -g -nostdlib -fPIC)