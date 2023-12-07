cmake_minimum_required(VERSION 3.26)
project(3sem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-g")

add_executable(3sem main.cpp
        tests/test_derived.h
        shapes/shapes.h
        shapes/circle.h
        shapes/Square.h
        shapes/circle.cpp
        ui/ui.cpp)
