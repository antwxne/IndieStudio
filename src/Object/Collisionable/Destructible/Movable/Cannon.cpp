/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Cannon.hpp"

Cannon::Cannon(const std::pair<int, int> &pos, const std::pair<int, int> &size,
    Bullet &bullet)
    : MovableObject(pos, size), _bullet(bullet)
{
    //changer le sprite
}
void Cannon::fire()
{
}
