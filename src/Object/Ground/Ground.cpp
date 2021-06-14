//
// Created by clement on 14/06/2021.
//

#include "Ground.hpp"

Ground::Ground(const coords &pos, const std::pair<int, int> &size,
    const std::pair<std::string, std::string> &path
) : AObject(pos, size, 1)
{
    _typeField.isGround = true;
}