/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Wall.hpp"

Wall::Wall(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path)
    : CollisionableObject(pos, size, path)
{
    _typeField.isWall = true;
    //change sprite
}
