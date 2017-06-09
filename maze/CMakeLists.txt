cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

# Define maze library and export headers
add_library(mazelib STATIC
  src/graph/cell.cpp
  src/graph/grid.cpp
)
target_include_directories(mazelib PUBLIC include)
