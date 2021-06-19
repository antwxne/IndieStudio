//
// Created by clement on 15/06/2021.
//

#pragma once
#include "vector"
#include "Object/UiObject/UiObject.hpp"

/**
 * @brief BorderPlayer class
 * @class BorderPlayer
 * 
 */
class BorderPlayer : public UiObject {
    public:
    /**
     * @brief Construct a new Border Player object
     * 
     * @param pos 
     * @param scale 
     * @param color 
     * @param sizeBorder 
     */
    BorderPlayer(coords pos, std::pair<float, float>, float scale, std::pair<RGB, RGB> const &color, int sizeBorder);
    /**
     * @brief Destroy the Border Player object
     * 
     */
    ~BorderPlayer() = default;
};