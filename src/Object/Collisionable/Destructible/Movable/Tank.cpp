/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Tank.hpp"

Tank::Tank(const Type3<float> &pos, const std::pair<int, int> &size,
    Cannon &cannon
) : MovableObject(pos, size), _cannon(cannon)
{
    _typeField.isTank = true;
    _life = 10;
    //changer le sprite
}
void Tank::fire()
{
    _cannon.fire();
}
