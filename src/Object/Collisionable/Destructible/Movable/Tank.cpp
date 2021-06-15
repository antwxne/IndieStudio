/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Tank.hpp"

const std::string Tank::sandCamo = "asset/Tank/sand_camo.png";
const std::string Tank::greenCamo = "asset/Tank/green_camo.png";
const std::string Tank::body = "asset/Tank/tier1.obj";
const std::string Tank::turret = "asset/Tank/tier2.obj";
const std::string Tank::cannon = "asset/Tank/tier3.obj";

Tank::Tank(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath)
    : MovableObject(pos, size, path), _cannon(Cannon(pos, size, cannonPath))
{
    _typeField.isTank = true;
    _life = 10;
    _speed = 5;
    //changer le sprite
}
void Tank::fire()
{
    _cannon.fire();
}