//
// Created by clement on 15/06/2021.
//

#pragma once
#include "Object/UiObject/UiObject.hpp"

class FullSquare : public UiObject {
    public:
    FullSquare(coords pos, std::pair<float, float>, float scale, std::pair<RGB, RGB> const &color);
    ~FullSquare() = default;
};