//
// Created by clement on 14/06/2021.
//

#include "Ground.hpp"

Ground::Ground(const coords &pos, const std::pair<int, int> &size,
    const std::pair<std::string, std::string> &path)
: AObject(pos, size, 1.0f), _path(path)
{
    _typeField.isGround = true;
    _typeField.is3D = true;
}

const std::string &Ground::getTexture() const noexcept
{
    return _path.first;
}

const std::string &Ground::getModel() const noexcept
{
    return _path.second;
}