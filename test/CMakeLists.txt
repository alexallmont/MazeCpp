cmake_minimum_required(VERSION 2.8)

# TODO include boost as library and get boost as external
include_directories(../external)

# Add test executable
add_executable(maze_test test.cpp)
target_link_libraries(maze_test mazelib)
add_test(maze_test maze_test)

# Launch tests after each make
add_custom_command(
  TARGET maze_test
  POST_BUILD
  COMMAND ctest --output-on-failure
)
