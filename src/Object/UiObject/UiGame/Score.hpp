//
// Created by clement on 19/06/2021.
//

#pragma once
#include "TexteUi.hpp"
/**
 * @brief class to manage score
 * @class Score
 * 
 */
class Score : public TexteUI{
    public:
    /**
     * @brief Construct a new Score object
     * 
     * @param name 
     * @param pos 
     * @param size 
     * @param text 
     * @param sizeText 
     * @param scale 
     * @param color 
     */
    Score(const std::string &name,const coords &pos, const std::pair<int, int> &size,
        std::size_t &text, int sizeText, float scale,
        std::pair<RGB, RGB> color);
    /**
     * @brief Destroy the Score object
     * 
     */
    ~Score() = default;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    const std::string &getName() const;
    /**
     * @brief Get the Score object
     * 
     * @return size_t& 
     */
    size_t &getScore() const;
    /**
     * @brief update score in display
     * 
     */
    void updateDisplay();
    /**
     * @brief Set the Score object
     * 
     * @param score 
     */
    void setScore(std::size_t &score);

    protected:
    /**
     * @brief player's name
     * 
     */
    std::string  _name;
    /**
     * @brief player's score
     * 
     */
    std::size_t &_score;
};