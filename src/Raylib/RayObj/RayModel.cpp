/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayModel
*/

#include "RayModel.hpp"

RayModel::RayModel()
{
}

RayModel::~RayModel()
{
}

void RayModel::setTexture(std::string const &path)
{
    _texture = LoadTexture(path.c_str());
}

void RayModel::setModel(std::string const &path)
{
    _model = LoadModel(path.c_str());
}

void RayModel::setTextureToModel()
{
    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, _texture);
}

void RayModel::draw(IObject &obj)
{
    const std::pair<int, int> pos = obj.getPosition();
    float a = (float) pos.first;
    float b = (float) pos.second;
    const float scale = obj.getScale();
    const std::pair<struct RGB, struct RGB> color = obj.getColors();

    DrawModel(_model, {a, b, 0}, scale, {color.first.r, color.first.g, color.first.b, color.first.a});
}