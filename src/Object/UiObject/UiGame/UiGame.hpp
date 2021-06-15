//
// Created by clement on 15/06/2021.
//

#pragma once
#include "vector"
#include "Object/UiObject/UiObject.hpp"

class UiGame {
    public:
    UiGame();
    ~UiGame() = default;
    std::vector<UiObject> _posRectangle;
};
