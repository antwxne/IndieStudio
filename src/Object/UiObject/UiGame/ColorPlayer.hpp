//
// Created by clement on 16/06/2021.
//

#pragma once
#include "vector"
#include "Object/UiObject/UiObject.hpp"
#include "Object/UiObject/UiGame/FullSquare.hpp"

class ColorPlayer {
    public:
    ColorPlayer();
    ~ColorPlayer() = default;
    std::vector<FullSquare> _posColorSquare;
};

static const std::vector<std::pair<float, float>>_posColor {
    {std::make_pair(275, 940)},
    {std::make_pair(775, 940)},
    {std::make_pair(1275, 940)},
    {std::make_pair(1775, 940)},
};