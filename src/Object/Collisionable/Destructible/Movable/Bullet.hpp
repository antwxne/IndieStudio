/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "MovableObject.hpp"

#ifndef INDIESTUDIO_BULLET_HPP
#define INDIESTUDIO_BULLET_HPP

/**
 * @class Bullet
 *
 * @brief Bullet to kill other player
 */
class Bullet: public MovableObject {
public:
    /**
     * @brief Construct a new Bullet object
     * 
     * @param pos 
     * @param size 
     */
    Bullet(const coords &pos, const std::pair<int, int> &size = {-1000, -1000});

    /**
     * @brief once bullet was shot, it follows a vector and being updated by this
     * method
     * 
     */
    void constant_move() noexcept;
    /**
     * @brief set a new dir
     * 
     * @param direction 
     */
    void move(const coords &direction) noexcept override;
    /**
     * @brief bounce when hit surface
     * 
     */
    void bounce() noexcept;

private:
    coords _direction;
    coords _prevPos;
};

#endif //INDIESTUDIO_BULLET_HPP
