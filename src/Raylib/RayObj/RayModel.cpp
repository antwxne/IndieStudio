/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayModel
*/

#include "RayModel.hpp"

RayModel::RayModel(std::string textureFilepath, std::string modelFilepath) : _texture(LoadTexture(textureFilepath.c_str())), _model(LoadModel(modelFilepath.c_str()))
{
    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, _texture);
}

RayModel::~RayModel()
{
    UnloadTexture(_texture);
    UnloadModel(_model);
}

void RayModel::draw(IObject &obj)
{
    const std::pair<int, int> pos = obj.getPosition();
    float a = (float) pos.first;
    float b = (float) pos.second;
    const float scale = obj.getScale();
    const std::pair<struct RGB, struct RGB> color = obj.getColors();
    std::cout << "[3D] je print un Model" << "\npos => " << a << ":" << b << "\nScale " << scale << '\n';

    DrawModel(_model, {a, b, 0}, scale/50, WHITE);
}