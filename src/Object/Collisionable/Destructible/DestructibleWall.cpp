/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "DestructibleWall.hpp"
#include <iostream>
DestructibleWall::DestructibleWall(const std::pair<int, int> &pos,
    const std::pair<int, int> &size): DestructibleObject(pos, size)
{
    _life = 3;
    _type_field.is_wall;
    // changer le sprite
}
