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

#include "Object/UiObject/UiObject.hpp"
#include "Raylib/Raylib.hpp"
#include "Object/AObject.hpp"
#include "Object/Particles.hpp"
#include "Object/Ground/Ground.hpp"
#include "Object/UiObject/UiObject.hpp"
#include "Object/UiObject/UiGame/FrameUI.hpp"
#include "Object/UiObject/UiGame/LifeGame.hpp"
#include "Object/UiObject/Button/Button.hpp"
#include "Object/UiObject/UiGame/ColorPlayer.hpp"
#include "Object/UiObject/UiGame/TexteUi.hpp"
#include "Object/Collisionable/Wall/Wall.hpp"
#include "Object/Collisionable/Destructible/Movable/PowerUps/PowerUps.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath{
    "asset/background_asset/ground.png",
    "asset/OBJFormat/ground.obj",
    "asset/bonus/arrow.obj"};

SceneMaxime::SceneMaxime(Setting &settings) : AScene(settings), _pressed(false), _isPaused(false), _scenePause(settings)
{
    /////////////////////////////START CEMENT//////////////////////:

    _objects.emplace_back(std::make_shared<Ground>(
        coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(_assetsPath.at(0), _assetsPath.at(1))));
    auto const &carre = std::make_unique<FrameUI>();
    for (auto const &carr : carre->getBorder())
        _objects.emplace_back(std::make_shared<BorderPlayer>(carr));
    for (unsigned int i = 0; i != _posTank.size(); i++)
    {
        auto tmp = _objects.emplace_back(std::make_shared<Tank>( _settings._players.at(i).name, coords(_posTank[i].first, 0, _posTank[i].second), coords(10, 10, 10), 8, std::make_pair(Tank::sable, Tank::body), std::make_pair(Tank::darkGreen, Tank::cannon)));
        if (i == 0)
            setInputsTank(_settings._keysPlayerOne, _objects.back());
        else if (i == i) {
            setInputsTank(_settings._keysPlayerTwo, _objects.back());
        }
        auto tank = std::dynamic_pointer_cast<Tank>(_objects.back());
        for (int y = 0; y != tank->getLife(); y++)
            _objects.emplace_back(std::make_shared<LifeGame>(
                tank->getName(), coords(_uiLifePosPlayer[i].first + (30 * y), _uiLifePosPlayer[i].second)));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_playerPos[i].first, _playerPos[i].second),
            std::make_pair(50, 50), dynamic_cast<Tank &>(*tmp).getName(), 20,
            1, std::make_pair(RGB(150), RGB())));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_scorePos[i].first, _scorePos[i].second),
            std::make_pair(50, 50),
            std::to_string(dynamic_cast<Tank &>(*tmp).getScore()), 20, 1,
            std::make_pair(RGB(150), RGB())));
    }
    auto const &colorPlayer = std::make_unique<ColorPlayer>();
    for (auto &color : colorPlayer->getPosColorSquare())
    {
        _objects.emplace_back(std::make_shared<UiObject>(color));
    }
    /////////////////////////////END CLEMENT//////////////////////:
    /////////////////////////////START Maxime//////////////////////:
    std::vector<std::pair<int, int>> size;

    for (auto &i : _objects)
        if (i->getTypeField().isTank)
            size.push_back(std::make_pair(static_cast<int>(i->getPosition().first), static_cast<int>(i->getPosition().third)));
    auto const &map = std::make_unique<Map>(size);

    map->createDestructibleMap(std::make_pair(-6, -7), std::make_pair(0, 0));
    map->createDestructibleMap(std::make_pair(-6, 1), std::make_pair(-1, -7));
    map->createDestructibleMap(std::make_pair(0, 0), std::make_pair(6, 7));
    map->createDestructibleMap(std::make_pair(0, -7), std::make_pair(6, 0));

    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));

    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
    setInputFunction(Raylib::ESCAPE, [&]() {
        _isPaused = !_isPaused;
    });

    setInputFunction(Raylib::SPACE, [&]() {
        _pressed = true;
    });
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));
    for (auto const &block : map->_objectDestructibleList)
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));

    /////////////////////////////END MAXIME//////////////////////:
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

void SceneMaxime::manageHeart(const std::string &name, const int life)
{
    std::size_t idx = 0;
    std::vector<int> tmp;

    for (unsigned int i = 0; i != _objects.size(); i++)
    {
        if (_objects[i]->getTypeField().isLife)
        {
            auto heart = std::dynamic_pointer_cast<LifeGame>(_objects[i]);
            if (heart->getName() == name)
            {
                if (idx == life)
                {
                    _listPosHeart.push_back(i);
                }
                else
                    ++idx;
            }
        }
    }
}

void SceneMaxime::checkHeart() noexcept
{
    if (_listPosHeart.size() != 0)
    {
        for (auto &i : _listPosHeart)
        {
            _objects.erase(_objects.begin() + i);
        }
        _listPosHeart.clear();
    }
}

Scenes SceneMaxime::run(Raylib &lib)
{
    bool isLock = false;

    while (lib.gameLoop())
    {
        triggerInputActions(lib);
        lib.printObjects(_objects);
        if (_pressed && !isLock) {
            _pressed = false;
            isLock = true;
            for (auto it = _objects.begin(); it != _objects.end(); ) {
                if (it->get()->getTypeField().isDestructible == true) {
                    _objects.emplace_back(std::make_shared<PowerUps>(coords(it->get()->getPosition().first,it->get()->getPosition().second + 1.0f, it->get()->getPosition().third), coords(1, 1, 1), std::pair<std::string, std::string>("", _assetsPath.at(2))));
                    _objects.emplace_back(std::make_shared<Particles>(_objects.back()->getPosition(), std::make_pair(1.f, 1), 1.1f, 0.05f, std::make_pair(RGB(218, 165, 32), RGB()), 25, coords(.0f, .001f, .0f)));
                    it = _objects.erase(it);
                    break;
                } else
                    ++it;
            }
        }
        if (_isPaused) {
            auto newScene = _scenePause.run(lib);
            if (newScene != Scenes::GAME)
                return (newScene);
            _isPaused = false;
        }
        if (_pressed && !isLock) {
            _pressed = false;
            isLock = true;
            for (auto it = _objects.begin(); it != _objects.end();) {
                if (it->get()->getTypeField().isDestructible == true)
                {
                    _objects.emplace_back(std::make_shared<PowerUps>(coords(it->get()->getPosition().first, it->get()->getPosition().second + 1.0f, it->get()->getPosition().third), coords(0, 0, 0), std::pair<std::string, std::string>("", _assetsPath.at(2))));
                    _objects.emplace_back(std::make_shared<Particles>(coords(it->get()->getPosition().first, it->get()->getPosition().second + 1.0f, it->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(218, 165, 32), RGB()), 10, coords(0, 0.2f, 0)));
                    it = _objects.erase(it);
                    break;
                }
                else
                    ++it;
            }
        }
        for (auto &it : _objects) {
            if (it->getTypeField().isTank) {
                auto tank = std::dynamic_pointer_cast<Tank>(it);
                manageHeart(tank->getName(), tank->getLife());
            }
            if (it->getTypeField().isParticule == true)
                std::dynamic_pointer_cast<Particles>(it)->update();
            else if (it->getTypeField().isPowerUps == true)
                std::dynamic_pointer_cast<PowerUps>(it)->rotate(0.5f);
        }
        checkHeart();
    }
    return (Scenes::QUIT);
}