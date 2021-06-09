/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#include "SceneMaxime.hpp"

SceneMaxime::SceneMaxime()
{
    //init _objects
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

void SceneMaxime::run(Raylib &lib)
{
    while (lib.gameLoop()) {
        lib.drawingLoopBegin();
        lib.drawingLoopEnd();
    }
}