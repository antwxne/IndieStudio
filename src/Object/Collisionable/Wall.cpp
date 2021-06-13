/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Wall.hpp"

Wall::Wall(const std::pair<int, int> &pos, const std::pair<int, int> &size)
    : CollisionableObject(pos, size)
{
    _type_field.is_wall = true;
    //change sprite
}
