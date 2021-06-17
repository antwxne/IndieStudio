//
// Created by clement on 16/06/2021.
//

#pragma once
#include "Object/UiObject/UiObject.hpp"


class TexteUI : public UiObject{
    public:
    TexteUI(const coords &pos, const std::pair<int, int> &size, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color);
    ~TexteUI() = default;
    const std::string &getText() const;
    int getTextSize() const;
    const coords &getTextPos() const;
    void setText(const std::string &text);
    void setTextSize(int textSize);
    void setTextPos(const coords &textPos);
    void upTextSize(int up, int limit, const coords &pos);

    protected:
    std::string _text;
    int _textSize;
    coords _textPos;
};
