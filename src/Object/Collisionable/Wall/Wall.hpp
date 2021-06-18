/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/CollisionableObject.hpp"

#ifndef INDIESTUDIO_WALL_HPP
#define INDIESTUDIO_WALL_HPP

/**
 * @class Wall
 *
 * @brief class for non destructible wall
 */
class Wall: public CollisionableObject {
public:
    /**
     * @brief Construct a new Wall object
     *
     * @param pos
     * @param size
     * @param path
     */
    Wall(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path);
    /**
     * @brief Construct a new Wall object
     *
     * @param wall to copy
     */
    Wall(const Wall &w) : Wall(w._pos, w._3DSize, std::pair<std::string, std::string> {"asset/OBJFormat/Textures/wall.png", "asset/OBJFormat/wallA.obj"}) {}
};

#endif //INDIESTUDIO_WALL_HPP
