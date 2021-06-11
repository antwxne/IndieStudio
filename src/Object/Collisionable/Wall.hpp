/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/CollisionableObject.hpp"

#ifndef INDIESTUDIO_WALL_HPP
#define INDIESTUDIO_WALL_HPP

class Wall: public CollisionableObject {
public:
    Wall(const std::pair<int, int> &pos, const std::pair<int, int> &size);
    Wall(const Wall &w) : Wall(w._pos, w._size) {}
};

#endif //INDIESTUDIO_WALL_HPP
