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
#include "Object/Collisionable/Wall.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath {
    "asset/box_test/box-textures.png",
    "asset/box_test/Box.obj",
};

SceneMaxime::SceneMaxime(Setting &settings) : AScene(settings)
{
    auto const &map = std::make_unique<Map>();

    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
    map->createDestructibleMap(std::make_pair(0, 0), std::make_pair(5, 5));
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));
    for (auto const &block : map->_objectDestructibleList)
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

Scenes SceneMaxime::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.gameLoop()) {
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}