cmake_minimum_required(VERSION 3.0.0)
project(design_pattern_cpp VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_COMPILER_IS_GNUCC)
    add_compile_options(-std=c++17 -Wall -Werror)
endif ()

set(PATTERNS
        abstract_factory
        adapter
        bridge
        builder
        composite
        decorator
        facade
        factory_method
        flyweight
        prototype
        singleton
        )

foreach (pattern IN ITEMS ${PATTERNS})
    include(${CMAKE_CURRENT_LIST_DIR}/${pattern}/CMakeLists.txt)
endforeach ()
