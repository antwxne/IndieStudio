/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Cannon.hpp"

Cannon::Cannon(const Type3<float> &pos, const std::pair<int, int> &size,
    Bullet &bullet)
    : MovableObject(pos, size), _bullet(bullet)
{
    _typeField.isCannon = true;
    //changer le sprite
}
void Cannon::fire()
{
}
