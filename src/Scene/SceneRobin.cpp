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

SceneRobin::SceneRobin(std::shared_ptr<Setting> settings) : AScene(settings)
{
    setInputFunction(Raylib::ENTER, [](){std::cout << "ENTERRRRRRR" << std::endl;});
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

Scenes SceneRobin::run(Raylib &lib, Scenes const &prevScene)
{
    int input = 0;

    while (lib.gameLoop()) {
        triggerInputActions(lib);
    }
    return (Scenes::QUIT);
}