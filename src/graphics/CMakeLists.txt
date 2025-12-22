cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(shapes)

add_library(cvg_graphics
    screen.cpp
    style.cpp
    shape.cpp
    color.cpp
    transform.cpp
    )
target_compile_options(cvg_graphics PRIVATE -Wall -Wextra -pedantic -Wno-enum-compare -Wno-maybe-uninitialized -Wno-uninitialized -Wno-unused-parameter)
target_link_libraries(cvg_graphics PUBLIC cvg_shapes)

add_library(cvg_svg
    svg_visitor.cpp
    )
target_compile_options(cvg_svg PRIVATE -Wall -Wextra -pedantic -Wno-enum-compare -Wno-maybe-uninitialized -Wno-uninitialized -Wno-unused-parameter)
target_link_libraries(cvg_svg PUBLIC cvg_graphics)
