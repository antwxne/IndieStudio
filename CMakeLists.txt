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

# Source files
set(RAYLIB_SRCS
        ${RAYLIB_PATH}/Raylib.cpp)
set(OBJECTS_SRCS
        src/Object/IObject.hpp
        src/Object/AObject.hpp
        src/Object/AObject.cpp
        src/Object/Collisionable/CollisionableObject.cpp
        src/Object/Collisionable/CollisionableObject.hpp
        src/Scene/AScene.cpp src/Scene/AScene.hpp
        src/Scene/IScene.hpp
        src/Object/Collisionable/Destructible/Movable/MovableObject.cpp
        src/Object/Collisionable/Destructible/Movable/MovableObject.hpp
        src/Object/Collisionable/Destructible/DestructibleObject.cpp
        src/Object/Collisionable/Destructible/DestructibleObject.hpp
        src/Object/TypeObject.hpp test.cpp
        src/Object/Collisionable/Wall.cpp
        src/Object/Collisionable/Wall.hpp
        src/Object/Collisionable/Destructible/DestructibleWall.cpp
        src/Object/Collisionable/Destructible/DestructibleWall.hpp
        src/Object/Collisionable/Destructible/Movable/Tank.cpp
        src/Object/Collisionable/Destructible/Movable/Tank.hpp
        src/Object/Collisionable/Destructible/Movable/Cannon.cpp
        src/Object/Collisionable/Destructible/Movable/Cannon.hpp
        src/Object/Collisionable/Destructible/Movable/Bullet.cpp
        src/Object/Collisionable/Destructible/Movable/Bullet.hpp
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