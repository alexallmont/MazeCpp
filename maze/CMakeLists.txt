cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

# Define maze library and export headers
add_library(mazelib INTERFACE)

target_include_directories(mazelib INTERFACE
  include
)
