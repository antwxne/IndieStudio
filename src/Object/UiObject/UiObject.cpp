/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** UiObject
*/

#include "UiObject.hpp"

UiObject::UiObject(const coords &pos, const std::pair<int, int> &size, const std::string &texture, float scale, std::pair<RGB, RGB> const &color)
    : AObject(pos, size, scale, color), _texture(texture)
{
}

UiObject::UiObject(const coords &pos, const std::pair<int, int> &size, const std::string &texture, float scale)
    : AObject(pos, size, scale), _texture(texture)
{
}

UiObject::~UiObject()
{
}

void UiObject::setTexture(const std::string &newTexture) noexcept
{
    _texture = newTexture;
}

const std::string UiObject::getTexture() const noexcept
{
    return (_texture);
}

void UiObject::setRect(bool tmp) noexcept
{
    _typeField.isRect = tmp;
}
