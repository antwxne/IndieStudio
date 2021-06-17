/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Wall.hpp"

Wall::Wall(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path)
    : CollisionableObject(pos, size, path)
{
    _typeField.isWall = true;
}