cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_COMPILER_WORKS ON)

option(BUILD_TESTS OFF)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../build/${CMAKE_BUILD_TYPE}/namelesslibc/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../build/${CMAKE_BUILD_TYPE}/namelesslibc/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../build/${CMAKE_BUILD_TYPE}/namelesslibc/bin")
project(namelesslibk C)

set(SOURCES "src/string.c"
            "src/stdlib.c")

add_library(namelesslibk ${SOURCES})

target_compile_options(namelesslibk PRIVATE -Wall -Wextra -ffreestanding -fno-stack-protector -mno-red-zone -fPIC)
target_link_options(namelesslibk PRIVATE -g -nostdlib -fPIC)


if (BUILD_TESTS)
   add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif()