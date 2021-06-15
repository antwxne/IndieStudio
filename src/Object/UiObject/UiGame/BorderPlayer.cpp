//
// Created by clement on 15/06/2021.
//

#include "BorderPlayer.hpp"

BorderPlayer::BorderPlayer(coords pos, std::pair<float, float> size,
    float scale, const std::pair<RGB, RGB> &color, int sizeBorder
) : UiObject(pos, size, "", scale, color)
{
}