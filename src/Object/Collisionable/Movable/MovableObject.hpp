/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/CollisionableObject.hpp"

#ifndef INDIESTUDIO_MOVABLEOBJECT_HPP
#define INDIESTUDIO_MOVABLEOBJECT_HPP

class MovableObject: CollisionableObject {
public:
    MovableObject(const std::pair<int, int> &pos, const std::pair<int, int> &size);

    void move(const std::pair<int, int> &direction) noexcept;
    void rotate(float angle) noexcept;
    void changeSpeed(float newSpeed);

protected:
    float _speed;

};

#endif //INDIESTUDIO_MOVABLEOBJECT_HPP
