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

SceneMaxime::SceneMaxime(std::shared_ptr<Setting> settings) : AScene(settings)
{
    auto const &map = std::make_unique<Map>();

    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
    //map->createDestructibleMap(std::make_pair(0, 0), std::make_pair(5, 5));
    // map->createContourMap(10, 10);
    // for (auto const &block : map->_objectNoDestructibleList) {
    //     std::cout << "[BLOCK] position => " << block.getPosition().first << " " << block.getPosition().second << " " << block.getPosition().third << "\n";
    //     _objects.emplace_back(std::make_shared<Wall>(block));
    //     _objects.back()->set3d(true);
    //     _objects.back()->setScale(0.02f);
    // }
    _objects.emplace_back(std::make_shared<Wall>(coords(0, 0, 0), std::make_pair(0, 0), std::make_pair(_assetsPath.at(0), _assetsPath.at(1))));
    _objects.back()->set3d(true);
    _objects.back()->setScale(0.02f);
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