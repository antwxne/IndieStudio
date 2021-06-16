/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** PowerUps
*/

#include "PowerUps.hpp"

PowerUps::PowerUps(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const Power &powerUps)
    : MovableObject(pos, size, path), _powerUps(powerUps) {}

PowerUps::PowerUps(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path)
    : MovableObject(pos, size, path), _powerUps()
{
    srand(time(NULL));
    int nb = rand() % 3;

    switch (nb) {
    case (0):
        _powerUps.isSpeedUp = true;
        setTexture(_assetsPath.at(nb));
        break;
    case (1):
        _powerUps.isLifeUp = true;
        setTexture(_assetsPath.at(nb));
        break;
    case (2):
        _powerUps.isDamageUp = true;
        setTexture(_assetsPath.at(nb));
        break;
    default:
        break;
    }
}

PowerUps::~PowerUps() {}

const Power &PowerUps::getPowerUps() const noexcept
{
    return _powerUps;
}

void PowerUps::setPowerUps(const Power &power) noexcept
{
    _powerUps = power;
}

void PowerUps::applyPowerUps(Tank &tank) noexcept
{
    if (_powerUps.isLifeUp)
        tank.updateLife(1);
    else if (_powerUps.isSpeedUp)
        tank.changeSpeed(1);
    else if (_powerUps.isDamageUp)
        std::cout << "[Aplly Power UP] Is damge up needed\n";
}
