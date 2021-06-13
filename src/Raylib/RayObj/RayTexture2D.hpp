/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayTexture2D
*/

#ifndef RAYTEXTURE2D_HPP_
#define RAYTEXTURE2D_HPP_

#include "Raylib/RayObj/IRayObj.hpp"

class RayTexture2D : public IRayObj
{
    public:
        RayTexture2D(std::string filepath);
        ~RayTexture2D();
        void draw(IObject &obj) final;

    private:
        Texture2D _texture;
};

#endif /* !RAYTEXTURE2D_HPP_ */
