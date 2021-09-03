cmake_minimum_required(VERSION 3.10)

project(lecture05)

# We can add as many executables as we like. Just need to provide the source
# files for each. They'll both compile when we click build in VSCode or type
# make on the command line
add_executable(operators operators.cpp)
add_executable(arrays arrays.cpp)
