//
// Created by clement on 16/06/2021.
//

#include "TexteUi.hpp"

TexteUI::TexteUI(const coords &pos, const std::pair<int, int> &size,
    const std::string &text, int sizeText, float scale,
    std::pair<RGB, RGB> color
) : UiObject(pos, size, "", scale, color)
{
    _text = text;
    _textPos = pos;
    _textSize = sizeText;
    _typeField.isText = true;
}

const std::string &TexteUI::getText() const
{
    return _text;
}

int TexteUI::getTextSize() const
{
    return _textSize;
}

const coords &TexteUI::getTextPos() const
{
    return _textPos;
}

void TexteUI::setText(const std::string &text)
{
    _text = text;
}

void TexteUI::setTextSize(int textSize)
{
    _textSize = textSize;
}

void TexteUI::upTextSize(int up, int limit, const coords &pos)
{
    if (_textSize < limit) {
        _textPos += pos;
        _textSize += up;
    }
}

void TexteUI::setTextPos(const coords &textPos)
{
    _textPos = textPos;
}
