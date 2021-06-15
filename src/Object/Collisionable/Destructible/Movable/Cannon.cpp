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
    _scale = 0.2f;
}

Cannon::Cannon(const Cannon &to_copy) : MovableObject(to_copy._pos, to_copy._size, to_copy._path)
{
    _typeField.isCannon = true;
    _scale = 0.2f;
}

void Cannon::fire()
{
    // float angle = _rotation * 180 / PI;

    // coords dir = {cos(angle), sin(angle), 0};
    // _bullet.move(dir);
}
