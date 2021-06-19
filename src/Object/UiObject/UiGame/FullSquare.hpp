//
// Created by clement on 15/06/2021.
//

#pragma once
#include "Object/UiObject/UiObject.hpp"

/**
 * @brief Full square
 * @class FullSquare
 * 
 */
class FullSquare : public UiObject {
    public:
    /**
     * @brief Construct a new Full Square object
     * 
     * @param pos 
     * @param scale 
     * @param color 
     */
    FullSquare(coords pos, std::pair<float, float>, float scale, std::pair<RGB, RGB> const &color);
    /**
     * @brief Destroy the Full Square object
     * 
     */
    ~FullSquare() = default;
};