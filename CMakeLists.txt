# Cmake version
cmake_minimum_required(VERSION 3.17)

# Project name
project(IndieStudio)

# Variables
set(BINARY_NAME bomberman)
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(src)

# Paths
set(RAYLIB_PATH src/Raylib)
set(OBJECT_PATH src/Object)
set(COLLIS_PATH ${OBJECT_PATH}/Collisionable)
set(DESTRUCT_PATH ${COLLIS_PATH}/Destructible)
set(MOVABLE_PATH ${DESTRUCT_PATH}/Movable)
set(SCENE_PATH src/Scene)

# Source files
set(RAYLIB_SRCS
        ${RAYLIB_PATH}/Raylib.cpp)
set(OBJECTS_SRCS
        ${OBJECT_PATH}/IObject.hpp
        ${OBJECT_PATH}/AObject.hpp
        ${OBJECT_PATH}/AObject.cpp
        ${SCENE_PATH}/AScene.cpp
        ${SCENE_PATH}/AScene.hpp
        ${SCENE_PATH}/IScene.hpp
        ${COLLIS_PATH}/CollisionableObject.cpp
        ${COLLIS_PATH}/CollisionableObject.hpp
        ${COLLIS_PATH}/Wall.cpp
        ${COLLIS_PATH}/Wall.hpp
        ${DESTRUCT_PATH}/DestructibleObject.cpp
        ${DESTRUCT_PATH}/DestructibleObject.hpp
        ${DESTRUCT_PATH}/DestructibleWall.cpp
        ${DESTRUCT_PATH}/DestructibleWall.hpp
        ${MOVABLE_PATH}/MovableObject.cpp
        ${MOVABLE_PATH}/MovableObject.hpp
        ${MOVABLE_PATH}/Tank.cpp
        ${MOVABLE_PATH}/Tank.hpp
        ${MOVABLE_PATH}/Cannon.cpp
        ${MOVABLE_PATH}/Cannon.hpp
        ${MOVABLE_PATH}/Bullet.cpp
        ${MOVABLE_PATH}/Bullet.hpp
        )

set(INDIE_SRCS
        ${RAYLIB_SRCS}
        ${OBJECTS_SRCS})

# Compilation
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/)

find_package(raylib REQUIRED)

add_executable(${BINARY_NAME} Main.cpp ${INDIE_SRCS})

target_compile_features(${BINARY_NAME} PRIVATE cxx_std_17)
target_link_libraries(bomberman raylib)