/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cstring>

#include "Object/AObject.hpp"

AObject::AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size, float scale, const std::pair<RGB, RGB> &colors, std::unique_ptr<IRayObj> &&func)
    : _pos(pos), _size(size), _rotation(0), _scale(scale), _color(colors), _drawable(std::move(func))
{
    _type_field.is_object = true;
    _type_field.is_3D = false;
}

AObject::AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size, float scale, std::unique_ptr<IRayObj> &&func)
    : _pos(pos), _size(size), _rotation(0), _scale(scale), _color(std::make_pair(RGB(), RGB())), _drawable(std::move(func))
{
    _type_field.is_object = true;
    _type_field.is_3D = false;
}

const std::pair<int, int> &AObject::getPosition() const noexcept
{
    return _pos;
}

void AObject::setPosition(std::pair<int, int> position) noexcept
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
    _type_field.is_3D = is3d;
}

void AObject::setSize(std::pair<int, int> size) noexcept
{
    _size = size;
}

void AObject::setDrawable(std::unique_ptr<IRayObj> &&funct) noexcept
{
    _drawable = std::move(funct);
}

const type_field_t &AObject::getTypeField() const noexcept
{
    return _type_field;
}

const std::pair<RGB, RGB> &AObject::getColors() const noexcept
{
    return _color;
}

const void AObject::funcDraw() noexcept
{
    _drawable->draw(getPosition(), getSize(), getScale(), getColors());
}
