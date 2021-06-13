/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/AObject.hpp"

#ifndef INDIESTUDIO_COLLISIONABLEOBJECT_HPP
#define INDIESTUDIO_COLLISIONABLEOBJECT_HPP

class CollisionableObject: public AObject {
public:
    CollisionableObject(const std::pair<int, int> &pos, const std::pair<int, int> &size);
    ~CollisionableObject() = default;

    bool hit(CollisionableObject &) noexcept;
};

#endif //INDIESTUDIO_COLLISIONABLEOBJECT_HPP
