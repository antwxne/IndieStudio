/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Tank.hpp"

Tank::Tank(const std::pair<int, int> &pos, const std::pair<int, int> &size)
    : MovableObject(pos, size)
{
    _life = 10;
    //changer le sprite
}
