/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "CollisionableObject.hpp"
#include "Raylib/RayObj/RayModel.hpp"

CollisionableObject::CollisionableObject(const std::pair<int, int> &pos,
    const std::pair<int, int> &size
) : AObject(pos, size, 1, std::move(std::make_unique<RayModel>("", "")))
{
    _type_field.is_collisionable = true;
}

bool CollisionableObject::hit(const CollisionableObject &obj) const noexcept
{
    if (this->_pos.first + this->_size.first >= obj._pos.first
    && this->_pos.first <= obj._pos.first + obj._size.first
    && this->_pos.second + this->_size.second >= obj._pos.second
    && this->_pos.second <= obj._pos.second + obj._size.second)
        return true;
    return false;
}