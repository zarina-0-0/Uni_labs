cmake_minimum_required(VERSION 3.26)
project(3sem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-g")

#find_package(Catch2 3 REQUIRED)

add_executable(3sem main.cpp
        ptrs/shared.cpp
        ptrs/unique.cpp
        containers_with_myptrs/arrseq_myptrs.cpp
        containers_with_myptrs/darr_myptrs.cpp
        containers_with_myptrs/Sequence_container_interface.h
)
#add_executable(tests
#        tests/test_derived.h
#        ui/ui.cpp
#        ptrs/shared.cpp
#        ptrs/unique.cpp
#        containers_with_myptrs/arrseq_myptrs.cpp
#        containers_with_myptrs/darr_myptrs.cpp
#        containers_with_myptrs/Sequence_container_interface.h)
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)