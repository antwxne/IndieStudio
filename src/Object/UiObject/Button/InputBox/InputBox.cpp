/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** InputBox
*/

#include "InputBox.hpp"

InputBox::InputBox(const coords &pos, const std::pair<int, int> &size, const std::string &path, int sizeText, float scale, std::pair<RGB, RGB> color)
    : button::Button(pos, size, path, "", sizeText, scale, color)
{
    _typeField.isInputBox = true;
}

InputBox::~InputBox()
{
}

void InputBox::changeText(char input, const std::pair<float, float> &pos)
{
    if (!isInside(pos) || !input || (_text.size() == 15 && input != -1))
        return;
    if (input != -1)
        _text.push_back(input);
    else if (_text.size())
        _text.pop_back();
    _textPos = coords(_pos.first + _size.first / (_text.length() + 1), _pos.second + _size.second / 3);
}