cmake_minimum_required(VERSION 3.10)
project(mc1d)

# GLOB does what it sounds like - grabs a bunch of something. We use the *
# wildcard to get all of the .cpp files
# ${PROJECT_SOURCE_DIR} is a variable set by cmake. This is the way we access it
# with the ${VARIABLE_NAME} syntax
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
# Headers are designated by directory, so we just need to point it to the
# include folder
include_directories(${PROJECT_SOURCE_DIR}/include)

# Now we use the variable, instead of specifying one .cpp file
add_executable(mc1d ${SOURCES})
