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
#include "Object/UiObject/UiGame/ColorPlayer.hpp"
#include "Object/UiObject/UiGame/TexteUi.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath{
    "asset/background_asset/ground.png", "asset/OBJFormat/ground.obj",};

SceneMaxime::SceneMaxime(Setting &settings) : AScene(settings)
{
    auto const &map = std::make_unique<Map>();
    map->createDestructibleMap(std::make_pair(-5, -5), std::make_pair(5, 5));
    map->createDestructibleMap(std::make_pair(-5, -5), std::make_pair(6, 6));
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));

    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
    _objects.emplace_back(
        std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22),
            std::pair<std::string, std::string>(_assetsPath.at(0),
                _assetsPath.at(1))));
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
    for (unsigned int i = 0; i != _playerPos.size(); i++) {
        auto tmp = _objects.emplace_back(
            std::make_shared<Tank>(_settings._players.at(i).name,
                coords(0, 0, 0), std::make_pair(10, 10),
                std::make_pair(Tank::sandCamo, Tank::body),
                std::make_pair(Tank::greenCamo, Tank::turret)));
        auto tank = std::dynamic_pointer_cast<Tank>(_objects.back());
        for (int y = 0; y != tank->getLife(); y++) {
            _objects.emplace_back(std::make_shared<LifeGame>(tank->getName(),
                coords(_uiLifePosPlayer[i].first + (30 * y),
                    _uiLifePosPlayer[i].second)));
        }
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_playerPos[i].first, _playerPos[i].second),
            std::make_pair(50, 50), dynamic_cast<Tank &>( *tmp).getName(), 20,
            1, std::make_pair(RGB(150), RGB())));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_scorePos[i].first, _scorePos[i].second),
            std::make_pair(50, 50),
            std::to_string(dynamic_cast<Tank &>( *tmp).getScore()), 20, 1,
            std::make_pair(RGB(150), RGB())));
    }
    auto const &colorPlayer = std::make_unique<ColorPlayer>();
    for (auto &color : colorPlayer->_posColorSquare) {
        _objects.emplace_back(std::make_shared<UiObject>(color));
    }
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

void SceneMaxime::manageHeart(const std::string &name, const int life)
{
    std::size_t idx = 0;
    std::vector<int> tmp;

    for (unsigned int i = 0; i != _objects.size(); i++) {
        if (_objects[i]->getTypeField().isLife) {
            auto heart = std::dynamic_pointer_cast<LifeGame>(_objects[i]);
            if (heart->getName() == name) {
                if (idx == life) {
                    _iterator.push_back(i);
                } else
                    ++idx;
            }
        }
    }
}

Scenes SceneMaxime::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.gameLoop()) {
        for (auto &tmp : _objects) {
            if (tmp->getTypeField().isTank) {
                auto test = std::dynamic_pointer_cast<Tank>(tmp);
                manageHeart(test->getName(), test->getLife());
            }
        }
        if (_iterator.size() != 0) {
            for (auto &i : _iterator)
                _objects.erase(_objects.begin() + i);
            _iterator.clear();
        }
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}