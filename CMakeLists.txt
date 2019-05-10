cmake_minimum_required(VERSION 3.13)
project(interpolation_moskanova C)

set(CMAKE_C_STANDARD 99)

include_directories(interpolation_moskanova PUBLIC tests)

add_library(interpolation_moskanova headers/interpolation.h interpolation.c)

add_executable(test tests/test_interpolation.c)

target_include_directories(test PUBLIC headers)