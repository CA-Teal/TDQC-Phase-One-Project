cmake_minimum_required(VERSION 3.20)
project(tdqc_phase_one C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(deps)
add_subdirectory(src)
add_subdirectory(tests)