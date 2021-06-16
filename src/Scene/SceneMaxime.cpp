/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#include "SceneMaxime.hpp"
#include "Core.hpp"
#include "Map/Map.hpp"
#include <bits/stdc++.h>

#include "Raylib/Raylib.hpp"
#include "Object/AObject.hpp"
#include "Object/Ground/Ground.hpp"
#include "Object/UiObject/UiObject.hpp"
#include "Object/Collisionable/Wall/Wall.hpp"
#include "Object/Collisionable/Destructible/Movable/PowerUps/PowerUps.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath {
    "asset/background_asset/ground.png",
    "asset/OBJFormat/ground.obj",
    "asset/bonus/arrow.obj"
};

SceneMaxime::SceneMaxime(Setting &settings) : AScene(settings), _pressed(false)
{
    auto const &map = std::make_unique<Map>();
    map->createDestructibleMap(std::make_pair(-5, -5), std::make_pair(5, 5));
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));

    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });

    setInputFunction(Raylib::SPACE, [&]() {
        _pressed = true;
    });
    _objects.emplace_back(std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(_assetsPath.at(0), _assetsPath.at(1))));
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));
    for (auto const &block : map->_objectDestructibleList) {
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
        std::dynamic_pointer_cast<DestructibleWall>(_objects.back())->setRotationAngle(90.0f);
        std::dynamic_pointer_cast<DestructibleWall>(_objects.back())->setRotationAxis(coords(0, 1, 0));
    }
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

Scenes SceneMaxime::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.gameLoop()) {
        triggerInputActions(lib);
        lib.printObjects(_objects);
        if (_pressed) {
            _pressed = false;
            for (auto it = _objects.begin(); it != _objects.end(); ) {
                if (it->get()->getTypeField().isDestructible == true) {
                    _objects.emplace_back(std::make_shared<PowerUps>(coords(it->get()->getPosition().first,it->get()->getPosition().second + 1.0f, it->get()->getPosition().third), std::make_pair(0, 0), std::pair<std::string, std::string>("", _assetsPath.at(2))));
                    _objects.back()->setScale(0.03f);
                    it = _objects.erase(it);
                    break;
                } else
                    ++it;
            }
        }
    }
    return (Scenes::QUIT);
}