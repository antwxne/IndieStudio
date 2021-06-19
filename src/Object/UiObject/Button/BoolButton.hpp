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
    /**
     * @brief on/off button
     * @class BoolButton
     * 
     */
    class BoolButton : public Button
    {
        public:
            /**
             * @brief Construct a new Bool Button object
             * 
             * @param pos 
             * @param size 
             * @param path 
             * @param text 
             * @param sizeText 
             * @param scale 
             * @param color 
             */
            BoolButton(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, const std::string &text, int sizeText, float scale, std::pair<RGB, RGB> color);
            /**
             * @brief Destroy the Bool Button object
             * 
             */
            ~BoolButton();
            /**
             * @brief Set the State object
             * 
             * @param pos 
             * @param clicked 
             */
            void setState(const std::pair<float, float> &pos, bool clicked);
            /**
             * @brief Get the Pressed object
             * 
             * @return true 
             * @return false 
             */
            bool getPressed() const noexcept;

        private:
            /**
             * @brief bool pressed ?
             * 
             */
            bool _pressed;
    };

}

#endif /* !BOOLBUTTON_HPP_ */
