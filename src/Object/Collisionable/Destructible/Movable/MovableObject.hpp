/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Destructible/DestructibleObject.hpp"

#ifndef INDIESTUDIO_MOVABLEOBJECT_HPP
#define INDIESTUDIO_MOVABLEOBJECT_HPP

/**
 * @class Movable Object
 *
 * @brief base class for object who can move
 */
class MovableObject: public DestructibleObject {
public:
    /**
     * @brief Construct a new Movable Object object
     *
     * @param pos
     * @param size
     */
    MovableObject(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path);

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
     * @brief Increase speed for move
     *
     * @param newSpeed
     */
    void changeSpeed(float newSpeed);
    /**
     * @brief Set the Speed object
     * 
     * @param speed 
     */
    void setSpeed(float speed);
    /**
     * @brief Get the Speed object
     * 
     * @return float current speed
     */
    float getSpeed() const;

protected:
    /**
     * @brief object's speed
     * 
     */
    float _speed;
};

#endif //INDIESTUDIO_MOVABLEOBJECT_HPP
