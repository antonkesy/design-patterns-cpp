cmake_minimum_required(VERSION 3.0.0)
project(design_pattern_cpp VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_COMPILER_IS_GNUCC)
    add_compile_options(-std=c++11 -Wall -Werror -fsanitize=leak)
endif ()

include(${CMAKE_CURRENT_SOURCE_DIR}/singleton/CMakeLists.txt)