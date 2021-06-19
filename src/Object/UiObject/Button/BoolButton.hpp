/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** BoolButton
*/

#ifndef BOOLBUTTON_HPP_
#define BOOLBUTTON_HPP_

#include "Button.hpp"

namespace button {

    class BoolButton : public Button
    {
        public:
            BoolButton(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color);
            ~BoolButton();
            void setState(const std::pair<float, float> &pos, bool clicked);
            bool getPressed() const noexcept;

        private:
            bool _pressed;
    };

}

#endif /* !BOOLBUTTON_HPP_ */
