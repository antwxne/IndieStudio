/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <cmath>

#include "Raylib/Raylib.hpp"
#include "Cannon.hpp"


Cannon::Cannon(const coords &pos, const coords &size, const int maxBullets, const std::pair<std::string, std::string> &path)
    : MovableObject(pos, size, path), _fireTimeStamp(std::chrono::high_resolution_clock::now()), _fireCoolDown(1500), _prevPos(pos)
{
    _typeField.isCannon = true;
    _scale = 0.2f;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);

    const std::size_t _maxBullets = maxBullets;
    _bullets.reserve(_maxBullets);
    for (int i = 0; i < _maxBullets; ++i)
        _bullets.emplace_back(coords({Bullet::waitPosition, 0.3, -100}), _rotationAngle);
}

void Cannon::fire()
{
    auto now = std::chrono::high_resolution_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - _fireTimeStamp) < std::chrono::milliseconds(_fireCoolDown))
        return;
    _fireTimeStamp = std::chrono::high_resolution_clock::now();
    for (auto &bullet : _bullets) {
        if (bullet.getPosition().first == Bullet::waitPosition) {
            bullet.setPosition(coords(_pos.first, bullet.getPosition().second, _pos.third));
            bullet.setRotationAngle(_rotationAngle);
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

void Cannon::moveBullets() noexcept
{
    for (auto &bullet : _bullets)
        if (bullet.getPosition().first != Bullet::waitPosition)
            bullet.move(coords(std::sin(M_PI *  bullet.getRotationAngle() / 180), 0, std::cos(M_PI * bullet.getRotationAngle() / 180)));
}
void Cannon::move(const coords &direction) noexcept
{
    auto tmp = direction;
    _prevPos = _pos;
    tmp *= _speed * Raylib::getDeltaTime();
    _pos += tmp;
}
const coords &Cannon::getPrevPos() const
{
    return _prevPos;
}
