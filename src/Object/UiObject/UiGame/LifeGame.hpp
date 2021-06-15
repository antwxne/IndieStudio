//
// Created by clement on 15/06/2021.
//

#pragma once
#include "vector"
#include "Object/UiObject/UiObject.hpp"
#include "Object/UiObject/UiGame/FullSquare.hpp"

class LifeGame {
    public:
    LifeGame();
    ~LifeGame() = default;
    std::vector<FullSquare> _posLife;
};

static const std::vector<std::pair<float, float>>_uiLifePos {
    {std::make_pair(150, 1050)},
    {std::make_pair(650, 1050)},
    {std::make_pair(1150, 1050)},
    {std::make_pair(1650, 1050)},
};
