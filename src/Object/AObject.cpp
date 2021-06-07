/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cstring>

#include "Object/AObject.hpp"

AObject::AObject(const std::pair<int, int> &pos,
    const std::pair<int, int> &size
): _pos(pos), _size(size), _rotation(0)
{
    std::memset(&_type_field, 0, sizeof(type_field_t));
    _type_field.is_object = true;
}

const std::pair<int, int> &AObject::getPosition() const noexcept
{
    return _pos;
}
const std::pair<int, int> &AObject::getSize() const noexcept
{
    return _size;
}
const type_field_t &AObject::getTypeField() const noexcept
{
    return _type_field;
}
