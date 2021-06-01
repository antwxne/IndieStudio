/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "MovableObject.hpp"

#ifndef INDIESTUDIO_BULLET_HPP
#define INDIESTUDIO_BULLET_HPP

class Bullet: public MovableObject {
public:
    Bullet(const std::pair<int, int> &pos = {-1000, -1000}, const std::pair<int, int> &size = {-1000, -1000});

    void constant_move() noexcept;
    void move(const std::pair<int, int> &direction) noexcept override;

private:
    std::pair<int, int> _direction;
};

#endif //INDIESTUDIO_BULLET_HPP
