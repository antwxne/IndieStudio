/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "CollisionableObject.hpp"
#include "Raylib/RayObj/RayModel.hpp"

CollisionableObject::CollisionableObject(const std::pair<int, int> &pos,
    const std::pair<int, int> &size, const std::pair<std::string, std::string> &path
) : AObject(pos, size, 1, std::move(std::make_unique<RayModel>(path.first, path.second)))
{
    _path = path;
    _type_field.is_collisionable = true;
}

void CollisionableObject::setTexture(const std::string &texture) noexcept
{
    std::cout << "[COLLISIONABLE] Set Texture" << '\n';
    _texturePath = texture;
}

void CollisionableObject::setModel(const std::string &texture) noexcept
{
    std::cout << "[COLLISIONABLE] Set Model" << '\n';
    _modelPath = texture;
}

const std::string &CollisionableObject::getTexture() const noexcept
{
    return _texturePath;
}

const std::string &CollisionableObject::getModel() const noexcept
{
    return _modelPath;
}

bool CollisionableObject::hit(const CollisionableObject &) const noexcept
{
    return false;
}