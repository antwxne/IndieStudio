/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cmath>
#include <raymath.h>

#include "TankIa.hpp"

TankIA::TankIA(const Type3<float> &pos, const std::pair<int, int> &size,
    Cannon &cannon
) : Tank(pos, size, cannon)
{
    _typeField.isIa = true;
    _stopDistance = size.first * 2;
}
void TankIA::target(const Type3<float> &pos) noexcept
{
    _targetPos = pos;
}
void TankIA::autoMove() noexcept
{
    double distance = TankIA::distance(_targetPos);
    Type3<float> dir = _pos - _targetPos;

    rotate(static_cast<double>(atan2(dir.second, dir.first)) * (PI / 180));
    if (distance > _stopDistance) {
        move(_targetPos);
    }
}
double TankIA::distance(const Type3<float> &otherPos) const noexcept
{
    return sqrt(pow((_pos.first - otherPos.first),2) + pow((_pos.second - otherPos.second),2));
}
void TankIA::move(const Type3<float> &direction) noexcept
{
    Type3<float> dir = {0, 0, 0};

    dir.first = direction.first > 0 ? 1 : direction.first < 0 ? -1 : 0;
    dir.second = direction.second > 0 ? 1 : direction.second< 0 ? -1 : 0;
    _pos += dir;
}
void TankIA::rotate(float angle) noexcept
{
    _rotation = angle;
}

void TankIA::setBlocked(bool blocked)
{
    _blocked = blocked;
}
