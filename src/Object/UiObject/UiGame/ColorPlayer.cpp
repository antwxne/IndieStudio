//
// Created by clement on 16/06/2021.
//

#include "ColorPlayer.hpp"

ColorPlayer::ColorPlayer()
{
    for (auto const &i: _posColor) {
        _posColorSquare.emplace_back(coords(i.first,i.second), std::make_pair(50,30), 1, std::make_pair(RGB{230,0,0}, RGB()));
    }
}