cmake_minimum_required(VERSION 2.8)

project(MazeCpp)

add_definitions(-std=c++11)

enable_testing()

add_executable(tests tests/main.cpp)
add_test(tests tests)
