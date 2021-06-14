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
#include "Tank.hpp"

SceneRobin::SceneRobin(std::shared_ptr<Setting> settings) : AScene(settings)
{
    setInputFunction(Raylib::ENTER, [](){std::cout << "ENTERRRRRRR" << std::endl;});
    Bullet bullet({0, 0, 0});
    _objects.emplace_back(std::make_shared<Tank>(Tank({0, 0, 0}, {30, 30}, {"", ""}, {"", ""})));
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