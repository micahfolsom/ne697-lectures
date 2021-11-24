# Basic project setup
cmake_minimum_required(VERSION 3.10)
project(ba133_example)
set(APP_NAME sim)

# C++ options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O2 -Wall -Wextra -Wpedantic")

# Geant4 setup
option(G4_VIS "Build with Geant4 visualization enabled" ON)
if (G4_VIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()
include(${Geant4_USE_FILE})

# clang-format formatting (use "make clang-format" to apply)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(${PROJECT_SOURCE_DIR}/cmake/clang-format.cmake)

# g4-trivial code files
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

# sim app
add_executable(${APP_NAME} ${SOURCES})
target_link_libraries(${APP_NAME} ${Geant4_LIBRARIES})

# Copy scripts directory
add_custom_target(copy-scripts ALL COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${PROJECT_SOURCE_DIR}/scripts ${PROJECT_BINARY_DIR}/scripts
)
