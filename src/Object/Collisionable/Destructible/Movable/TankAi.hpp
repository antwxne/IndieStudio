/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_TANKAI_HPP
#define INDIESTUDIO_TANKAI_HPP

#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

class TankAI: public Tank {
public:
    TankAI(const coords &pos, const std::pair<int, int> &size,
        Cannon &cannon);
    ~TankAI() = default;

    void target(const coords &pos) noexcept;
    void autoMove() noexcept;
    void move(const coords &direction) noexcept override;
    void rotate(float angle) noexcept override;
    void setBlocked(bool blocked);
    void fire() override;

private:
    double distance(const coords &otherPos) const noexcept;

protected:
    coords _targetPos;
    double _stopDistance;
    bool _blocked;
};

#endif //INDIESTUDIO_TANKAI_HPP
