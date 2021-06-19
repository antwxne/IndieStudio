//
// Created by clement on 15/06/2021.
//

#pragma once
#include "BorderPlayer.hpp"

/**
 * @brief FrameUI
 * 
 * @class FrameUI
 * 
 */
class FrameUI {
    public:
    /**
     * @brief Construct a new Frame U I object
     * 
     */
    FrameUI();
    /**
     * @brief Destroy the Frame U I object
     * 
     */
    ~FrameUI() = default;

    private:
    /**
     * @brief all players infos
     * 
     */
    std::vector<BorderPlayer> _border;
    public:
    /**
     * @brief Get the Border object
     * 
     * @return const std::vector<BorderPlayer>& 
     */
    const std::vector<BorderPlayer> &getBorder() const;
};

/**
 * @brief ui size
 * 
 */
static const std::vector<std::pair<float, float>> _uiGameSize{
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)}
};

/**
 * @brief UI pos
 * 
 */
static const std::vector<std::pair<float, float>> _uiGamePos {
    {std::make_pair(270, 975)},
    {std::make_pair(770, 975)},
    {std::make_pair(1270, 975)},
    {std::make_pair(1770, 975)}
};
