cmake_minimum_required(VERSION 3.26)
project(Lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2 main.cpp
        ../Lab1/containers_with_myptrs/Sequence_container_interface.h
        ../Lab1/containers_with_myptrs/arrseq_myptrs.cpp
        ../Lab1/containers_with_myptrs/darr_myptrs.cpp
)
