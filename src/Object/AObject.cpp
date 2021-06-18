/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/AObject.hpp"

AObject::AObject(const coords &pos, const std::pair<int, int> &size, float scale, const std::pair<RGB, RGB> &colors)
    : _pos(pos), _size(size), _rotationAngle(0.0f), _rotationAxis(coords(0, 0, 0)), _scale(scale), _color(colors)
{
}

AObject::AObject(const coords &pos, const std::pair<int, int> &size, float scale)
    : _pos(pos), _size(size), _rotationAngle(0.0f), _rotationAxis(coords(0, 0, 0)), _scale(scale), _color(std::make_pair(RGB(), RGB()))
{
}

const coords &AObject::getPosition() const noexcept
{
    return _pos;
}

void AObject::setPosition(const coords &position) noexcept
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

const float AObject::getRotationAngle() const noexcept
{
    return _rotationAngle;
}

const coords &AObject::getRotationAxis() const noexcept
{
    return _rotationAxis;
}

void AObject::setColor(const std::pair<RGB, RGB> &color)
{
    _color = color;
}