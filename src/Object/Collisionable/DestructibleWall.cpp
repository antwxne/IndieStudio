/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "DestructibleWall.hpp"

DestructibleWall::DestructibleWall(const std::pair<int, int> &pos,
    const std::pair<int, int> &size
) : Wall(pos, size)
{
    _life = 3;
    // changer le sprite
}
