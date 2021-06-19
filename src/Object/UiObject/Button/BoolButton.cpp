/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** BoolButton
*/

#include "BoolButton.hpp"

namespace button {

    BoolButton::BoolButton(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color)
        : Button(pos, size, path, text, sizeText, scale, color), _pressed(false)
    {
    }

    BoolButton::~BoolButton()
    {
    }

    void BoolButton::setState(const std::pair<float, float> &pos, bool clicked)
    {
        static bool on = false;

        if (isInside(pos)) {
            if (clicked) {
                setTexture(_texturePath.at(buttonState_e::CLICKED));
                if (!on)
                    _pressed = !_pressed;
                on = true;
            } else {
                setTexture(_texturePath.at(buttonState_e::OVER));
                on = false;
            }
        } else {
            setTexture(_texturePath.at(_pressed ? buttonState_e::OVER : buttonState_e::NOTHING));
        }
    }

    bool BoolButton::getPressed() const noexcept
    {
        return (_pressed);
    }


}
