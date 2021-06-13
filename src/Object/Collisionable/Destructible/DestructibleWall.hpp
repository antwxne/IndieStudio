/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Wall.hpp"
#include "Object/Collisionable/Destructible/DestructibleObject.hpp"

#ifndef INDIESTUDIO_DESTRUCTIBLEWALL_HPP
#define INDIESTUDIO_DESTRUCTIBLEWALL_HPP

class DestructibleWall: public DestructibleObject {
public:
    DestructibleWall(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path);
    DestructibleWall(const DestructibleWall &e) : DestructibleWall(e._pos, e._size, std::pair<std::string, std::string>{0, 0}) {}
    ~DestructibleWall() = default;
};

#endif //INDIESTUDIO_DESTRUCTIBLEWALL_HPP
