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
    TankAI(const std::pair<int, int> &pos, const std::pair<int, int> &size,
        Cannon &cannon);
    ~TankAI() = default;

    void target(const std::pair<int, int> &pos) noexcept;
    void autoMove() noexcept;
    void move(const std::pair<int, int> &direction) noexcept override;
    void rotate(float angle) noexcept override;
    void setBlocked(bool blocked);
    void fire() override;

private:
    double distance(const std::pair<int, int> &otherPos) const noexcept;

protected:
    std::pair<int, int> _targetPos;
    double _stopDistance;
    bool _blocked;
};

#endif //INDIESTUDIO_TANKAI_HPP
