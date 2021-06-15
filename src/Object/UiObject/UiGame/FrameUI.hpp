//
// Created by clement on 15/06/2021.
//

#pragma once
#include "BorderPlayer.hpp"

class FrameUI {
    public:
    FrameUI();
    ~FrameUI() = default;

    public:
    std::vector<BorderPlayer> _border;
};

static const std::vector<std::pair<float, float>> _uiGameSize{
    {std::make_pair(100, 100)},
    {std::make_pair(100, 100)},
    {std::make_pair(100, 100)},
    {std::make_pair(100, 100)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},

};

static const std::vector<std::pair<float, float>> _uiGamePos {
    {std::make_pair(150, 925)},
    {std::make_pair(650, 925)},
    {std::make_pair(1150, 925)},
    {std::make_pair(1650, 925)},
    {std::make_pair(260, 975)},
    {std::make_pair(760, 975)},
    {std::make_pair(1260, 975)},
    {std::make_pair(1760, 975)},
};
