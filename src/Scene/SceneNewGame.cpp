/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#include "SceneNewGame.hpp"

<<<<<<< HEAD
SceneNewGame::SceneNewGame(Setting &settings) : AScene(settings)
=======
SceneNewGame::SceneNewGame(Setting & settings) : AScene(settings)
>>>>>>> 45b6de4b5229598a7bd0f302740cc8b3f941e278
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