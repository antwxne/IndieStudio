/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <raymath.h>

#include "Cannon.hpp"

Cannon::Cannon(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path)
    : MovableObject(pos, size, path)
{
    _typeField.isCannon = true;
    _scale = 0.2f;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
    _bullets.reserve(10);
    for (int i = 0; i < 10; ++i) {
        _bullets.emplace_back(Bullet({-10000, 0, 0}, std::make_pair(1, 1)));
    }
}

void Cannon::fire()
{
    float angle = _rotationAngle * 180 / PI;

    coords dir = {cos(angle), sin(angle), 0};
    for (auto &i : _bullets) {
        if (i.getPosition().first != -10000) {
            i.move(dir);
            break;
        }
    }
}
const std::vector<Bullet> &Cannon::getBullets() const
{
    return _bullets;
}
