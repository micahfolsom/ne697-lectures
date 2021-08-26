# Comment lines in CMake start with the #
# This line is required. Run "cmake --version" in a terminal to see which
# version you have (I have 3.16 on Ubuntu 20.04)
cmake_minimum_required(VERSION 3.10)

# Every project needs a name!
project(hello_app)

# Create an executable "target" named hello, which takes a list of source (.cpp)
# file paths
add_executable(hello hello.cpp)
