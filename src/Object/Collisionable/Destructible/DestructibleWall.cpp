/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "DestructibleWall.hpp"
#include <iostream>

DestructibleWall::DestructibleWall(const std::pair<int, int> &pos,
    const std::pair<int, int> &size, const std::pair<std::string, std::string> &path)
    : DestructibleObject(pos, size, path)
{
    _life = 3;
}
