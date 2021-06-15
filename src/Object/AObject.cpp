/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/AObject.hpp"

AObject::AObject(const coords &pos, const std::pair<int, int> &size, float scale, const std::pair<RGB, RGB> &colors)
    : _pos(pos), _size(size), _rotation(0), _scale(scale), _color(colors)
{
    _typeField.is3D = false;
}

AObject::AObject(const coords &pos, const std::pair<int, int> &size, float scale)
    : _pos(pos), _size(size), _rotation(0), _scale(scale), _color(std::make_pair(RGB(), RGB()))
{
    _typeField.is3D = false;
}

const coords &AObject::getPosition() const noexcept
{
    return _pos;
}

void AObject::setPosition(coords position) noexcept
{
    _pos = position;
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

void AObject::set3d(bool is3d) noexcept
{
    _typeField.is3D = is3d;
}

void AObject::setSize(std::pair<int, int> size) noexcept
{
    _size = size;
}

const typeField &AObject::getTypeField() const noexcept
{
    return _typeField;
}

const std::pair<RGB, RGB> &AObject::getColors() const noexcept
{
    return _color;
}
float AObject::getRotation() const
{
    return _rotation;
}

void AObject::setRect(bool tmp) noexcept
{
    _typeField.isContourRect = tmp;
}

void AObject::setFillRect(bool tmp) noexcept
{
    _typeField.isFillRect = tmp;
}