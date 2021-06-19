/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "DestructibleWall.hpp"
#include <iostream>

DestructibleWall::DestructibleWall(const coords &pos,
    const coords &size, const std::pair<std::string, std::string> &path)
    : DestructibleObject(pos, size, path)
{
    _life = 1;
    _typeField.isDestructibleWall = true;
    _rotationAngle = 90.0f;
    _rotationAxis = {0, 1, 0};
}
