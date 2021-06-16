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
    std::vector<UiObject> _posLife;
};

static const std::vector<std::pair<float, float>>_uiLifePos {
    {std::make_pair(265, 1050)},
    {std::make_pair(295, 1050)},
    {std::make_pair(325, 1050)},
    {std::make_pair(765, 1050)},
    {std::make_pair(795, 1050)},
    {std::make_pair(825, 1050)},
    {std::make_pair(1265, 1050)},
    {std::make_pair(1295, 1050)},
    {std::make_pair(1325, 1050)},
    {std::make_pair(1765, 1050)},
    {std::make_pair(1795, 1050)},
    {std::make_pair(1825, 1050)},
};
