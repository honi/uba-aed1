cmake_minimum_required(VERSION 3.8)
project(tpi)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

file(GLOB DIR_TESTS_EN "test/*.cpp")

set(SOURCE_FILES main.cpp
        auxiliares.cpp
        ejercicios.cpp
        Funciones_TPI.cpp)

add_executable(tpi ${SOURCE_FILES}
        ${DIR_TESTS_EN}
        )

set(CMAKE_CXX_FLAGS "-g --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tpi gtest gtest_main)
