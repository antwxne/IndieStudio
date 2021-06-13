/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <raymath.h>

#include "Cannon.hpp"

Cannon::Cannon(const coords &pos, const std::pair<int, int> &size,
    Bullet &bullet)
    : MovableObject(pos, size), _bullet(bullet)
{
    _typeField.isCannon = true;
    //changer le sprite
}
void Cannon::fire()
{
    float angle = _rotation * 180 / PI;

    coords dir = {cos(angle), sin(angle), 0};
    _bullet.move(dir);
}
