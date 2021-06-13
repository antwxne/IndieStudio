/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaySquare
*/

#ifndef RAYSQUARE_HPP_
#define RAYSQUARE_HPP_

#include "Raylib/RayObj/IRayObj.hpp"

class RaySquare : public IRayObj
{
    public:
        RaySquare(objType_e type);
        ~RaySquare() = default;
        void draw(IObject &obj) final;
    private:
        objType_e _type;
};

#endif /* !RAYSQUARE_HPP_ */
