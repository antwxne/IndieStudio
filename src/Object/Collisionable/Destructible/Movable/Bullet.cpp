/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <raymath.h>

#include "Bullet.hpp"
#include "Raylib.hpp"

const std::string Bullet::modelPath = "asset/Tank/bullet.obj";
const std::string Bullet::texturePath = "asset/Tank/sable.png";
const float Bullet::waitPosition = -12.0;

Bullet::Bullet(const coords &pos, float angle) : MovableObject(pos, coords(1,1, 1), std::make_pair(Bullet::texturePath, Bullet::modelPath))
{
    _scale = 0.15f;
    _typeField.isBullet = true;
    _life = 1;
    _rotationAngle = angle;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
    _damage = 1;
}

void Bullet::move(const coords &direction) noexcept
{
    auto tmp = direction;
    tmp *= _speed * Raylib::getDeltaTime();
    _pos += tmp;
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

void Bullet::resetBullet() noexcept
{
    _pos = coords(waitPosition, _pos.second, waitPosition);
}

float Bullet::getDamage() const noexcept
{
    return _damage;
}

void Bullet::setDamage(float damage) noexcept
{
    _damage = damage;
}


// void Bullet::constant_move() noexcept
// {
//     static auto start = std::chrono::high_resolution_clock::now();
//     auto now = std::chrono::high_resolution_clock::now();

//     if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start) >= std::chrono::milliseconds(500)) {
//         start = std::chrono::high_resolution_clock::now();
//         // _pos.first += _direction.first;
//         // _pos.second += _direction.second;
//         // _pos.third += _direction.third;
//         _pos += _direction;
//     }
//     // rotate(static_cast<double>(std::atan2(_direction.second, _direction.first)) * (PI / 180));
// }