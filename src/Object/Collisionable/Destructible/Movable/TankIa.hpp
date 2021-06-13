/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_TANKIA_HPP
#define INDIESTUDIO_TANKIA_HPP

#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

class TankIA: public Tank {
public:
    TankIA(const std::pair<int, int> &pos, const std::pair<int, int> &size,
        Cannon &cannon);
    ~TankIA() = default;

    void target(const std::pair<int, int> &pos) noexcept;
    void autoMove() noexcept;
    void move(const std::pair<int, int> &direction) noexcept override;
    void rotate(float angle) noexcept override;
    void setBlocked(bool blocked);

private:
    double distance(const std::pair<int, int> &otherPos) const noexcept;

protected:
    std::pair<int, int> _targetPos;
    double _stopDistance;
    bool _blocked;
};

#endif //INDIESTUDIO_TANKIA_HPP
