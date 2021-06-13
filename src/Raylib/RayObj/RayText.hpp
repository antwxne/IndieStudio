/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayText
*/

#ifndef RAYTEXT_HPP_
#define RAYTEXT_HPP_

#include "Raylib/RayObj/IRayObj.hpp"

class RayText : public IRayObj
{
    public:
        RayText(std::string text);
        ~RayText() = default;
        void draw(const std::pair<int, int> &pos, const std::pair<int, int> &size, const float scale, const std::pair<struct RGB, struct RGB> color) final;

    private:
        std::string _text;
};

#endif /* !RAYTEXT_HPP_ */
