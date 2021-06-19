/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Tank.hpp"
#include "Raylib.hpp"
#include <iostream>
#include <fstream>
#include <functional>

const std::string Tank::bodyTexture = "asset/Tank/sandCamo.png";
const std::string Tank::darkGreen = "asset/Tank/dark_green.png";
const std::string Tank::darkRed = "asset/Tank/dark_red.png";
const std::string Tank::greenCamo = "asset/Tank/green_camo.png";
const std::string Tank::bodyModel = "asset/Tank/tankBodyNEW.obj";
const std::string Tank::cannonModel = "asset/Tank/turretWithCannonNEW.obj";

Tank::Tank(const std::string &name, const coords &pos, const coords &size, const int maxBullets, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : MovableObject(pos, size, path), _cannon(coords{pos.first, pos.second + 0.15f, pos.third}, size, maxBullets, cannonPath), _name(name), _score(0), _previousPos(0, 0, 0)
{
    _typeField.isTank = true;
    _scale = 0.2f;
    _life = 3;
    _rotationAngle = 0.0f;
    _rotationAxis = coords(0.0f, 1.0f, 0.0f);
}

void Tank::fire()
{
    _cannon.fire();
}

void Tank::move(const coords &direction) noexcept
{
    auto tmp = direction;
    _previousPos = _pos;
    tmp *= _speed * Raylib::getDeltaTime();
    _pos += tmp;
    _cannon.move(direction);
}

void Tank::moveBullets() noexcept
{
    _cannon.moveBullets();
}

void Tank::rotateCannon(float angle)
{
    _cannon.rotate(angle);
}

Cannon &Tank::getCannon() noexcept
{
    return _cannon;
}

std::string const &Tank::getName() const noexcept
{
    return _name;
}

std::size_t const &Tank::getScore() const noexcept
{
    return _score;
}

void Tank::setScore(const std::size_t &score) noexcept
{
    _score = score;
}
const coords &Tank::getPreviousPos() const noexcept
{
    return _previousPos;
}
void Tank::setPosition(const coords &pos) noexcept
{
    _pos = pos;
    _cannon.setPosition(_cannon.getPrevPos());
}
void Tank::increaseDamage(int dmgUp) noexcept
{
    _cannon.increaseDamage(dmgUp);
}

std::pair<std::string, std::string > Tank::getPathTank() noexcept {
    return _path;
}

const Tank::tank_t &Tank::getTankStructSave() noexcept
{
    _save.x = _pos.first;
    _save.y = _pos.third;
    _save.life = _life;
    _save.score = _score;
    _save.z = _pos.second;
    _save.speed = _speed;
    std::strcpy(_save.name, _name.c_str());
    return _save;
}

void Tank::writeTankList(std::vector<Tank> _tankList) noexcept
{
    unsigned long size = _tankList.size();
    Tank::tank_t dest;
    std::remove("tank.txt");
    std::ofstream file("tank.txt",
        std::ios::out | std::ofstream::binary | std::ofstream::trunc);
    file.write(reinterpret_cast<const char *>(&size), sizeof(unsigned long));
    for (auto &i : _tankList) {
        dest = i.getTankStructSave();
        file.write(reinterpret_cast<const char *>(&dest),
            sizeof(Tank::tank_t));
    }
}

std::vector<Tank> Tank::readTank()
{
    std::vector<Tank> tmp;
    unsigned long size = 0;
    Tank::tank_t dest;
    std::ifstream file("tank.txt",
        std::ios::in | std::ifstream::binary);
    if (file.is_open() == false)
        throw std::runtime_error("Can not open");
    std::cout << size << std::endl;
    file.read(reinterpret_cast<char *>(&size), sizeof(unsigned long));
    for (int i = 0; i != size; i++) {
        file.read(reinterpret_cast<char *>(&dest),
            sizeof(Tank::tank_t));
        tmp.emplace_back(dest.name,
            coords(static_cast<float>(dest.x), static_cast<float>(dest.z), static_cast<float>(dest.y)),
            coords (10, 0, 10), 8,std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel));
        auto tank = tmp.back();
        tank.setScore(dest.score);
        tank.setLife(dest.life);
        tank._speed = dest.speed;
    }
    std::cout << "finish tank" << std::endl;
    return tmp;
}
