/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayModel
*/

#include "RayModel.hpp"

RayModel::RayModel(const std::string &texture, const std::string &model) : _isSet(false)
{
    //std::cout << "JE PASSE DANS LE CONSTRUCTEUR" << "\n";
    if (!texture.empty())
        _texture = LoadTexture(texture.c_str());
    if (!model.empty())
        _model = LoadModel(model.c_str());
}

RayModel::~RayModel()
{
    UnloadTexture(_texture);
    UnloadModel(_model);
}

const void RayModel::setModel(std::string const &Filepath) {
    _model = LoadModel(Filepath.c_str());
}

const void RayModel::setTexture(std::string const &Filepath) {
    _texture = LoadTexture(Filepath.c_str());
}

void RayModel::draw(const std::pair<int, int> &pos, const std::pair<int, int> &size, const float scale, const std::pair<struct RGB, struct RGB> color)
{
    float a = (float) pos.first;
    float b = (float) pos.second;
    //std::cout << "[3D] je print un Model" << "\npos => " << a << ":" << b << "\nScale " << scale << '\n';
    if (!_isSet) {
        SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, _texture);
        _isSet = true;
    }
    DrawModel(_model, {a, b, 0}, scale, WHITE);
}