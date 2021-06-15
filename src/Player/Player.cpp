/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Player.hpp"


Player::Player(Tank &tank)
: _name(""), _score(0), _tank(tank)
{
}

const std::string &Player::getName() const
{
    return _name;
}
void Player::setName(const std::string &name)
{
    _name = name;
}
std::size_t Player::getScore() const
{
    return _score;
}
void Player::setScore(std::size_t score)
{
    _score = score;
}
void Player::increaseScore(std::size_t inc)
{
    _score += inc;
}

