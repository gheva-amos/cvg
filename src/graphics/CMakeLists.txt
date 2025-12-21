cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 23)

add_library(cvg_graphics
    screen.cpp
    style.cpp
    shape.cpp
    color.cpp
    )
target_compile_options(cvg_graphics PRIVATE -Wall -Wextra -pedantic -Wno-enum-compare -Wno-maybe-uninitialized -Wno-uninitialized -Wno-unused-parameter)

