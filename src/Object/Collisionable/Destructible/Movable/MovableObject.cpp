/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "MovableObject.hpp"

MovableObject::MovableObject(const Type3<float> &pos,
    const std::pair<int, int> &size
) : DestructibleObject(pos, size,std::pair<std::string, std::string> {"", ""}), _speed(0)
{
    _typeField.isMovable = true;
}

void MovableObject::move(const Type3<float> &direction) noexcept
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
