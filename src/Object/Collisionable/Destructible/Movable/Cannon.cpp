/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Cannon.hpp"
#include <cmath>

Cannon::Cannon(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path)
    : MovableObject(pos, size, path)
{
    const int _nbBullets = 1;
    _typeField.isCannon = true;
    _scale = 0.2f;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
    _bullets.reserve(_nbBullets);
    for (int i = 0; i < _nbBullets; ++i)
        _bullets.emplace_back(Bullet({-12, 0, -7}, _rotationAngle));
}

void Cannon::fire()
{
    for (auto &bullet : _bullets) {
        if (bullet.getPosition().first == -12) {
            bullet.setPosition(coords(0, 0, -5));
            bullet.setRotationAngle(_rotationAngle);
            break;
        }
    }
}
const std::vector<Bullet> &Cannon::getBullets() const
{
    return _bullets;
}
