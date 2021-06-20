/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "UiObject.hpp"
/**
 * @brief contains all button's class
 * @namespace button
 * 
 */
namespace button {
    /**
     * @brief different state of button
     * @enum buttonState_e
     * 
     */
    enum buttonState_e
    {
        NOTHING,
        OVER,
        CLICKED
    };
    /**
     * @brief path to buttons
     * 
     */
    static const std::array<std::string, 3> _buttonNavigPath {
        "asset/menu_asset/Button_blue.png",
        "asset/menu_asset/Button_beige.png",
        "asset/menu_asset/Button_blue_pressed.png"
    };
    /**
     * @brief path to buttons
     * 
     */
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

    /**
     * @brief path to buttons
     * 
     */
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

    /**
     * @brief button size
     * 
     */
    static const std::pair<float, float> _buttonSize = std::make_pair(200, 50);
    /**
     * @brief button size
     * 
     */
    static const std::pair<float, float> _buttonSettingSize = std::make_pair(50, 50);
    /**
     * @brief base class for buttons
     * @class Button
     * 
     */
    class Button : public UiObject
    {
        public:
            /**
             * @brief Construct a new Button object
             * 
             * @param pos 
             * @param size 
             * @param path 
             * @param text 
             * @param sizeText 
             * @param scale 
             * @param color 
             */
            Button(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color);
            /**
             * @brief Destroy the Button object
             * 
             */
            ~Button();
            /**
             * @brief Set the Text object
             * 
             * @param newText 
             */
            void setText(const std::string &newText) noexcept;
            /**
             * @brief Get the Text object
             * 
             * @return const std::string 
             */
            const std::string getText() const noexcept;
            /**
             * @brief Get the Text Pos object
             * 
             * @return const coords 
             */
            const coords getTextPos() const noexcept;
            /**
             * @brief Get the Text Size object
             * 
             * @return const int 
             */
            const int getTextSize() const noexcept;
            /**
             * @brief 
             * 
             * @param pos 
             * @return true 
             * @return false 
             */
            bool isInside(const std::pair<float, float> &pos) const;
            /**
             * @brief Set the State object
             * 
             * @param pos 
             * @param clicked 
             */
            void setState(const std::pair<float, float> &pos, bool clicked);
            /**
             * @brief clear text in button
             * 
             */
            void clearText();

        protected:
            /**
             * @brief path to textures
             * 
             */
            std::array<std::string, 3> _texturePath;
            /**
             * @brief text in button
             * 
             */
            std::string _text;
            /**
             * @brief text size
             * 
             */
            int _textSize;
            /**
             * @brief 3D position for text
             * 
             */
            coords _textPos;
    };

}

#endif /* !BUTTON_HPP_ */
