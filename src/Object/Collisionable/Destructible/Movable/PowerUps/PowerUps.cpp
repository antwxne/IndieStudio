/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** PowerUps
*/

#include "PowerUps.hpp"

PowerUps::PowerUps(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path, const Power &powerUps)
    : MovableObject(pos, size, path), _powerUps(powerUps)
{
    _typeField.isPowerUps = true;
    _scale = 0.03f;
    _rotationAxis = {0, 1, 0};
    _life = 1;
}

PowerUps::PowerUps(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path)
    : MovableObject(pos, size, path), _powerUps()
{
    _typeField.isPowerUps = true;
    _scale = 0.03f;
    _rotationAxis = {0, 1, 0};
    _life = 1;
    srand(time(NULL));
    int nb = rand() % 3;

    switch (nb) {
    case (0):
        _powerUps.isSpeedUp = true;
        setTexture(_texturePath.at(nb));
        setModel(_modelPath.at(nb));
        break;
    case (1):
        _powerUps.isLifeUp = true;
        setTexture(_texturePath.at(nb));
        setModel(_modelPath.at(nb));
        break;
    case (2):
        _powerUps.isDamageUp = true;
        setTexture(_texturePath.at(nb));
        setModel(_modelPath.at(nb));
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

void PowerUps::applyPowerUps(Tank &tank) const noexcept
{
    if (_powerUps.isLifeUp)
        tank.updateLife(lifeUp);
    else if (_powerUps.isSpeedUp)
        tank.changeSpeed(speedUp);
    else if (_powerUps.isDamageUp)
        tank.increaseDamage(damageUp);
}
