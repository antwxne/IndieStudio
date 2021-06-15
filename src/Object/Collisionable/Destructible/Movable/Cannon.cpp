/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <raymath.h>

#include "Cannon.hpp"

Cannon::Cannon(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path)
    : MovableObject(pos, size, path)
{
    _typeField.isCannon = true;
    //changer le sprite
}
void Cannon::fire()
{
    // float angle = _rotation * 180 / PI;

    // coords dir = {cos(angle), sin(angle), 0};
    // _bullet.move(dir);
}
