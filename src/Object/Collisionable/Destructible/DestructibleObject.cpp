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
    _type_field.is_destructible = true;
    _save.life = _life;
    _save.x = pos.first;
    _save.y = pos.second;
}
float DestructibleObject::getLife() const
{
    return _life;
}
void DestructibleObject::setLife(float life)
{
    _life = life;
    _save.life = _life;
}
void DestructibleObject::updateLife(float life)
{
    _life += life;
    _save.life = _life;
}
bool DestructibleObject::isDestroyed() const
{
    return _life > 0;
}

const DestructibleObject::destructible_t &DestructibleObject::getStructSave() const noexcept
{
    return _save;
}

