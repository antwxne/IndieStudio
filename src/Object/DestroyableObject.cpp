/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "DestroyableObject.hpp"

DestroyableObject::DestroyableObject(): _life(0)
{
}
float DestroyableObject::getLife() const
{
    return _life;
}
void DestroyableObject::setLife(float life)
{
    _life = life;
}
void DestroyableObject::updateLife(float life)
{
    _life += life;
}
bool DestroyableObject::isDestroyed() const
{
    return _life > 0;
}

