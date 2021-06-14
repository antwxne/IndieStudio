/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(const coords &pos, const std::pair<int, int> &size, const std::string &path, const std::string &text, float scale, std::pair<RGB, RGB> color)
    : UiObject(pos, size, path, scale, color), _text(text), _state(buttonState_e::NOTHING), _textPos(pos.first + 10, pos.second + 10)
{
    _typeField.isButton = true;
}

Button::~Button()
{
}

void Button::setText(const std::string &newText) noexcept
{
    _text = newText;
}

const std::string Button::getText() const noexcept
{
    return (_text);
}

bool Button::isInside(const std::pair<float, float> &pos) const
{
    return ((_pos.first <= pos.first && pos.first <= _pos.first + _size.first) &&
            (_pos.second <= pos.second && pos.second <= _pos.second + _size.second));
}

const coords Button::getTextPos() const noexcept
{
    return (_textPos);
}
