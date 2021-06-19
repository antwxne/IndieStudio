//
// Created by clement on 16/06/2021.
//

#pragma once
#include <vector>
#include "Object/UiObject/UiObject.hpp"
#include "Object/UiObject/UiGame/FullSquare.hpp"

/**
 * @brief Color of the player in UI
 * @class ColorPlayer
 * 
 */
class ColorPlayer {
    public:
    /**
     * @brief Construct a new Color Player object
     * 
     */
    ColorPlayer();
    /**
     * @brief Destroy the Color Player object
     * 
     */
    ~ColorPlayer() = default;

    private:
    /**
     * @brief position
     * 
     */
    std::vector<FullSquare> _posColorSquare;
    public:
    /**
     * @brief Get the Pos Color Square object
     * 
     * @return const std::vector<FullSquare>& 
     */
    const std::vector<FullSquare> &getPosColorSquare() const;
};
/**
 * @brief position for color
 * 
 */
static const std::vector<std::pair<float, float>>_posColor {
    {std::make_pair(215, 981)},
    {std::make_pair(715, 981)},
    {std::make_pair(1215, 981)},
    {std::make_pair(1715, 981)},
};

/**
 * @brief coolor for player
 * 
 */
static const std::vector<std::pair<RGB, RGB>> _colorPlayer {
{RGB(255,0,0),RGB()},
{RGB(0,0,255),RGB()},
{RGB(0,255,0),RGB()},
{RGB(255,255,0),RGB()},
};
