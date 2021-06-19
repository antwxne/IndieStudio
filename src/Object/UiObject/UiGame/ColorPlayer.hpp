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
    {std::make_pair(215, 981)},
    {std::make_pair(715, 981)},
    {std::make_pair(1215, 981)},
    {std::make_pair(1715, 981)},
};

static const std::vector<std::pair<RGB, RGB>> _colorPlayer {
{RGB(255,0,0),RGB()},
{RGB(0,0,255),RGB()},
{RGB(0,255,0),RGB()},
{RGB(255,255,0),RGB()},
};
