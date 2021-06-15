/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Tank.hpp"
#include <functional>

const std::string Tank::sandCamo = "asset/Tank/sand_camo.png";
const std::string Tank::greenCamo = "asset/Tank/green_camo.png";
const std::string Tank::body = "asset/Tank/tankBodyNEW.obj";
const std::string Tank::turret = "asset/Tank/turretWithCannonNEW.obj";

Tank::Tank(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : MovableObject(pos, size, path), _cannon(coords{pos.first, pos.second + 0.2, pos.third}, size, cannonPath)
{
    _typeField.isTank = true;
    _life = 10;
    _speed = 5;
    _scale = 0.2f;
}

Tank::Tank(const Tank &to_copy)
    : MovableObject(to_copy._pos, to_copy._size, to_copy._path), _cannon(to_copy._cannon)
{
    _typeField.isTank = true;
    _life = 10;
    _speed = 5;
    _scale = 0.2f;
}

void Tank::fire()
{
    _cannon.fire();
}


Cannon const &Tank::getCannon() const
{
    return _cannon;
}