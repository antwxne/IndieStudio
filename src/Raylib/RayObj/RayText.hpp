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
        void draw(IObject &obj) final;

    private:
        std::string _text;
};

#endif /* !RAYTEXT_HPP_ */
