//
// Created by clement on 15/06/2021.
//

#include "FullSquare.hpp"

FullSquare::FullSquare(coords pos, std::pair<float, float> size, float scale,
    const std::pair<RGB, RGB> &color
) : UiObject(pos, size, "", scale, color)
{
    _typeField.isFullSquare = true;
}