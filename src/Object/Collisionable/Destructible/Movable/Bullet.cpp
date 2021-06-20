/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cmath>
#include <chrono>

#include "Bullet.hpp"
#include "Raylib.hpp"

const std::string Bullet::modelPath = "asset/Tank/bullet.obj";
const std::string Bullet::texturePath = "asset/Tank/sable.png";
const float Bullet::waitPosition = -120.0;

Bullet::Bullet(const coords &pos, float angle) : MovableObject(pos, coords(1, 1, 1), std::make_pair(Bullet::texturePath, Bullet::modelPath))
{
    _scale = 0.15f;
    _typeField.isBullet = true;
    _life = 3;
    _rotationAngle = angle;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
    _damage = 1;
    _speed = 7;
    _timeShot = std::chrono::high_resolution_clock::now();
}

void Bullet::move(const coords &direction) noexcept
{
    auto tmp = direction;
    _prevPos = _pos;
    tmp *= _speed * Raylib::getDeltaTime();
    _pos += tmp;
}

void Bullet::bounce() noexcept
{
    auto tmp = _pos - _prevPos;

    if (tmp.first < 0)
        _direction.first *= -1;
    else if (tmp.third < 0)
        _direction.third *= -1;
    else {
        _direction.first *= -1;
        _direction.third *= -1;
    }
    _rotationAngle = static_cast<int>(_rotationAngle + 180) % 360;
}

void Bullet::resetBullet() noexcept
{
    _pos = coords(waitPosition, _pos.second, waitPosition);
    _life = 3;
}

float Bullet::getDamage() const noexcept
{
    return _damage;
}

void Bullet::setDamage(float damage) noexcept
{
    _damage = damage;
}
const coords &Bullet::getDirection() const noexcept
{
    return _direction;
}
void Bullet::setDirection(const coords &direction) noexcept
{
    _direction = direction;
}
void Bullet::setShooting(bool val) noexcept
{
    auto end = std::chrono::high_resolution_clock::now();

    if (val) {
        _typeField.isShooting = true;
        _timeShot = std::chrono::high_resolution_clock::now();
    }
    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - _timeShot) >= std::chrono::milliseconds(500)) {
        _typeField.isShooting = false;
    }
}