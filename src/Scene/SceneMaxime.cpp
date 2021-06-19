/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#include "SceneMaxime.hpp"
#include <bits/stdc++.h>

#include "Core.hpp"
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

SceneMaxime::SceneMaxime(Setting &settings) : AScene(settings), _pressed(false), _isPaused(false), _scenePause(settings)
{
    /////////////////////////////START CEMENT//////////////////////:

    _objects.emplace_back(std::make_shared<Ground>(
        coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(core::groundTexture, core::groundModel)));
    auto const &carre = std::make_unique<FrameUI>();
    for (auto const &carr : carre->getBorder())
        _objects.emplace_back(std::make_shared<BorderPlayer>(carr));
    for (unsigned int i = 0; i != _posTank.size(); i++) {
        auto lastTank = _objects.back();
        if (settings.load == true) {
            auto tanks = Tank::readTank();
            lastTank = _objects.emplace_back(std::make_shared<Tank>(tanks[i].getName(), coords(tanks[i].getPosition().first, 0, tanks[i].getPosition().third), coords(10,10,10),8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        } else {
            lastTank = _objects.emplace_back(
                std::make_shared<Tank>(_settings._playersSettings.at(i).name,
                    coords(_posTank[i].first, 0, _posTank[i].second),
                    coords(10, 10, 10), 8,
                    std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                    std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        }
        if (i == 0)
            setInputsTank(_settings._keysPlayerOne, lastTank);
        else if (i == i) {
            setInputsTank(_settings._keysPlayerTwo, lastTank);
        }
        auto tank = std::dynamic_pointer_cast<Tank>(lastTank);
        std::cout << tank->getName() << std::endl;
        for (int y = 0; y != tank->getLife(); y++) {
            _objects.emplace_back(std::make_shared<LifeGame>(tank->getName(),
                coords(_uiLifePosPlayer[i].first + (30 * y),
                    _uiLifePosPlayer[i].second)));
        }
        for (int y = 0; y != tank->getLife(); y++)
            _objects.emplace_back(std::make_shared<LifeGame>(
                tank->getName(), coords(_uiLifePosPlayer[i].first + (30 * y), _uiLifePosPlayer[i].second)));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_namePlayerPos[i].first, _namePlayerPos[i].second),
            std::make_pair(50, 50), dynamic_cast<Tank &>(*lastTank).getName(), 20,
            1, std::make_pair(RGB(150), RGB())));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_scorePos[i].first, _scorePos[i].second),
            std::make_pair(50, 50),
            std::to_string(dynamic_cast<Tank &>(*lastTank).getScore()), 20, 1,
            std::make_pair(RGB(150), RGB())));
    }
    auto const &colorPlayer = std::make_unique<ColorPlayer>();
    for (auto &color : colorPlayer->getPosColorSquare())
    {
        _objects.emplace_back(std::make_shared<UiObject>(color));
    }
    /////////////////////////////END CLEMENT//////////////////////:
    /////////////////////////////START Maxime//////////////////////:
    std::vector<std::pair<float, float>> size;

    for (auto &i : _objects)
        if (i->getTypeField().isTank)
            size.push_back(std::make_pair(static_cast<int>(i->getPosition().first), static_cast<int>(i->getPosition().third)));
    _map = std::make_unique<Map>(size);

    // std::cout << "CA MARCHE LALALLAL0\n";
    if (settings.load == false) {
    _map->createDestructibleMap(std::make_pair(-6, -7), std::make_pair(0, 0));
    _map->createDestructibleMap(std::make_pair(-6, 1), std::make_pair(-1, -7));
    _map->createDestructibleMap(std::make_pair(0, 0), std::make_pair(6, 7));
    _map->createDestructibleMap(std::make_pair(0, -7), std::make_pair(6, 0));
    } else
        _map->readDestructibleList();
    _map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));
    std::cout << "CA MARCHE BITEPis\n";
    std::cout << "Size == " << std::endl;
    std::cout << _map->_objectNoDestructibleList.size()  << std::endl;
    for (auto const &block : _map->_objectNoDestructibleList) {
        std::cout << " PREMIERE TAILLE == " << block.getSize().first << std::endl;
        _objects.emplace_back(std::make_shared<Wall>(block));
    }
    std::cout << "CA MARCHE LOLOLO\n";
    for (auto const &block : _map->_objectDestructibleList) {
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
    }
    _settings.load = false;
    std::cout << "CA MARCHE BITE\n";
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
            if (heart->getName() == name) {
                tmp.push_back(i);
                ++idx;
                }
        }
    }
    if (idx != life) {
        for (auto &p : tmp) {
            idx--;
            auto heart = std::dynamic_pointer_cast<LifeGame>(_objects[p]);
            heart->setTransparancy(true);
            if (idx == life) {
                break;
            }
        }
    }
}

void SceneMaxime::saveTanks() noexcept
{
    std::vector<Tank> ki;
    for (auto &it: _objects) {
        if (it->getTypeField().isTank) {
            auto tank = std::dynamic_pointer_cast<Tank>(it);
            ki.push_back(dynamic_cast<Tank &>(*tank));
        }
    }
    Tank::writeTankList(ki);
}

Scenes SceneMaxime::run(Raylib &lib)
{
    bool isLock = false;

    while (lib.gameLoop())
    {
        lib.displayMusic(core::_gameMusic, _settings._musicVol);
        triggerInputActions(lib);
        lib.printObjects(_objects);
        if (_pressed && !isLock) {
            _pressed = false;
            isLock = true;
            for (auto it = _objects.begin(); it != _objects.end(); ) {
                if (it->get()->getTypeField().isDestructible == true) {
                    _objects.emplace_back(std::make_shared<PowerUps>(coords(it->get()->getPosition().first,it->get()->getPosition().second + 1.0f, it->get()->getPosition().third), coords(1, 1, 1), std::pair<std::string, std::string>("", core::powerUpModel)));
                    _objects.emplace_back(std::make_shared<Particles>(_objects.back()->getPosition(), std::make_pair(1.f, 1), 1.1f, 0.05f, std::make_pair(RGB(218, 165, 32), RGB()), 25, coords(.0f, .001f, .0f)));
                    it = _objects.erase(it);
                    break;
                } else
                    ++it;
            }
        }
        if (_isPaused) {
            auto newScene = _scenePause.run(lib);
            if (newScene == Scenes::SAVE) {
                SceneMaxime::saveTanks();
            } else if (newScene != Scenes::GAME)
                return (newScene);
            _isPaused = false;
        }
        if (_pressed && !isLock) {
            _pressed = false;
            isLock = true;
            for (auto it = _objects.begin(); it != _objects.end();) {
                if (it->get()->getTypeField().isDestructible == true)
                {
                    _objects.emplace_back(std::make_shared<PowerUps>(coords(it->get()->getPosition().first, it->get()->getPosition().second + 1.0f, it->get()->getPosition().third), coords(0, 0, 0), std::pair<std::string, std::string>("", core::powerUpModel)));
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
    }
    return (Scenes::QUIT);
}


// void SceneMaxime::initTanks()
// {
//     int counter = 0;
//     std::size_t setOfKeyInputs = 0;
//     Setting::tanksCoords tanksCoords = Setting::_tanksPosNbPlayers.at(_settings._playersSettings.size());

//     for (auto &playerSettings : _settings._playersSettings) {
//         if (playerSettings.type == PLAYER && setOfKeyInputs < 2) {
//             _objects.emplace_back(std::make_shared<Tank>(
//                 playerSettings.name,
//                 coords(tanksCoords[counter].first,0,tanksCoords[counter].second),
//                 coords(10, 10, 10),
//                 8,
//                 std::make_pair(Tank::bodyTexture, Tank::bodyModel),
//                 std::make_pair(Tank::darkGreen, Tank::cannonModel))
//             );
//             setInputsTank(_settings._keysPlayers[setOfKeyInputs], _objects.back());
//             setOfKeyInputs++;
//         } else if (playerSettings.type == IA) {
//             // _objects.emplace_back(std::make_shared<TankIA>("grosTankSaMere", coords(0,0,0), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
//         }
//         counter++;
//     }
// }