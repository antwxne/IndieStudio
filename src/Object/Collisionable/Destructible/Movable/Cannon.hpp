/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/


#include "MovableObject.hpp"
#include "Bullet.hpp"
#include <chrono>

#ifndef INDIESTUDIO_CANNON_HPP
#define INDIESTUDIO_CANNON_HPP

/**
 * @class Cannon
 *
 * @brief Cannon wich is related to a tank and contains a bullet
 */
class Cannon: public MovableObject {
public:
    /**
     * @brief Construct a new Cannon object
     *
     * @param pos
     * @param size
     * @param bullet
     */
    Cannon(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path);
    /**
     * @brief copy constructor
     * @param cannon object to copy
     */
    ~Cannon() = default;
    /**
     * @brief shot one bullet
     *
     */
    void fire();
    /**
     * @brief get all the bullets
     * @return vector of bullet
     */
    const std::vector<Bullet> &getBullets() const;

    /**
     * @brief to_call in game loop, it updates the moving bullets.
     * 
     */
    void moveBullets() noexcept;

    /**
     * @brief increases by one the damage of the bullets
     * 
     */
    void increaseDamage() noexcept;

    /**
     * @brief Set the Fire Cool Down object
     * 
     */
    void setFireCoolDown(int) noexcept;

    /**
     * @brief Get the Fire Cool Down object
     * 
     * @return int 
     */
    int getFireCoolDown() const noexcept;

private:
    /**
     * @var bullet's vector
     * @brief vector containing bullets
     */
    static const std::size_t _nbBullets;

    /**
     * @brief vector of all the bullets that this tank can have.
     *          --> we create before all bullets and move them when fired
     */
    std::vector<Bullet> _bullets;
    
    /**
     * @brief timeStamp used as a reference for fire cooldown
     * 
     */
    std::chrono::_V2::system_clock::time_point _fireTimeStamp;

    /**
     * @brief cool down for firing ability
     * 
     */
    int _fireCoolDown;
};

#endif //INDIESTUDIO_CANNON_HPP
