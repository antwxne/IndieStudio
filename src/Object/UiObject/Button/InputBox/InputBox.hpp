/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** InputBox
*/

#ifndef INPUTBOX_HPP_
#define INPUTBOX_HPP_

#include "UiObject/Button/Button.hpp"

namespace button {
    /**
     * @class InputBox
     * @brief box in menu to get input
     * 
     */
    class InputBox : public Button
    {
        public:
            /**
             * @brief Construct a new Input Box object
             * 
             * @param pos 
             * @param size 
             * @param path 
             * @param sizeText 
             * @param maxString 
             * @param scale 
             * @param color 
             */
            InputBox(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, int sizeText, int maxString, float scale, std::pair<RGB, RGB> color);
            /**
             * @brief Destroy the Input Box object
             * 
             */
            ~InputBox();
            /**
             * @brief 
             * 
             * @param input 
             * @param pos 
             */
            void changeText(char input, const std::pair<float, float> &pos);
        private:
            /**
             * @brief max characters input
             * 
             */
            int _maxText;
    };

}

#endif /* !INPUTBOX_HPP_ */
