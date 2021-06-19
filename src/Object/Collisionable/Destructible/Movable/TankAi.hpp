/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <chrono>

#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

#ifndef INDIESTUDIO_TANKAI_HPP
#define INDIESTUDIO_TANKAI_HPP

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
    TankAI(const std::string &name, const coords &pos, const coords &size, const int maxBullets, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath);
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
     * @brief fire with the cannon every 5 seconds
     *
     */
    void fire() override;

    static void writeIATankList(std::vector<TankAI> _tankAiList) noexcept;

    static std::vector<TankAI> readAiTankList() noexcept;

    private:
    /**
     * @brief cacl distance between 2 coords
     *
     * @param otherPos
     * @return double
     */
    double distance(const coords &otherPos) const noexcept;

protected:
    /**
     * @brief target position
     * 
     */
    coords _targetPos;
    /**
     * @brief distance to stop move before hiting the target
     * 
     */
    double _stopDistance;
    /**
     * @brief previous rotation angle
     * 
     */
    float _prevRotationAngle;
};

#endif //INDIESTUDIO_TANKAI_HPP
