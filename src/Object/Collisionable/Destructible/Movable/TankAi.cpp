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

TankAI::TankAI(const std::pair<int, int> &pos, const std::pair<int, int> &size,
    Cannon &cannon
) : Tank(pos, size, cannon)
{
    _typeField.isIa = true;
    _stopDistance = size.first * 2;
}
void TankAI::target(const std::pair<int, int> &pos) noexcept
{
    _targetPos = pos;
}
void TankAI::autoMove() noexcept
{
    double distance = TankAI::distance(_targetPos);
    std::pair<int, int> dir = _pos - _targetPos;

    rotate(static_cast<double>(atan2(dir.second, dir.first)) * (PI / 180));
    if (distance > _stopDistance) {
        move(_targetPos);
    }
}
double TankAI::distance(const std::pair<int, int> &otherPos) const noexcept
{
    return sqrt(pow((_pos.first - otherPos.first),2) + pow((_pos.second - otherPos.second),2));
}
void TankAI::move(const std::pair<int, int> &direction) noexcept
{
    std::pair dir = {0, 0};

    dir.first = direction.first > 0 ? 1 : direction.first < 0 ? -1 : 0;
    dir.second = direction.second > 0 ? 1 : direction.second< 0 ? -1 : 0;
    _pos += dir;
}
void TankAI::rotate(float angle) noexcept
{
    _rotation = angle;
    _cannon.rotate(angle - _cannon.getRotation());
}
void TankAI::setBlocked(bool blocked)
{
    _blocked = blocked;
}
void TankAI::fire()
{
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start) >= std::chrono::milliseconds(5000)) {
        start = std::chrono::steady_clock::now();
        _cannon.fire();
    }
}
