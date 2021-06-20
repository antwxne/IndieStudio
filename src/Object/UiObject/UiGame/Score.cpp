//
// Created by clement on 19/06/2021.
//

#include "Score.hpp"


Score::Score(const std::string &name, const coords &pos,
    const std::pair<int, int> &size, std::size_t &text, int sizeText,
    float scale, std::pair<RGB, RGB> color
) : TexteUI(pos, size, std::to_string(text), sizeText, scale, color), _score(text)
{
    _name = name;
    _typeField.isScore = true;
}

const std::string & Score::getName() const
{
    return _name;
}

void Score::setScore(std::size_t &score)
{
    _score = score;
}

size_t &Score::getScore() const
{
    return _score;
}

void Score::updateDisplay()
{
    _text = std::to_string(_score);
}
