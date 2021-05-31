/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Movable/MovableObject.hpp"
#include "Object/DestroyableObject.hpp"

#ifndef INDIESTUDIO_TANK_HPP
#define INDIESTUDIO_TANK_HPP

class Tank: public MovableObject, public DestroyableObject {
    Tank(const std::pair<int, int> &pos, const std::pair<int, int> &size);

    void fire() {};

private:
    // cannon
};

#endif //INDIESTUDIO_TANK_HPP
