cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 23)


add_executable(pattern_001 pattern_001.cpp)
target_compile_options(pattern_001 PRIVATE -Wall -Wextra -pedantic -Wno-enum-compare -Wno-maybe-uninitialized -Wno-uninitialized -Wno-unused-parameter)
target_link_libraries(pattern_001 PUBLIC cvg_svg)

