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

SceneRobin::SceneRobin(Setting & settings) : AScene(settings)
{
    // setInputFunction(Raylib::ENTER, [](){std::cout << "ENTERRRRRRR" << std::endl;});
    _objects.emplace_back(std::make_shared<Tank>(Tank({10,10,10}, {10, 10}, {Tank::body, Tank::sandCamo}, {Tank::turret, Tank::greenCamo})));
    std::cout << "just emplaced isTank: " << _objects.back()->getTypeField().isTank << std::endl;
    // _objects.back()->set3d(true);
    // _objects.back()->setScale(1.0f);
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

Scenes SceneRobin::run(Raylib &lib, Scenes const &prevScene)
{
    for (auto &i : _objects) {
        std::cout << "is3D: " << i->getTypeField().is3D << std::endl;
        std::cout << "isCollis: " << i->getTypeField().isCollisionable << std::endl;
        std::cout << "isTank: " << i->getTypeField().isTank << std::endl;
    }
    // while (lib.gameLoop()) {
        // triggerInputActions(lib);
        // lib.printObjects(_objects);
    // }
    return (Scenes::QUIT);
}