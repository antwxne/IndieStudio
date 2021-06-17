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

    private:
    std::vector<FullSquare> _posColorSquare;
    public:
    const std::vector<FullSquare> &getPosColorSquare() const;
};

static const std::vector<std::pair<float, float>>_posColor {
    {std::make_pair(275, 940)},
    {std::make_pair(775, 940)},
    {std::make_pair(1275, 940)},
    {std::make_pair(1775, 940)},
};

static const std::vector<std::pair<RGB, RGB>> _colorPlayer {
{RGB(255,0,0),RGB()},
{RGB(0,0,255),RGB()},
{RGB(0,255,0),RGB()},
{RGB(255,255,0),RGB()},
};
