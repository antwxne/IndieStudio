//
// Created by clement on 19/06/2021.
//

#pragma once
#include "TexteUi.hpp"

class Score : public TexteUI{
    public:
    Score(const std::string &name,const coords &pos, const std::pair<int, int> &size,
        std::size_t &text, int sizeText, float scale,
        std::pair<RGB, RGB> color);
    ~Score() = default;
    const std::string &getName() const;

    protected:
    std::string  _name;
    std::size_t &_score;
    public:
    size_t &getScore() const;
    void updateDisplay();

    public:
    void setScore(std::size_t &score);
};