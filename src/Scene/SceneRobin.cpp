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

// auto const &tank = std::dynamic_pointer_cast<Tank>(i);
// auto const &derived = std::dynamic_pointer_cast<CollisionableObject>(i);
// auto const &cannonCasted = static_cast<CollisionableObject>(tank->getCannon());
// drawModel(derived->getModel(), derived->getTexture(), derived->getPosition(), i->getScale(), i->getColors().first);
// drawModel(cannonCasted.getModel(), cannonCasted.getTexture(), cannonCasted.getPosition(), cannonCasted.getScale(), cannonCasted.getColors().first);