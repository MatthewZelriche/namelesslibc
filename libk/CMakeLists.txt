cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_COMPILER_WORKS ON)

option(BUILD_TESTS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../build/${CMAKE_BUILD_TYPE}/namelesslibc/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../build/${CMAKE_BUILD_TYPE}/namelesslibc/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../build/${CMAKE_BUILD_TYPE}/namelesslibc/bin")
project(namelesslibk C)

set(SOURCES "src/string.c"
            "src/stdlib.c"
            "src/ctype.c")

add_library(namelesslibkfortesting SHARED ${SOURCES})
add_library(namelesslibk ${SOURCES})

target_compile_options(namelesslibkfortesting PRIVATE -Wall -Wextra -ffreestanding -fno-stack-protector -mno-red-zone  -Werror-implicit-function-declaration)
target_link_options(namelesslibkfortesting PRIVATE -g -nostdlib)

target_compile_options(namelesslibk PRIVATE -Wall -Wextra -ffreestanding -fno-stack-protector -mno-red-zone  -Werror-implicit-function-declaration)
target_link_options(namelesslibk PRIVATE -g -nostdlib)


if (BUILD_TESTS)
   add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif()