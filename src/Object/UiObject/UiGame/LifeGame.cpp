//
// Created by clement on 15/06/2021.
//

#include "LifeGame.hpp"

LifeGame::LifeGame()
{
    for (auto const &i: _uiLifePos) {
        _posLife.emplace_back(coords(i.first, i.second), std::make_pair(20,20), 5, std::make_pair(RGB{230,0,0}, RGB()));
    }
}