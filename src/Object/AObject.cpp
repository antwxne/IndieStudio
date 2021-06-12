/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cstring>

#include "Object/AObject.hpp"

AObject::AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size, std::unique_ptr<IRayObj> func, bool is3D, float scale) : _pos(pos), _size(size), _rotation(0), _is3D(is3D), _scale(scale)
{
    _drawable = std::move(func);
    std::memset(&_type_field, 0, sizeof(type_field_t));
    _type_field.is_object = true;
}

const std::pair<int, int> &AObject::getPosition() const noexcept
{
    return _pos;
}

const float &AObject::getScale() const noexcept
{
    return _scale;
}

const std::pair<int, int> &AObject::getSize() const noexcept
{
    return _size;
}

void AObject::setScale(float scale) noexcept
{
    _scale = scale;
}

void AObject::setSize(std::pair<int, int> size) noexcept
{
    _size.first = size.first;
    _size.second = size.second;
}

const type_field_t &AObject::getTypeField() const noexcept
{
    return _type_field;
}

const objType_e &AObject::getType() const noexcept
{
    return _type;
}

const std::pair<struct RGB, struct RGB> &AObject::getColors() const noexcept
{
    return _color;
}

const bool AObject::is3D() const noexcept
{
    return (_is3D);
}

const void AObject::funcDraw() noexcept
{
    _drawable->draw(*this);
}
