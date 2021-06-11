/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaySquare
*/

#include "RaySquare.hpp"

RaySquare::RaySquare()
{
}

void RaySquare::draw(IObject &obj)
{
    const std::pair<int, int> pos = obj.getPosition();
    const std::pair<int, int> size = obj.getSize();
    const std::pair<struct RGB, struct RGB> color = obj.getColors();
    const objType_e type = obj.getType();

    if (type == BASIC)
        DrawRectangle(pos.first, pos.second, size.first, size.second, {color.first.r, color.first.g, color.first.b, color.first.a});
    else if (type == GRADIENT)
        DrawRectangleGradientH(pos.first, pos.second, size.first, size.second, {color.first.r, color.first.g, color.first.b, color.first.a}, {color.second.r, color.second.g, color.second.b, color.second.a});
    else if (type == LINES)
        DrawRectangleLines(pos.first, pos.second, size.first, size.second, {color.first.r, color.first.g, color.first.b, color.first.a});
    else
        std::cout << "[-] Unknow Rectangle Type, valid are Basic, Gradient, Lines" << '\n';
}