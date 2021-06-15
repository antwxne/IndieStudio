/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#ifndef SCENENEWGAME_HPP_
#define SCENENEWGAME_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

class SceneNewGame : public AScene
{
    public:
        SceneNewGame(Setting & settings);
        ~SceneNewGame();
        Scenes run(Raylib &lib, Scenes const &prevScene) final;
};

#endif /* !SCENENEWGAME_HPP_ */
