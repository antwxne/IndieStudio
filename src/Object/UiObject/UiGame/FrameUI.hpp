//
// Created by clement on 15/06/2021.
//

#pragma once
#include "BorderPlayer.hpp"

class FrameUI {
    public:
    FrameUI();
    ~FrameUI() = default;

    private:
    std::vector<BorderPlayer> _border;
    public:
    const std::vector<BorderPlayer> &getBorder() const;
};

static const std::vector<std::pair<float, float>> _uiGameSize{
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)}
};

static const std::vector<std::pair<float, float>> _uiGamePos {
    {std::make_pair(270, 975)},
    {std::make_pair(770, 975)},
    {std::make_pair(1270, 975)},
    {std::make_pair(1770, 975)}
};
