/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#include "SceneNewGame.hpp"

SceneNewGame::SceneNewGame(std::shared_ptr<Setting> settings) : AScene(settings)
{
}

SceneNewGame::~SceneNewGame()
{
}

void SceneNewGame::initAssets()
{

}

Scenes SceneNewGame::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.getKeyPressed() != KEY_ENTER) {

    }
    return (Scenes::GAME);
}