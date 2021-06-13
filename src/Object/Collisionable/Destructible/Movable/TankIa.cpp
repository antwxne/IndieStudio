/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cmath>
#include <chrono>

#include "TankIa.hpp"

TankIA::TankIA(const std::pair<int, int> &pos, const std::pair<int, int> &size,
    Cannon &cannon
) : Tank(pos, size, cannon)
{
    _type_field.is_ia = true;
    _stopDistance = size.first * 2;
}
void TankIA::target(const std::pair<int, int> &pos) noexcept
{
    _targetPos = pos;
}
void TankIA::autoMove() noexcept
{
    double distance = TankIA::distance(_targetPos);
    std::pair<int, int> dir = _pos - _targetPos;

    rotate(static_cast<double>(atan2(dir.second, dir.first)) * (PI / 180));
    if (distance > _stopDistance) {
        move(_targetPos);
    }
}
double TankIA::distance(const std::pair<int, int> &otherPos) const noexcept
{
    return sqrt(pow((_pos.first - otherPos.first),2) + pow((_pos.second - otherPos.second),2));
}
void TankIA::move(const std::pair<int, int> &direction) noexcept
{
    std::pair dir = {0, 0};

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
