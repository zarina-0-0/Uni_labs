cmake_minimum_required(VERSION 3.26)
project(Lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2 main.cpp
        ui.cpp
        test_myptrs.cpp
        heavy_tests.cpp
        heavy_tests.cpp
        ../Lab1/containers_with_myptrs/arrseq_myptrs.h
)