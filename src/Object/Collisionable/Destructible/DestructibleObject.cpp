/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "DestructibleObject.hpp"

DestructibleObject::DestructibleObject(const std::pair<int, int> &pos,
    const std::pair<int, int> &size
    ):CollisionableObject(pos, size), _life(0)
{

}
float DestructibleObject::getLife() const
{
    return _life;
}
void DestructibleObject::setLife(float life)
{
    _life = life;
}
void DestructibleObject::updateLife(float life)
{
    _life += life;
}
bool DestructibleObject::isDestroyed() const
{
    return _life > 0;
}

