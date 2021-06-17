/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Tank.hpp"
#include "Raylib.hpp"
#include <functional>

const std::string Tank::sandCamo = "asset/Tank/sand_camo.png";
const std::string Tank::greenCamo = "asset/Tank/green_camo.png";
const std::string Tank::body = "asset/Tank/tankBodyNEW.obj";
const std::string Tank::turret = "asset/Tank/turretWithCannonNEW.obj";

Tank::Tank(const std::string &name, const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : MovableObject(pos, size, path), _cannon(coords{pos.first, pos.second + 0.15f, pos.third}, size, cannonPath), _name(name), _score(0)
{
    _typeField.isTank = true;
    _life = 10;
    _scale = 0.2f;
    _rotationAngle = 0.0f;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
}

void Tank::fire()
{
    _cannon.fire();
}

void Tank::move(const coords &direction) noexcept
{
    auto tmp = direction;
    tmp *= _speed * Raylib::getDeltaTime();
    _pos += tmp;
    _cannon.move(direction);
}

void Tank::rotateCannon(float angle)
{
    _cannon.rotate(angle);
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