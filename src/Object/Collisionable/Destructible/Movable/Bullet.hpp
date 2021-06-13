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
    Bullet(const Type3<float> &pos = {-1000, -1000, 0}, const std::pair<int, int> &size = {-1000, -1000});

    void constant_move() noexcept;
    void move(const Type3<float> &direction) noexcept override;

private:
    Type3<float> _direction;
};

#endif //INDIESTUDIO_BULLET_HPP
