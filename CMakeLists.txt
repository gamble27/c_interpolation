cmake_minimum_required(VERSION 3.13)
project(interpolation_moskanova C)

set(CMAKE_C_STANDARD 99)

include_directories(BEFORE headers)
include_directories(BEFORE tests)

add_library(interpolation STATIC headers/interpolation.h interpolation.c)

add_executable(test tests/test_interpolation.c)

#target_link_directories(test headers)
target_link_libraries(test interpolation)
target_include_directories(test BEFORE PUBLIC headers)