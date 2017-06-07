cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

# Add the demo application using maze library
add_subdirectory(maze)
add_executable(demo demo.cpp)
target_link_libraries(demo mazelib)

# Add unit testing
enable_testing()
add_subdirectory(test)
