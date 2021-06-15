//
// Created by clement on 15/06/2021.
//

#pragma once
#include "BorderPlayer.hpp"

class RectangleUI {
    public:
    RectangleUI();
    ~RectangleUI() = default;

    public:
    std::vector<BorderPlayer> _border;
};
