/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#include "SceneNewGame.hpp"

SceneNewGame::SceneNewGame(Setting &settings) : AScene(settings)
{
}

SceneNewGame::~SceneNewGame()
{
}

Scenes SceneNewGame::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.gameLoop()) {

    }
    if (lib.gameLoop())
        return (Scenes::QUIT);
    return (Scenes::GAME);
}