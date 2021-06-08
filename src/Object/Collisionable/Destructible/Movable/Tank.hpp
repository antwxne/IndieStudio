/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Destructible/Movable/Cannon.hpp"
#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"

#ifndef INDIESTUDIO_TANK_HPP
#define INDIESTUDIO_TANK_HPP

class Tank: public MovableObject {
    Tank(const std::pair<int, int> &pos, const std::pair<int, int> &size,
        Cannon &cannon);

    void fire() {};

private:
    Cannon &_cannon;
};

#endif //INDIESTUDIO_TANK_HPP
