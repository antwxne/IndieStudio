/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneRobin
*/

#include <iostream>
#include <functional>

#include "SceneRobin.hpp"
#include "Core.hpp"

SceneRobin::SceneRobin()
{
    setInputFunction(Raylib::ENTER, [](){std::cout << "ENTERRRRRRR" << std::endl;});
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

int SceneRobin::run(Raylib &lib)
{
    int input = 0;

    while (lib.gameLoop()) {
        triggerInputActions(lib);
    }
    return (Core::Scenes::QUIT);
}