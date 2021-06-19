/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "UiObject.hpp"

namespace button {

    enum buttonState_e
    {
        NOTHING,
        OVER,
        CLICKED
    };

    static const std::array<std::string, 3> _buttonNavigPath {
        "asset/menu_asset/Button_blue.png",
        "asset/menu_asset/Button_beige.png",
        "asset/menu_asset/Button_blue_pressed.png"
    };

    static const std::array<std::string, 3> _buttonPlayerPath {
        "asset/menu_asset/Button_beige.png",
        "asset/menu_asset/Button_beige.png",
        "asset/menu_asset/Button_beige_pressed.png"
    };

    static const std::array<std::string, 3> _soloPath {
        "asset/menu_asset/Button_blue_pressed.png",
        "asset/menu_asset/Button_blue_pressed.png",
        "asset/menu_asset/Button_blue_pressed.png"
    };

    static const std::array<std::string, 3> _buttonSettingPath {
        "asset/menu_asset/Button_brown.png",
        "asset/menu_asset/Button_brown.png",
        "asset/menu_asset/Button_brown.png"
    };

    static const std::array<std::string, 3> _buttonWinnerPath {
        "asset/menu_asset/Button_white.png",
        "asset/menu_asset/Button_white.png",
        "asset/menu_asset/Button_white.png"
    };


    static const std::pair<float, float> _buttonSize = std::make_pair(200, 50);

    static const std::pair<float, float> _buttonSettingSize = std::make_pair(50, 50);

    class Button : public UiObject
    {
        public:
            Button(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color);
            ~Button();
            void setText(const std::string &newText) noexcept;
            const std::string getText() const noexcept;
            const coords getTextPos() const noexcept;
            const int getTextSize() const noexcept;
            bool isInside(const std::pair<float, float> &pos) const;
            void setState(const std::pair<float, float> &pos, bool clicked);
            void clearText();

        protected:
            std::array<std::string, 3> _texturePath;
            std::string _text;
            int _textSize;
            coords _textPos;
    };

}

#endif /* !BUTTON_HPP_ */
