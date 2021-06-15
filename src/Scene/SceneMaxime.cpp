/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#include "SceneMaxime.hpp"
#include "Core.hpp"
#include "raylib.h"
#include "Map/Map.hpp"
#include <bits/stdc++.h>

#include "Object/UiObject/UiObject.hpp"
#include "Raylib/Raylib.hpp"
#include "Object/AObject.hpp"
#include "Object/Collisionable/Wall.hpp"
#include "Object/UiObject/UiGame/RectangleUI.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath{
    "asset/box_test/box-textures.png", "asset/box_test/Box.obj",};

SceneMaxime::SceneMaxime(std::shared_ptr<Setting> settings) : AScene(settings)
{
    auto const &map = std::make_unique<Map>();

    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
    map->createDestructibleMap(std::make_pair(0, 0), std::make_pair(5, 5));
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));
    for (auto const &block : map->_objectNoDestructibleList) {
        _objects.emplace_back(std::make_shared<Wall>(block));
        _objects.back()->set3d(true);
        _objects.back()->setScale(1.0f);
    }
    for (auto const &block : map->_objectDestructibleList) {
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
        _objects.back()->set3d(true);
        _objects.back()->setScale(1.0f);
    }
    //for (unsigned int i = 0; i != _uiGamePos.size(); i++) {
    /*auto tmp = std::make_shared<UiObject>(
        coords(_uiGamePos[i].first, _uiGamePos[i].second),
        std::make_pair(_uiGameSize[i].first, _uiGameSize[i].second), "", 9,
        std::make_pair(RGB(0, 0, 0), RGB()));
    tmp->setRect(true);*/
    auto const &carre = std::make_unique<RectangleUI>();
    for (auto const &carr : carre->_border) {
        _objects.emplace_back(std::make_shared<BorderPlayer>(carr));
    }
    for (auto const &i: _uiLifePos) {
        auto tmp = std::make_shared<UiObject>(coords(i.first, i.second),
            std::make_pair(20, 20), "", 1,
            std::make_pair(RGB(150, 150, 150), RGB()));
        tmp->setFillRect(true);
        _objects.emplace_back(tmp);
    }
    // _objects.emplace_back(std::make_shared<Wall>(coords(0, 0, 0), std::make_pair(0, 0), std::make_pair(_assetsPath.at(0), _assetsPath.at(1))));
    // _objects.back()->set3d(true);
    // _objects.back()->setScale(0.02f);
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