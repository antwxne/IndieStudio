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

    static const std::string sandCamo;
    static const std::string greenCamo;
    static const std::string body;
    static const std::string turret;
    static const std::string cannon;

    /**
     * @brief Construct a new Tank object
     * 
     * @param pos 
     * @param size 
     * @param cannon 
     */
    Tank(const std::string &name, const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath);
    Tank(const Tank &to_copy);
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
    void move(const coords &direction) noexcept override;

    Cannon const &getCannon() const;
    std::string const &getName() const;
    std::size_t const &getScore() const;
    void setScore(const std::size_t &score);

protected:
    Cannon _cannon;
    std::string _name;
    std::size_t _score;
};

#endif //INDIESTUDIO_TANK_HPP
