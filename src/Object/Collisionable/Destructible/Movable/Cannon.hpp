/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/


#include "MovableObject.hpp"
#include "Bullet.hpp"

#ifndef INDIESTUDIO_CANNON_HPP
#define INDIESTUDIO_CANNON_HPP

class Cannon: public MovableObject {
public:
    Cannon(const coords &pos, const std::pair<int, int> &size,
        Bullet &bullet);

    void fire();
private:
    Bullet &_bullet;
};

#endif //INDIESTUDIO_CANNON_HPP
