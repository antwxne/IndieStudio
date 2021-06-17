//
// Created by clement on 16/06/2021.
//

#include "ColorPlayer.hpp"

ColorPlayer::ColorPlayer()
{
    for (unsigned int i = 0; i != _posColor.size(); i++) {
        _posColorSquare.emplace_back(coords(_posColor[i].first,_posColor[i].second), std::make_pair(50,30), 1, _colorPlayer[i]);
    }
}

const std::vector<FullSquare> &ColorPlayer::getPosColorSquare() const
{
    return _posColorSquare;
}
