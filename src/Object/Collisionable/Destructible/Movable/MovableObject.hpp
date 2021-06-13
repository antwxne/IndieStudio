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
    /**
     * @brief Construct a new Movable Object object
     * 
     * @param pos 
     * @param size 
     */
    MovableObject(const coords &pos, const std::pair<int, int> &size);

    /**
     * @brief move object
     * 
     * @param direction 
     */
    virtual void move(const coords &direction) noexcept;
    /**
     * @brief rotate object
     * 
     * @param angle 
     */
    virtual void rotate(float angle) noexcept;
    /**
     * @brief change speed for move
     * 
     * @param newSpeed 
     */
    void changeSpeed(float newSpeed);

protected:
    float _speed;
};

#endif //INDIESTUDIO_MOVABLEOBJECT_HPP
