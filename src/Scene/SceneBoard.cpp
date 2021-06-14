/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneBoard
*/

#include "Core.hpp"
#include "SceneBoard.hpp"

SceneBoard::SceneBoard(std::shared_ptr<Setting> settings) : AScene(settings)
{
}

SceneBoard::~SceneBoard()
{
    _objects.clear();
}

Scenes SceneBoard::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.gameLoop()) {

    }
    if (lib.gameLoop())
        return (Scenes::QUIT);
    return (Scenes::MENU);
}