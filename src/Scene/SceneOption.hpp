/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#ifndef SCENEOPTION_HPP_
#define SCENEOPTION_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

class SceneOption : public AScene
{
    public:
        SceneOption(Setting & settings);
        ~SceneOption();
        Scenes run(Raylib &lib, Scenes const &prevScene) final;
    
    private:
        bool _quit;
};

#endif /* !SCENEOPTION_HPP_ */
