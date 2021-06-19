//
// Created by clement on 15/06/2021.
//

#pragma once

#include "vector"
#include "Object/UiObject/UiObject.hpp"
#include "Object/UiObject/UiGame/FullSquare.hpp"

/**
 * @brief Class display player's life
 * @class LifeGame
 * 
 */
class LifeGame : public UiObject {
    public:
    /**
     * @brief Construct a new Life Game object
     * 
     * @param name 
     * @param pos 
     */
    LifeGame(std::string const &name, coords pos);
    /**
     * @brief Destroy the Life Game object
     * 
     */
    ~LifeGame() = default;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    const std::string &getName() const;
    /**
     * @brief Set the Transparancy object
     * 
     */
    void setTransparancy(bool);
    private:
    /**
     * @brief player's name
     * 
     */
    std::string _name;
};