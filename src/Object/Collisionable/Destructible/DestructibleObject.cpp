/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "DestructibleObject.hpp"

DestructibleObject::DestructibleObject(const coords &pos,
    const coords &size, const std::pair<std::string, std::string> &path)
    : CollisionableObject(pos, size, path), _life(0)
{
    _typeField.isDestructible = true;
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

const DestructibleObject::destructible_t &DestructibleObject::getStructSave() noexcept
{
    _save.x = _pos.first;
    _save.y = _pos.third;
    _save.life = _life;
    return _save;
}
