/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** PowerUs
*/

#ifndef POWERUPS_HPP_
#define POWERUPS_HPP_

#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"
#include "Object/Collisionable/Destructible/Movable/Tank.hpp"
#include <stdlib.h>
#include <time.h>

struct Power
{
    Power() : isSpeedUp(false), isLifeUp(false), isDamageUp(false) {};
    bool isSpeedUp;
    bool isLifeUp;
    bool isDamageUp;
};

const std::vector<std::string> _assetsPath {
    "asset/bonus/Arrows-Blue.png",
    "asset/bonus/Arrows-Green.png",
    "asset/bonus/Arrows-Red.png",
};

class PowerUps : public MovableObject
{
    public:
        PowerUps(const coords &pos,const coords &size, const std::pair<std::string, std::string> &path, const Power &powerUps);
        PowerUps(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path);
        ~PowerUps();

        [[nodiscard]] const Power &getPowerUps() const noexcept;
        void setPowerUps(const Power &power) noexcept;
        void applyPowerUps(Tank &tank) const noexcept;
    protected:
    private:
        Power _powerUps;
};

#endif /* !POWERUS_HPP_ */
