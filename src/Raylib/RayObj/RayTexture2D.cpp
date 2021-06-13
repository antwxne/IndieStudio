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

void RayTexture2D::draw(const std::pair<int, int> &pos, const std::pair<int, int> &size, const float scale, const std::pair<struct RGB, struct RGB> color)
{
    DrawTexture(_texture, pos.first, pos.second, {color.first.r, color.first.g, color.first.b, color.first.a});
}