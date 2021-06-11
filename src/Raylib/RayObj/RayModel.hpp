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
        void draw(IObject &obj) final;

    protected:
    private:
        Model _model;
};

#endif /* !RAYMODEL_HPP_ */
