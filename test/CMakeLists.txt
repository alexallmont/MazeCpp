cmake_minimum_required(VERSION 2.8)

# Add test executable
add_executable(maze_test test.cpp)
target_link_libraries(maze_test mazelib)
add_test(maze_test maze_test)