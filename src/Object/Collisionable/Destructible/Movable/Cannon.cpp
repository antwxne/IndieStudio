/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <raymath.h>

#include "Cannon.hpp"

Cannon::Cannon(const coords &pos, const std::pair<int, int> &size,
    const std::pair<std::string, std::string> &path
) : MovableObject(pos, size, path)
{
    _typeField.isCannon = true;
    _scale = 0.2f;
    _bullets.reserve(10);
    for (int i = 0; i < 10; ++i) {
        _bullets[i] = Bullet({-10000, 0, 0}, std::make_pair(1, 1));
    }
}

Cannon::Cannon(const Cannon &to_copy) : Cannon(to_copy._pos, to_copy._size,
    to_copy._path)
{
}

void Cannon::fire()
{
    float angle = _rotation * 180 / PI;

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
