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

const std::string Tank::sandCamo = "asset/Tank/sand_camo.png";
const std::string Tank::greenCamo = "asset/Tank/green_camo.png";
const std::string Tank::body = "asset/Tank/tankBodyNEW.obj";
const std::string Tank::turret = "asset/Tank/turretWithCannonNEW.obj";

Tank::Tank(const std::string &name, const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : MovableObject(pos, size, path), _cannon(coords{pos.first, pos.second + 0.15f, pos.third}, size, cannonPath), _name(name), _score(0), _previousPos(pos)
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

void Tank::rotateCannon(float angle)
{
    _cannon.rotate(angle);
}

Cannon const &Tank::getCannon() const noexcept
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
void Tank::setPos(const coords &pos) noexcept
{
    AObject::setPos(pos);
    _cannon.setPosition(pos);
}
void Tank::increaseDamage() noexcept
{
    _cannon.increaseDamage();
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
    std::strcpy(_save.name, _name.c_str());
    return _save;
}

void Tank::writeTankList(std::vector<Tank> _tankList) noexcept
{
    unsigned long size = _tankList.size();
    Tank::tank_t dest;
    std::ofstream file("tank.txt",
        std::ios::out | std::ofstream::binary | std::ofstream::trunc);
    file.write(reinterpret_cast<const char *>(&size), sizeof(unsigned long));
    for (auto &i : _tankList) {
        dest = i.getTankStructSave();
        file.write(reinterpret_cast<const char *>(&dest),
            sizeof(Tank::tank_t));
    }
    file.close();
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
    file.read(reinterpret_cast<char *>(&size), sizeof(unsigned long));
    for (int i = 0; i != size; i++) {
        file.read(reinterpret_cast<char *>(&dest),
            sizeof(Tank::tank_t));
        //std::cout << "----------------------------" << std::endl;
        std::cout << "name == " << dest.name << " pos.x == " << dest.x << " pos.y == " << dest.y << "_life == " << dest.life << " _score == " << dest.score << std::endl;
        auto tank = tmp.emplace_back(dest.name,
            coords(static_cast<float>(dest.x), static_cast<float>(dest.z), static_cast<float>(dest.y)),
            std::make_pair(10, 10), std::make_pair(Tank::sandCamo, Tank::body), std::make_pair(Tank::greenCamo, Tank::turret));
        tank.setScore(dest.score);
        tank.setLife(dest.life);
    }
    file.close();
    return tmp;
}