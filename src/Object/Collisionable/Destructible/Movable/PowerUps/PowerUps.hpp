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

static const int bounceUp = 1;

static const int speedUp = 1;

static const int lifeUp = 1;

static const std::vector<std::string> _texturePath {
    "asset/bonus/Arrows-Blue.png",
    "asset/bonus/Arrows-Green.png",
    "asset/bonus/Arrows-Red.png",
};

static const std::vector<std::string> _modelPath {
    "asset/bonus/arrow.obj",
    "asset/bonus/arrow1.obj",
    "asset/bonus/arrow2.obj",
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
