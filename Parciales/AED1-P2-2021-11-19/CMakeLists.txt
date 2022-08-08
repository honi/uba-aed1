project(AED-P2-2021-11-19)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

add_executable(ej1 src/main.cpp tests/ej1_test.cpp)
target_link_libraries(ej1 gtest gtest_main)

add_executable(ej2 src/main.cpp tests/ej2_test.cpp)
target_link_libraries(ej2 gtest gtest_main)

add_executable(ej3 src/main.cpp tests/ej3_test.cpp)
target_link_libraries(ej3 gtest gtest_main)

add_executable(ej4 src/main.cpp tests/ej4_test.cpp)
target_link_libraries(ej4 gtest gtest_main)
