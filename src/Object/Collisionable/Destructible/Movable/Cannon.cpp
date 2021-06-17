/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <raymath.h>

#include "Cannon.hpp"

Cannon::Cannon(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path)
    : MovableObject(pos, size, path)
{
    _typeField.isCannon = true;
    _scale = 0.2f;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
    _bullets.reserve(10);
    for (int i = 0; i < 10; ++i) {
        _bullets.emplace_back(Bullet({-10000, 0, 0}));
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
void Cannon::increaseDamage() noexcept
{
    for (auto &it : _bullets)
        it.setDamage(it.getDamage() + 1);
}
