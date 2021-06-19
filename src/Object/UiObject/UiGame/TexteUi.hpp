//
// Created by clement on 16/06/2021.
//

#pragma once
#include "Object/UiObject/UiObject.hpp"

/**
 * @brief Text in ui
 * @class TexteUI
 * 
 */
class TexteUI : public UiObject{
    public:
    /**
     * @brief Construct a new Texte U I object
     * 
     * @param pos 
     * @param size 
     * @param text 
     * @param sizeText 
     * @param scale 
     * @param color 
     */
    TexteUI(const coords &pos, const std::pair<int, int> &size, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color);
    /**
     * @brief Destroy the Texte U I object
     * 
     */
    ~TexteUI() = default;
    /**
     * @brief Get the Text object
     * 
     * @return const std::string& 
     */
    const std::string &getText() const;
    /**
     * @brief Get the Text Size object
     * 
     * @return int 
     */
    int getTextSize() const;
    /**
     * @brief Get the Text Pos object
     * 
     * @return const coords& 
     */
    const coords &getTextPos() const;
    /**
     * @brief Set the Text object
     * 
     * @param text 
     */
    void setText(const std::string &text);
    /**
     * @brief Set the Text Size object
     * 
     * @param textSize 
     */
    void setTextSize(int textSize);
    /**
     * @brief Set the Text Pos object
     * 
     * @param textPos 
     */
    void setTextPos(const coords &textPos);
    /**
     * @brief 
     * 
     * @param up 
     * @param limit 
     * @param pos 
     */
    void upTextSize(int up, int limit, const coords &pos);

    protected:
    /**
     * @brief text
     * 
     */
    std::string _text;
    /**
     * @brief size
     * 
     */
    int _textSize;
    /**
     * @brief position
     * 
     */
    coords _textPos;
};
