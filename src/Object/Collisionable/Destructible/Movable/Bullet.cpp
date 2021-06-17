/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <chrono>
#include <raymath.h>

#include "Bullet.hpp"

static const std::string bulletModelPath = "";
static const std::string bulletTexturePath = "";

Bullet::Bullet(const coords &pos, const coords &size) : MovableObject(pos, size, {bulletModelPath, bulletTexturePath})
{
    _typeField.isBullet = true;
    _life = 3;
    _damage = 1;
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
float Bullet::getDamage() const noexcept
{
    return _damage;
}
void Bullet::setDamage(float damage) noexcept
{
    _damage = damage;
}
