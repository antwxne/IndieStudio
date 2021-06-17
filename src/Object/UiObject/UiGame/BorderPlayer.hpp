//
// Created by clement on 15/06/2021.
//

#pragma once
#include "vector"
#include "Object/UiObject/UiObject.hpp"

class BorderPlayer : public UiObject {
    public:
    BorderPlayer(coords pos, std::pair<float, float>, float scale, std::pair<RGB, RGB> const &color, int sizeBorder);
    ~BorderPlayer() = default;
};