/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneRobin
*/

#include <iostream>

#include "SceneRobin.hpp"
#include "Core.hpp"

SceneRobin::SceneRobin()
{
    //init _objects
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

int SceneRobin::run(Raylib &lib)
{
    int input = 0;

    while (lib.gameLoop()) {
        triggerInputFuncs(lib);
        BeginDrawing();
        //2D display here
        EndDrawing();
    }
    return (Core::Scenes::QUIT);
}