/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <chrono>

#include "Bullet.hpp"

Bullet::Bullet(const std::pair<int, int> &pos, const std::pair<int, int> &size)
    : MovableObject(pos, size)
{
    _typeField.isBullet = true;
    _life = 3;
    //changer le sprite
}
void Bullet::constant_move() noexcept
{
    static auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start) >= std::chrono::milliseconds(500)) {
        start = std::chrono::high_resolution_clock::now();
        _pos += _direction;
    }
}
void Bullet::move(const std::pair<int, int> &direction) noexcept
{
    _direction = direction;
}
