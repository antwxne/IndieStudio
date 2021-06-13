/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Wall.hpp"

Wall::Wall(const std::pair<int, int> &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path)
    : CollisionableObject(pos, size, path)
{
    //change sprite
}
