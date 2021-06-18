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
    Bullet(const coords &pos, float angle);

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

    /**
     * @brief Get the Damage object
     * 
     * @return float 
     */
    float getDamage() const noexcept;

    /**
     * @brief Set the Damage object
     * 
     * @param damage 
     */
    void setDamage(float damage) noexcept;

    /**
     * @brief when a bullet should be destroyed resets it to waitPosition
     * 
     */
    void resetBullet() noexcept;

    /**
     * @brief path to model asset
     * 
     */
    static const std::string modelPath;

    /**
     * @brief path to texture asset
     * 
     */
    static const std::string texturePath;

    /**
     * @brief position where the bullets stay when not fired and not moving
     * 
     */
    static const float waitPosition;

    const coords &getDirection() const noexcept;
    void setDirection(const coords &direction) noexcept;
    void setShooting(bool val) noexcept;
private:

    /**
     * @brief direction of the bullet
     * 
     */
    coords _direction;
    /**
     * @brief ???
     * 
     */
    coords _prevPos;

    /**
     * @brief if bullets collides with X, X's life is subtracted _damage 
     * 
     */
    float _damage;
};

#endif //INDIESTUDIO_BULLET_HPP
