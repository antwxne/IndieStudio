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

SceneRobin::SceneRobin(Setting &settings) : AScene(settings)
{
    // setInputFunction(Raylib::ENTER, [](){std::cout << "ENTERRRRRRR" << std::endl;});
    _objects.emplace_back(std::make_shared<Tank>(coords(0,0,0), std::make_pair(10, 10), std::make_pair(Tank::sandCamo, Tank::body), std::make_pair(Tank::greenCamo, Tank::turret)));
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

Scenes SceneRobin::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.gameLoop()) {
        triggerInputActions(lib);
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}