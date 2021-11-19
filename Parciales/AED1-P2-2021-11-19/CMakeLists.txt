project(AED-P2-2021-11-19)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

file(GLOB SRC_FILES "src/*.cpp")
file(GLOB TEST_FILES "tests/*.cpp")

add_executable(AED-P2-2021-11-19 main.cpp ${SRC_FILES} ${TEST_FILES})

target_link_libraries(AED-P2-2021-11-19 gtest gtest_main)
