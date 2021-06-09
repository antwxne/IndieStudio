/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneRobin
*/

#include "SceneRobin.hpp"

SceneRobin::SceneRobin()
{
    //init _objects
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

void SceneRobin::run(Raylib &lib)
{
    while (lib.gameLoop()) {
        BeginDrawing();
        //2D display here
        EndDrawing();
    }
}