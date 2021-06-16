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

Tank::Tank(const std::string &name, const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : MovableObject(pos, size, path), _cannon(coords{pos.first, pos.second + 0.2, pos.third}, size, cannonPath), _name(name), _score(0)
{
    _typeField.isTank = true;
    _life = 3;
    _speed = 5;
    _scale = 0.2f;
    _score = 0;
}

Tank::Tank(const Tank &to_copy)
    : MovableObject(to_copy._pos, to_copy._size, to_copy._path), _cannon(to_copy._cannon)
{
    _typeField.isTank = true;
    _life = 10;
    _speed = 5;
    _scale = 0.2f;
    _score = 0;
}

void Tank::fire()
{
    _cannon.fire();
}


Cannon const &Tank::getCannon() const
{
    return _cannon;
}

std::string const &Tank::getName() const
{
    return _name;
}

std::size_t const &Tank::getScore() const
{
    return _score;
}

void Tank::setScore(const std::size_t &score)
{
    _score = score;
}