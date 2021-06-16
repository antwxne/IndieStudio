/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/


#include "MovableObject.hpp"
#include "Bullet.hpp"

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
    Cannon(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path);
    Cannon(const Cannon &cannon);
    ~Cannon() = default;

    /**
     * @brief shot one bullet
     *
     */
    void fire();
private:
    std::vector<Bullet> _bullets;
};

#endif //INDIESTUDIO_CANNON_HPP
