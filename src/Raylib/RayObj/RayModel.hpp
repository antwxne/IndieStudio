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
        RayModel(const std::string &texture, const std::string &model);
        ~RayModel();
        const void setModel(std::string const &Filepath);
        const void setTexture(std::string const &Filepath);
        void draw(const std::pair<int, int> &pos, const std::pair<int, int> &size, const float scale, const std::pair<struct RGB, struct RGB> color) final;

    private:
        Texture2D _texture;
        Model _model;
        bool _isSet;
};

#endif /* !RAYMODEL_HPP_ */
