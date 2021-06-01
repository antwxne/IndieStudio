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
    DestructibleWall(const std::pair<int, int> &pos, const std::pair<int, int> &size);
    ~DestructibleWall() = default;
};

#endif //INDIESTUDIO_DESTRUCTIBLEWALL_HPP
