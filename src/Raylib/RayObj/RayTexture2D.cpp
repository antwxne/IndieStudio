/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayTexture2D
*/

#include "RayTexture2D.hpp"
#include <string.h>

RayTexture2D::RayTexture2D(std::string filepath) : _texture(LoadTexture(filepath.c_str()))
{
}

RayTexture2D::~RayTexture2D()
{
    UnloadTexture(_texture);
}

void RayTexture2D::draw(IObject &obj)
{
    const std::pair<int, int> pos = obj.getPosition();
    const RGB color = obj.getColors().first;

    DrawTexture(_texture, pos.first, pos.second, {color.r, color.g, color.b, color.a});
}