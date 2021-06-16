//
// Created by clement on 15/06/2021.
//

#pragma once

#include "vector"
#include "Object/UiObject/UiObject.hpp"
#include "Object/UiObject/UiGame/FullSquare.hpp"

class LifeGame : public UiObject {
    public:
    LifeGame(std::string const &name, coords pos);
    ~LifeGame() = default;
    const std::string &getName() const;
    void setTransparancy(bool);
    private:
    std::string _name;
};