cmake_minimum_required(VERSION 3.13)
project(LinuxProgrammingInterface C)

set(CMAKE_C_STANDARD 99)

#message(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

include_directories(include)

add_library(error_functions SHARED ./include/error_functions.c)
add_library(get_num SHARED ./include/get_num.c)

add_subdirectory(01_FileSystem)