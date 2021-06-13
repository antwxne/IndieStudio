/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Destructible/DestructibleObject.hpp"

#ifndef INDIESTUDIO_MOVABLEOBJECT_HPP
#define INDIESTUDIO_MOVABLEOBJECT_HPP

class MovableObject: public DestructibleObject {
public:
    MovableObject(const coords &pos, const std::pair<int, int> &size);

    virtual void move(const coords &direction) noexcept;
    virtual void rotate(float angle) noexcept;
    void changeSpeed(float newSpeed);

protected:
    float _speed;
};

#endif //INDIESTUDIO_MOVABLEOBJECT_HPP
