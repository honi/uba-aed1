project(Labo8)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES
    main.cpp
    src/ejercicios.cpp
    src/ejercicios.h
    src/risas.cpp
    src/risas.h
    tests/risasTEST.cpp
    tests/tests.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Labo8 ${SOURCE_FILES})

target_link_libraries(Labo8 gtest gtest_main)
