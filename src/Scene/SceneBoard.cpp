/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneBoard
*/

#include "SceneBoard.hpp"

SceneBoard::SceneBoard(Setting &settings) : AScene(settings)
{
}

SceneBoard::~SceneBoard()
{
    _objects.clear();
}

Scenes SceneBoard::run(Raylib &lib)
{
    while (1) {
    }
}