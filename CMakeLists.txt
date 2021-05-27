# Cmake version
cmake_minimum_required(VERSION 3.17)

# Project name
project(IndieStudio)

# Variables
set(BINARY_NAME indie)
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(src)
include_directories(src/Raylib)
include_directories(src/Object)

# Paths
set(RAYLIB_PATH src/Raylib)

# Source files
set(RAYLIB_SRCS
    ${RAYLIB_PATH}/Raylib.cpp)

set(INDIE_SRCS
    ${RAYLIB_SRCS})

# Compilation
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/)

find_package(raylib REQUIRED)

add_executable(${BINARY_NAME} Main.cpp ${INDIE_SRCS})

target_compile_features(${BINARY_NAME} PRIVATE cxx_std_17)
target_link_libraries(indie raylib)