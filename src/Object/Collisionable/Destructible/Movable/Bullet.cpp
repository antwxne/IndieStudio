/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <chrono>
#include <raymath.h>

#include "Bullet.hpp"

const std::string Bullet::modelPath = "asset/Tank/bullet.obj";
const std::string Bullet::texturePath = "asset/Tank/sable.png";

Bullet::Bullet(const coords &pos, float angle) : MovableObject(pos, std::make_pair(1,1), std::make_pair(Bullet::texturePath, Bullet::modelPath))
{
    _scale = 0.2f;
    _typeField.isBullet = true;
    _life = 1;
    _rotationAngle = angle;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
}
void Bullet::constant_move() noexcept
{
    static auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start) >= std::chrono::milliseconds(500)) {
        start = std::chrono::high_resolution_clock::now();
        _pos.first += _direction.first;
        _pos.second += _direction.second;
        _pos.third += _direction.third;
        _pos += _direction;
    }
    rotate(static_cast<double>(std::atan2(_direction.second, _direction.first)) * (PI / 180));
}
void Bullet::move(const coords &direction) noexcept
{
    _direction = direction;
}
void Bullet::bounce() noexcept
{
    auto tmp = _pos - _prevPos;

    if (tmp.first < 0)
        _direction.first *= -1;
    else if (tmp.second < 0)
        _direction.second *= -1;
    else {
        _direction.first *= -1;
        _direction.second *= -1;
    }
}
