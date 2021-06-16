/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Button
*/

#include "Button.hpp"

namespace button {

    Button::Button(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color)
        : UiObject(pos, size, path[0], scale, color), _text(text), _textSize(sizeText * scale), _textPos(pos.first + size.first / (text.length() + 1), pos.second + size.second / 3), _texturePath(path)
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

    const int Button::getTextSize() const noexcept
    {
        return (_textSize);
    }

    bool Button::isInside(const std::pair<float, float> &pos) const
    {
        return ((_pos.first <= pos.first && pos.first <= _pos.first + _size.first * _scale) &&
                (_pos.second <= pos.second && pos.second <= _pos.second + _size.second * _scale));
    }

    void Button::setState(const std::pair<float, float> &pos, bool clicked)
    {
        if (isInside(pos)) {
            setTexture(clicked ? _texturePath.at(buttonState_e::CLICKED) : _texturePath.at(buttonState_e::OVER));
        } else {
            setTexture(_texturePath.at(buttonState_e::NOTHING));
        }
    }

    const coords Button::getTextPos() const noexcept
    {
        return (_textPos);
    }

}