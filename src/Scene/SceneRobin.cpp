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
#include "Map/Map.hpp"


#include "Raylib/Raylib.hpp"
#include "Object/AObject.hpp"
#include "Object/Ground/Ground.hpp"
#include "Object/UiObject/UiObject.hpp"
#include "Object/Collisionable/Wall/Wall.hpp"

SceneRobin::SceneRobin(Setting &settings) : AScene(settings)
{
    _objects.emplace_back(std::make_shared<Tank>("grosTankSaMere", coords(0,0,0), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
    setInputsTank(_settings._keysPlayerOne, _objects.back());
    // _objects.emplace_back(std::make_shared<Tank>("petitTankMignon", coords(6,0,0), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
    // setInputsTank(_settings._keysPlayerTwo, _objects.back());

    std::vector<std::pair<float, float>> size;
    for (auto &i : _objects)
        if (i->getTypeField().isTank) {
            size.push_back(std::make_pair(i->getPosition().first, i->getPosition().third));
        }
    auto const &map = std::make_unique<Map>(size);

    map->createDestructibleMap(std::make_pair(-5, -5), std::make_pair(5, 5));
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));

    _objects.emplace_back(std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(core::groundTexture, core::groundModel)));
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));
    for (auto const &block : map->_objectDestructibleList)
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

Scenes SceneRobin::run(Raylib &lib)
{
    while (lib.gameLoop()) {
        triggerInputActions(lib);
        lib.printObjects(_objects);
        for (auto &object : _objects) {
            if (object->getTypeField().isTank) {
                auto tank = std::dynamic_pointer_cast<Tank>(object);
                tank->moveBullets();
            }
        }
    }
    return (Scenes::QUIT);
}