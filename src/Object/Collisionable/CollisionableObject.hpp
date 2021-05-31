/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_COLLISIONABLEOBJECT_HPP
#define INDIESTUDIO_COLLISIONABLEOBJECT_HPP

#include "Object/AObject.hpp"

class CollisionableObject: public AObject {
public:
    CollisionableObject(const std::pair<int, int> &pos, const std::pair<int, int> &size);
    ~CollisionableObject() = default;

    bool hit(const CollisionableObject &) const noexcept;
};

#endif //INDIESTUDIO_COLLISIONABLEOBJECT_HPP
