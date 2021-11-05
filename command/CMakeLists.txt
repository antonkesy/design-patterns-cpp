cmake_minimum_required(VERSION 3.0.0)

get_filename_component(DesignPatternName ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" DesignPatternName ${DesignPatternName})

add_executable(${DesignPatternName}_example ${CMAKE_CURRENT_LIST_DIR}/example/example_${DesignPatternName}.cpp)