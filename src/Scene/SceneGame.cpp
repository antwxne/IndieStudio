/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneGame
*/

#include <memory>
#include <string>
#include "Core.hpp"
#include "SceneGame.hpp"
#include "Tank.hpp"
#include "Ground.hpp"
#include "LifeGame.hpp"
#include "TexteUi.hpp"
#include "ColorPlayer.hpp"
#include "Particles.hpp"
#include "PowerUps.hpp"
#include "Setting.hpp"

const std::vector<std::pair<float, float>> SceneGame::_playerPos = {
    {std::make_pair(170.0f, 1035.0f)},
    {std::make_pair(670.0f, 1035.0f)},
    {std::make_pair(1170.0f, 1035.0f)},
    {std::make_pair(1670.0f, 1035.0f)},
};

const std::vector<std::pair<float, float>> SceneGame::_scorePos =  {
    {std::make_pair(280.0f, 990.0f)},
    {std::make_pair(780.0f, 990.0f)},
    {std::make_pair(1280.0f, 990.0f)},
    {std::make_pair(1780.0f, 990.0f)},
};

const std::vector<std::pair<float, float>> SceneGame::_uiLifePosPlayer = {
    std::make_pair(265, 1050),
    std::make_pair(765, 1050),
    std::make_pair(1265, 1050),
    std::make_pair(1765, 1050)
};

SceneGame::SceneGame(Setting &settings) : AScene(settings), _isPaused(false), _scenePause(settings)
{
    tanksCoords tanksCoords = _tanksPosNbPlayers.at(_settings._playersSettings.size());

    _objects.emplace_back(std::make_shared<Ground>(
        coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(core::groundTexture, core::groundModel)));
    initTanks(tanksCoords);
    initColors();
    initMap(tanksCoords);
    setInputFunction(Raylib::ESCAPE, [&]() {
        _isPaused = !_isPaused;
    });
    applyBonuses();
}

SceneGame::~SceneGame()
{
}

void SceneGame::initTanks(const tanksCoords &tanksCoords)
{
    int tankCounter = 0;
    std::size_t setOfKeyInputs = 0;

    for (auto &playerSettings : _settings._playersSettings) {
        if (playerSettings.type == NONE)
            continue;
        if (playerSettings.type == PLAYER && setOfKeyInputs < 2) {
            _objects.emplace_back(std::make_shared<Tank>(
                playerSettings.name,
                coords(tanksCoords[tankCounter].first,0, tanksCoords[tankCounter].second),
                coords(10, 10, 10),
                8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                std::make_pair(Tank::darkGreen, Tank::cannonModel))
            );
            setInputsTank(_settings._keysPlayers[setOfKeyInputs], _objects.back());
            setOfKeyInputs++;
            initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), playerSettings);
        } else if (playerSettings.type == IA) {
            // _objects.emplace_back(std::make_shared<TankIA>("grosTankSaMere", coords(0,0,0), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        }
        // initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), playerSettings);
        tankCounter++;
    }
}

void SceneGame::initTankUi(int tankCounter, std::shared_ptr<Tank> tank, PlayerSettings &settings)
{
    for (int y = 0; y != tank->getLife(); y++) {
        _objects.emplace_back(std::make_shared<LifeGame>(
            tank->getName(), coords(_uiLifePosPlayer[tankCounter].first + (30 * y), _uiLifePosPlayer[tankCounter].second)));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_playerPos[tankCounter].first, _playerPos[tankCounter].second),
            std::make_pair(50, 50), settings.name,
            20,
            1,
            std::make_pair(RGB(150), RGB())));
    }
    _objects.emplace_back(std::make_shared<TexteUI>(
        coords(_scorePos[tankCounter].first, _scorePos[tankCounter].second),
        std::make_pair(50, 50),
        std::to_string(tank->getScore()),
        20,
        1,
        std::make_pair(RGB(150), RGB()))
    );
}

void SceneGame::initColors()
{
    auto const &colorPlayer = std::make_unique<ColorPlayer>();
    for (auto &color : colorPlayer->getPosColorSquare())
        _objects.emplace_back(std::make_shared<UiObject>(color));
}

void SceneGame::initMap(const tanksCoords &tanksCoords)
{
    _map = std::make_unique<Map>(tanksCoords);
    _map->initTheObstacle();
    if (_settings.load == false) {
        _map->createDestructibleMap(std::make_pair(-6, -7), std::make_pair(0, 0));
        _map->createDestructibleMap(std::make_pair(-6, 1), std::make_pair(-1, -7));
        _map->createDestructibleMap(std::make_pair(0, 0), std::make_pair(6, 7));
        _map->createDestructibleMap(std::make_pair(0, -7), std::make_pair(6, 0));
    } else
        _map->readDestructibleList();
    _map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));
    std::cout << _map->_objectNoDestructibleList.size()  << std::endl;
    for (auto const &block : _map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));
    for (auto const &block : _map->_objectDestructibleList)
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
    _settings.load = false;
}

void SceneGame::manageHeart(const std::string &name, const int life)
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

void SceneGame::saveTanks() noexcept
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


Scenes SceneGame::run(Raylib &lib)
{
    bool isLock = false;

    while (lib.gameLoop())
    {
        lib.displayMusic(core::_gameMusic, _settings._musicVol);
        triggerInputActions(lib);
        if (_isPaused) {
            auto newScene = _scenePause.run(lib);
            if (newScene == Scenes::SAVE) {
                saveTanks();
                _map->writeDestructibleList();
            } else if (newScene != Scenes::GAME)
                return (newScene);
            _isPaused = false;
        }
        updateObjects(lib);
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}

void SceneGame::updateObjects(Raylib &lib) noexcept
{
    for (auto object = _objects.begin(); object != _objects.end();) {
        bool isSupr = false;

        if ((*object)->getTypeField().isTank) {
            auto tank = std::dynamic_pointer_cast<Tank>(*object);
            manageHeart(tank->getName(), tank->getLife());
            tank->moveBullets();
            if (tank->getLife() <= 0) {
                std::cout << " [Scene Game] Je supprime le TANK\n";
                _objects.emplace_back(std::make_shared<Particles>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(20, 12, 9), RGB()), 100, coords(0, 0.2f, 0), 5000.0f));
                object = _objects.erase(object);
                isSupr = true;
            }
        }
        if ((*object)->getTypeField().isParticule == true) {
            if (std::dynamic_pointer_cast<Particles>(*object)->update() == true) {
                std::cout << " [Scene Game] Je supprime la particule\n";
                object = _objects.erase(object);
                isSupr = true;
            }
        }
        else if ((*object)->getTypeField().isPowerUps == true)
            std::dynamic_pointer_cast<PowerUps>(*object)->rotate(0.5f);
        if (object->get()->getTypeField().isDestructibleWall && std::dynamic_pointer_cast<DestructibleWall>(*object)->getLife() <= 0) {
            // std::cout << " [Scene Game] Je init la particule\n";
            // std::cout << " [Scene Game] pos x: " << object->get()->getPosition().first << "\n";
            // std::cout << " [Scene Game] pos y: " << object->get()->getPosition().second << "\n";
            // std::cout << " [Scene Game] pos z: " << object->get()->getPosition().third << "\n\n";
            _objects.emplace_back(std::make_shared<PowerUps>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), coords(1, 1, 1), std::pair<std::string, std::string>("", "")));
            //_objects.emplace_back(std::make_shared<Particles>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(218, 165, 32), RGB()), 100, coords(0, 0.2f, 0), 5000.0f));
            object = _objects.erase(object);
            isSupr = true;
        }
        if (object->get()->getTypeField().isPowerUps && std::dynamic_pointer_cast<PowerUps>(*object)->getLife() <= 0) {
            object = _objects.erase(object);
            isSupr = true;
        }
        if (!isSupr)
            ++object;
    }
}

void SceneGame::applyBonuses() noexcept
{
    // selon les bonus choisis cette fonction sera utile ou non
    // peut etre mieux de le faire directement a l'instanciation pour les tanks par exemple
    if (_settings.bonuses.firstBonus) {
    }
    if (_settings.bonuses.secondBonus) {
    }
    if (_settings.bonuses.thirdBonus) {
    }
    if (_settings.bonuses.fourthBonus) {
    }
}