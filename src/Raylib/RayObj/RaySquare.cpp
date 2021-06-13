/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaySquare
*/

#include "RaySquare.hpp"

RaySquare::RaySquare(objType_e type) : _type(type)
{
}

void RaySquare::draw(const std::pair<int, int> &pos, const std::pair<int, int> &size, const float scale, const std::pair<struct RGB, struct RGB> color)
{
    if (_type == BASIC)
        DrawRectangle(pos.first, pos.second, size.first, size.second, {color.first.r, color.first.g, color.first.b, color.first.a});
    else if (_type == GRADIENT)
        DrawRectangleGradientH(pos.first, pos.second, size.first, size.second, {color.first.r, color.first.g, color.first.b, color.first.a}, {color.second.r, color.second.g, color.second.b, color.second.a});
    else if (_type == LINES)
        DrawRectangleLines(pos.first, pos.second, size.first, size.second, {color.first.r, color.first.g, color.first.b, color.first.a});
    else if (_type == WIRES) {
        Rectangle rec = {30, 30, (int) size.first, (int) size.second };
        DrawRectangleRoundedLines(rec, 0.2f, 0, 1, Fade({color.second.r, color.second.g, color.second.b, color.second.a}, 0.4));
    }
    else
        std::cout << "[-] Unknow Rectangle Type, valid are Basic, Gradient, Lines" << '\n';
}