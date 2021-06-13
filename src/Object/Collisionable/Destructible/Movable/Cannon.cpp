/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <raymath.h>

#include "Cannon.hpp"

Cannon::Cannon(const std::pair<int, int> &pos, const std::pair<int, int> &size,
    Bullet &bullet)
    : MovableObject(pos, size), _bullet(bullet)
{
    _typeField.isCannon = true;
    //changer le sprite
}
void Cannon::fire()
{
    double angle = _rotation * 180 / PI;
    std::pair<int, int> dir = {cos(angle), sin(angle)};
    _bullet.move(dir);
}
