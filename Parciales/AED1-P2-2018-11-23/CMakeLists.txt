project(AED-P2-2018-11-23)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

file(GLOB TEST_FILES "tests/*.cpp")

add_executable(AED-P2-2018-11-23 main.cpp ${TEST_FILES})

target_link_libraries(AED-P2-2018-11-23 gtest gtest_main)
