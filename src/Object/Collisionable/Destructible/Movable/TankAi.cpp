/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cmath>
#include <chrono>
#include <raymath.h>

#include "TankAi.hpp"
#include "Raylib/Raylib.hpp"

TankAI::TankAI(const std::string &name, const coords &pos, const coords &size, const int maxBullets, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : Tank(name, pos, size, maxBullets, path, cannonPath)
{
    _typeField.isIa = true;
    _stopDistance = 2;
}

void TankAI::target(const coords &pos) noexcept
{
    _targetPos = pos;
}

void TankAI::autoMove() noexcept
{
    double distance = TankAI::distance(_targetPos);
    coords dir = _pos - _targetPos;

    rotate(static_cast<double>(atan2(dir.third, dir.first)) * (PI / 180));
    if (distance > _stopDistance) {
        move(dir);
    }
}

double TankAI::distance(const coords &otherPos) const noexcept
{
    return sqrt(pow((_pos.first - otherPos.first),2) + pow((_pos.second - otherPos.second),2));
}

void TankAI::move(const coords &direction) noexcept
{
    coords dir = {0, 0, 0};

    _previousPos = _pos;
    dir.first = direction.first > 0 ? .2f : direction.first < 0 ? -.2f : 0;
    dir.second = direction.second > 0 ? .2f : direction.second < 0 ? -.2f : 0;
    auto tmpDir = dir;
    dir *= _speed * Raylib::getDeltaTime();
    _pos += dir;
    //std::cout << "tmp dir == " << tmpDir.first << " " << tmpDir.third << "\n";
    _cannon.move(tmpDir);
}


void TankAI::rotate(float angle) noexcept
{
    _rotationAngle += angle;
    auto casted = static_cast<int>(_rotationAngle);
    auto moduloed = casted % 360;
    if (moduloed != casted)
        _rotationAngle = moduloed;
    //std::cout << "rotation angle == " << _rotationAngle << "\n";
    _cannon.rotate(angle);
}

void TankAI::fire()
{
        _cannon.fire();

}
