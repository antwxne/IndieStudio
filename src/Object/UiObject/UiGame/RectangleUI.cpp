//
// Created by clement on 15/06/2021.
//

#include "RectangleUI.hpp"

RectangleUI::RectangleUI()
{
    _border.emplace_back(coords(100, 1000),
        std::make_pair(50, 50),  9,
        std::make_pair(RGB(0, 0, 0), RGB()), 5);
}