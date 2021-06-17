/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Destructible/Movable/Cannon.hpp"
#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"
#include <utility>

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
    /**
     * @brief Destroy the Tank object
     * 
     */
     //Tank(Tank &tank);
    ~Tank() = default;

    /**
     * @brief fire with the cannon
     * 
     */
    virtual void fire();
    void move(const coords &direction) noexcept override;
    void rotateCannon(float angle);

    Cannon const &getCannon() const noexcept;
    std::string const &getName() const noexcept;
    std::size_t const &getScore() const noexcept;
    void setScore(const std::size_t &score) noexcept;
    const coords &getPreviousPos() const noexcept;
    void setPos(const coords &pos) noexcept override;
    void increaseDamage() noexcept;
    std::pair<std::string, std::string> getPathTank() noexcept;
    struct tank_t {
        float x;
        float z;
        float y;
        float life;
        std::size_t score;
        char name[50];
    };

    const tank_t &getTankStructSave() noexcept;
    static void writeTankList(std::vector<Tank> _tankList) noexcept;
    static std::vector<Tank> readTank();

    protected:
    Cannon _cannon;
    std::string _name;
    std::vector<int> _iterator;
    std::size_t _score;
    tank_t _save;
    coords _previousPos;
};

#endif //INDIESTUDIO_TANK_HPP
