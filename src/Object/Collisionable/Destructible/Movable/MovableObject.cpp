/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "MovableObject.hpp"

MovableObject::MovableObject(const std::pair<int, int> &pos,
    const std::pair<int, int> &size
) : DestructibleObject(pos, size), _speed(0)
{
}

void MovableObject::move(const std::pair<int, int> &direction) noexcept
{
    _pos += direction;
}
void MovableObject::rotate(float angle) noexcept
{
    _rotation += angle;
}
void MovableObject::changeSpeed(float newSpeed)
{
    _speed += newSpeed;
}
