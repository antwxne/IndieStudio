//
// Created by clement on 15/06/2021.
//

#include "LifeGame.hpp"

LifeGame::LifeGame(std::string const &name, coords pos) : _name(name), UiObject(pos, std::make_pair(1,1), "asset/Tank/heart.png", 0.02)
{
    _typeField.isLife = true;
}

const std::string &LifeGame::getName() const
{
    return _name;
}

void LifeGame::setTransparancy(bool tmp)
{
    _typeField.isTransparent = tmp;
}