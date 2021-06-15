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
#include "Object/Ground/Ground.hpp"
#include "Object/UiObject/UiObject.hpp"
#include "Object/Collisionable/Wall.hpp"
#include "Object/UiObject/UiGame/FrameUI.hpp"
#include "Object/UiObject/UiGame/LifeGame.hpp"
#include "Player/Player.hpp"
#include "Object/UiObject/Button/Button.hpp"
#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath {
    "asset/background_asset/ground.png",
    "asset/OBJFormat/ground.obj",
};

SceneMaxime::SceneMaxime(Setting &settings) : AScene(settings)
{
    auto const &map = std::make_unique<Map>();
    map->createDestructibleMap(std::make_pair(-5, -5), std::make_pair(5, 5));
    map->createDestructibleMap(std::make_pair(-5, -5), std::make_pair(6, 6));
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));

    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
    _objects.emplace_back(std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(_assetsPath.at(0), _assetsPath.at(1))));
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));
    for (auto const &block : map->_objectDestructibleList) {
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
        _objects.back()->set3d(true);
        _objects.back()->setScale(1.0f);
    }
    auto const &carre = std::make_unique<FrameUI>();
    for (auto const &carr : carre->_border) {
        _objects.emplace_back(std::make_shared<BorderPlayer>(carr));
    }
    auto const &life = std::make_unique<LifeGame>();
    for (auto const &lif : life->_posLife) {
        _objects.emplace_back(std::make_shared<FullSquare>(lif));
    }
    for (unsigned int i = 0; i != _playerName.size(); i++) {
        _objects.emplace_back(std::make_shared<button::Button>(coords(_playerPos[i].first,_playerPos[i].second), std::make_pair(50,50), "", _playerName[i], 20, 1, std::make_pair(
            RGB(150), RGB())));
    }
    for (unsigned int i = 0; i != _scorePos.size(); i++) {
        _objects.emplace_back(std::make_shared<button::Button>(coords(_scorePos[i].first,_scorePos[i].second), std::make_pair(50,50), "", std::to_string(_playerScore[i]), 20, 1, std::make_pair(
            RGB(150), RGB())));
    }
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

Scenes SceneMaxime::run(Raylib &lib, Scenes const &prevScene)
{
    std::cout << _settings._players.at(0).name << " " << _settings._players.at(2).name << " " << _settings._players.at(2).ai << std::endl;
    while (lib.gameLoop()) {
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}