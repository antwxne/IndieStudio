/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** PowerUs
*/

#ifndef POWERUPS_HPP_
#define POWERUPS_HPP_

#include <stdlib.h>
#include <time.h>

#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"
#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

/**
 * @brief info about power up
 * @struct Power
 * 
 */
struct Power
{
    /**
     * @brief Construct a new Power object
     * 
     */
    Power() : isSpeedUp(false), isLifeUp(false), isDamageUp(false) {};
    /**
     * @brief speed up ?
     * 
     */
    bool isSpeedUp;
    /**
     * @brief life up ?
     * 
     */
    bool isLifeUp;
    /**
     * @brief damage up ?
     * 
     */
    bool isDamageUp;
};
/**
 * @brief default value for bounce up
 * 
 */
static const int bounceUp = 1;
/**
 * @brief default value for speed up
 * 
 */
static const int speedUp = 1;
/**
 * @brief default value for life up
 * 
 */
static const int lifeUp = 1;
/**
 * @brief path to power up's textures
 * 
 */
static const std::vector<std::string> _texturePath {
    "asset/bonus/Arrows-Blue.png",
    "asset/bonus/Arrows-Green.png",
    "asset/bonus/Arrows-Red.png",
};
/**
 * @brief path to power up's model
 * 
 */
static const std::vector<std::string> _modelPath {
    "asset/bonus/arrow.obj",
    "asset/bonus/arrow1.obj",
    "asset/bonus/arrow2.obj",
};
/**
 * @brief class for power ups management
 * @class PowerUps
 * 
 */
class PowerUps : public MovableObject
{
    public:
        /**
         * @brief Construct a new Power Ups object
         * 
         * @param pos 
         * @param size 
         * @param path 
         * @param powerUps 
         */
        PowerUps(const coords &pos,const coords &size, const std::pair<std::string, std::string> &path, const Power &powerUps);
        /**
         * @brief Construct a new Power Ups object
         * 
         * @param pos 
         * @param size 
         * @param path 
         */
        PowerUps(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path);
        /**
         * @brief Destroy the Power Ups object
         * 
         */
        ~PowerUps();
        /**
         * @brief Get the Power Ups object
         * 
         * @return const Power& 
         */
        [[nodiscard]] const Power &getPowerUps() const noexcept;
        /**
         * @brief Set the Power Ups object
         * 
         * @param power 
         */
        void setPowerUps(const Power &power) noexcept;
        /**
         * @brief apply power up to tank object
         * 
         * @param tank 
         */
        void applyPowerUps(Tank &tank) const noexcept;
    protected:
    private:
        /**
         * @brief current power up
         * 
         */
        Power _powerUps;
};

#endif /* !POWERUS_HPP_ */
