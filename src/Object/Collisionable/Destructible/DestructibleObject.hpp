/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/CollisionableObject.hpp"

#ifndef INDIESTUDIO_DESTROYABLEOBJECT_HPP
#define INDIESTUDIO_DESTROYABLEOBJECT_HPP

class DestructibleObject: public CollisionableObject {
public:
    DestructibleObject(const std::pair<int, int> &pos,
        const std::pair<int, int> &size);
    ~DestructibleObject() = default;

    [[nodiscard]] float getLife() const;
    void setLife(float life);
    void updateLife(float life);
    bool isDestroyed() const;

protected:
    float _life;
};

#endif //INDIESTUDIO_DESTROYABLEOBJECT_HPP
