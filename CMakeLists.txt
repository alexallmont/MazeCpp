cmake_minimum_required(VERSION 3.3)

project(MazeCpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

include_directories(include)
include_directories(external)

file(GLOB SOURCES "src/**/*.cpp")
add_executable(maze_test test/main.cpp ${SOURCES})

enable_testing()
add_test(maze_test maze_test)
