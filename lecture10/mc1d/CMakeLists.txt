cmake_minimum_required(VERSION 3.10)
project(mc1d)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(mc1d ${SOURCES})
