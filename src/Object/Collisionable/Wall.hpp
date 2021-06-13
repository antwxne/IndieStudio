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
    Wall(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path);
    Wall(const Wall &w) : Wall(w._pos, w._size, std::pair<std::string, std::string> {"", ""}) {}
};

#endif //INDIESTUDIO_WALL_HPP
