/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/AObject.hpp"

AObject::AObject(const std::pair<int, int> &pos,
    const std::pair<int, int> &size
): _pos(pos), _size(size), _bitmap((0 << OBJECT) | 1), _rotation(0)
{
}
int AObject::getBitMap() const noexcept
{
    return _bitmap;
}
const std::pair<int, int> &AObject::getPosition() const noexcept
{
    return _pos;
}
const std::pair<int, int> &AObject::getSize() const noexcept
{
    return _size;
}
