cmake_minimum_required(VERSION 3.0.0)
project(design_pattern_cpp VERSION 1.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PATTERNS
        abstract_factory
        adapter
        bridge
        builder
        chain_of_responsibility
        command
        composite
        decorator
        facade
        factory_method
        flyweight
        interpreter
        iterator
        mediator
        memento
        null_object
        object_pool
        observer
        prototype
        proxy
        singleton
        state
        strategy
        template_method
        visitor
        )

foreach (pattern IN ITEMS ${PATTERNS})
    add_executable(${pattern}_example ${pattern}/example/example_${pattern}.cpp)
    target_compile_options(${pattern}_example PRIVATE -Wall)
endforeach ()
