/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cmath>
#include <numeric>

#include "TankAi.hpp"
#include "Raylib/Raylib.hpp"

coords &operator-(coords &a)
{
    a.first *= -1;
    a.second *= -1;
    a.third *= -1;
    return a;
}

std::ostream &operator<<(std::ostream &os, const coords &a)
{
    os << a.first << " " << a.second << " " << a.third;
    return os;
}

TankAI::TankAI(const std::string &name, const coords &pos, const coords &size, const int maxBullets, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : Tank(name, pos, size, maxBullets, path, cannonPath)
{
    _typeField.isIa = true;
    _stopDistance = 2;
    _prevRotationAngle = _rotationAngle;
}

void TankAI::target(const coords &pos) noexcept
{
    _targetPos = pos;
}

void TankAI::autoMove() noexcept
{
    double distance = TankAI::distance(_targetPos);
    coords dir = _targetPos - _pos;
    float doRotation = std::sin(_rotationAngle) * (_pos.first - _targetPos.first) + (-std::cos(_rotationAngle)) * (_pos.second - _targetPos.second);

    rotate(1);
    //std::cout << "do rotation == " << doRotation << "\n";
    if (distance > _stopDistance) {
        move(dir);
    }
}

double TankAI::distance(const coords &otherPos) const noexcept
{
    return sqrt(pow((_pos.first - otherPos.first),2) + pow((_pos.third - otherPos.third),2));
}

void TankAI::move(const coords &direction) noexcept
{
    coords dir = {0, 0, 0};

    _previousPos = _pos;
    dir.first = direction.first > 0 ? .2f : direction.first < 0 ? -.2f : 0;
    dir.third = direction.third > 0 ? .2f : direction.third < 0 ? -.2f : 0;
    auto tmpDir = dir;
    dir *= _speed * Raylib::getDeltaTime();
    _pos += dir;
    _cannon.move(tmpDir);
}


void TankAI::rotate(float angle) noexcept
{
    float doRotation = std::sin(_rotationAngle) * (_pos.first - _targetPos.first) + (-std::cos(_rotationAngle)) * (_pos.second - _targetPos.second);

//    std::cout << "rotate pos ai == " << _pos << std::endl;
//    std::cout << "rotate pos target == " << _targetPos << std::endl;
//    //std::cout << "do rotation == " << doRotation << "\n";
    _prevRotationAngle = _rotationAngle;
    _rotationAngle += doRotation > 0 ? angle : -angle;
    _rotationAngle = static_cast<int>(_rotationAngle) % 360;
    _cannon.rotate(doRotation > 0 ? angle : -angle);
}

void TankAI::fire()
{
    _cannon.fire();
}
