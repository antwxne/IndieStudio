//
// Created by clement on 15/06/2021.
//

#include "FrameUI.hpp"

FrameUI::FrameUI()
{
    for (unsigned int i = 0; i != 4; i++) {
        _border.emplace_back(coords(_uiGamePos[i].first, _uiGamePos[i].second),
        std::make_pair(_uiGameSize[i].first, _uiGameSize[i].second),  5,
        std::make_pair(RGB(150, 150,150), RGB()), 5);
    }
}

const std::vector<BorderPlayer> &FrameUI::getBorder() const
{
    return _border;
}