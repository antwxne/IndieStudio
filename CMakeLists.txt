SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/cmake_modules/)
FIND_PACKAGE(raylib REQUIRED)
cmake_minimum_required(VERSION 3.12)
project(indiestudio VERSION 1.0.0)
SET(CMAKE_CXX_STANDARD 17)

add_executable(indie main.cpp)
target_link_libraries(indie raylib)
