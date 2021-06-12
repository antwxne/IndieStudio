/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayModel
*/

#ifndef RAYMODEL_HPP_
#define RAYMODEL_HPP_

#include "Raylib/RayObj/IRayObj.hpp"

class RayModel : public IRayObj
{
    public:
        RayModel();
        ~RayModel();
        void setTexture(std::string const &path);
        void setModel(std::string const &path);
        void setTextureToModel(void);
        void draw(IObject &obj) final;

    private:
        Model _model;
        Texture2D _texture;
};

#endif /* !RAYMODEL_HPP_ */
