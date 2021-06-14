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

/**
 * @class Tank
 *
 * @brief base class for tank which is played by the player
 */
class Tank: public MovableObject {
public:
    /**
     * @brief Construct a new Tank object
     * 
     * @param pos 
     * @param size 
     * @param cannon 
     */
    Tank(const coords &pos, const std::pair<int, int> &size,
        Cannon &cannon);
    /**
     * @brief Destroy the Tank object
     * 
     */
    ~Tank() = default;

    /**
     * @brief fire with the cannon
     * 
     */
    virtual void fire();

protected:
    Cannon &_cannon;
};

#endif //INDIESTUDIO_TANK_HPP
