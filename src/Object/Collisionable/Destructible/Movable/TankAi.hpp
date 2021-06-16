/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_TANKAI_HPP
#define INDIESTUDIO_TANKAI_HPP

#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

/**
 * @class TankAi
 *
 * @brief class for AI
 */
class TankAI: public Tank {
public:
    /**
     * @brief Construct a new Tank A I object
     *
     * @param pos
     * @param size
     * @param cannon
     */
    TankAI(const std::string &name, const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath);
    /**
     * @brief Destroy the Tank A I object
     *
     */
    ~TankAI() = default;

    /**
     * @brief set a target (player or IA)
     *
     * @param pos
     */
    void target(const coords &pos) noexcept;
    /**
     * @brief call this every time to animate AI
     *
     */
    void autoMove() noexcept;
    /**
     * @brief move object
     *
     * @param direction
     */
    void move(const coords &direction) noexcept override;
    /**
     * @brief rotate object
     *
     * @param angle
     */
    void rotate(float angle) noexcept override;
    /**
     * @brief Set the Blocked object
     *
     * @param blocked
     */
    void setBlocked(bool blocked);
    /**
     * @brief fire with the cannon every 5 seconds
     *
     */
    void fire() override;

private:
    /**
     * @brief cacl distance between 2 coords
     *
     * @param otherPos
     * @return double
     */
    double distance(const coords &otherPos) const noexcept;

protected:
    coords _targetPos;
    double _stopDistance;
    bool _blocked;
};

#endif //INDIESTUDIO_TANKAI_HPP
