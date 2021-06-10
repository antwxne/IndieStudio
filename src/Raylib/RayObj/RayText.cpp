/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayText
*/

#include "RayText.hpp"

RayText::RayText(std::string text) : _text(text)
{
}

void RayText::draw(IObject &obj)
{
    const std::pair<int, int> pos = obj.getPosition();
    const std::pair<int, int> size = obj.getSize();
    const std::pair<struct RGB, struct RGB> color = obj.getColors();

    DrawText(_text.c_str(), pos.first, pos.second, size.first, {color.first.r, color.first.g, color.first.b, color.first.a});
}
