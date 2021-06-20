/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Wall/Wall.hpp"
#include "Object/Collisionable/Destructible/DestructibleObject.hpp"

#ifndef INDIESTUDIO_DESTRUCTIBLEWALL_HPP
#define INDIESTUDIO_DESTRUCTIBLEWALL_HPP

/**
 * @class DestructibleWall
 *
 * @brief Wall collisionable and destructible
 */
class DestructibleWall: public DestructibleObject {
public:
    /**
     * @brief Construct a new Destructible Wall object
     *
     * @param pos
     * @param size
     * @param path
     */
    DestructibleWall(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path);
    /**
     * @brief Construct a new Destructible Wall object
     *
     * @param object to copy
     */
    DestructibleWall(const DestructibleWall &e) : DestructibleWall(e._pos, e._3DSize, std::pair<std::string, std::string>{"asset/OBJFormat/Textures/truck_alien.png", "asset/OBJFormat/truck_green.obj"}) {}
    /**
     *
     * @brief Destroy the Destructible Wall object
     *
     */
    ~DestructibleWall() = default;
};

#endif //INDIESTUDIO_DESTRUCTIBLEWALL_HPP
