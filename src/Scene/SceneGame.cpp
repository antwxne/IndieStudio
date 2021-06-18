/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneGame
*/

#include <memory>
#include <string>
#include <random>
#include <algorithm>

#include "Object/Collisionable/Destructible/Movable/TankAi.hpp"
#include "Core.hpp"
#include "SceneGame.hpp"
#include "Object/Collisionable/Destructible/Movable/Tank.hpp"
#include "Ground.hpp"
#include "LifeGame.hpp"
#include "TexteUi.hpp"
#include "ColorPlayer.hpp"
#include "Particles.hpp"
#include "PowerUps.hpp"
#include "Setting.hpp"

const std::vector<std::string> _assetsPaths{"asset/background_asset/ground.png",
    "asset/OBJFormat/ground.obj", "asset/bonus/arrow.obj"};

const std::vector<std::pair<float, float>> SceneGame::_playerPos = {
    {std::make_pair(170.0f, 1035.0f)}, {std::make_pair(670.0f, 1035.0f)},
    {std::make_pair(1170.0f, 1035.0f)}, {std::make_pair(1670.0f, 1035.0f)},};

const std::vector<std::pair<float, float>> SceneGame::_scorePos = {
    {std::make_pair(280.0f, 990.0f)}, {std::make_pair(780.0f, 990.0f)},
    {std::make_pair(1280.0f, 990.0f)}, {std::make_pair(1780.0f, 990.0f)},};

const std::vector<std::pair<float, float>> SceneGame::_uiLifePosPlayer = {
    std::make_pair(265, 1050), std::make_pair(765, 1050),
    std::make_pair(1265, 1050), std::make_pair(1765, 1050)};

SceneGame::SceneGame(Setting &settings) : AScene(settings), _isPaused(false),
    _scenePause(settings)
{
    tanksCoords tanksCoords = _tanksPosNbPlayers.at(
        _settings._playersSettings.size());

    _objects.emplace_back(
        std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22),
            std::pair<std::string, std::string>(_assetsPaths.at(0),
                _assetsPaths.at(1))));
    initTanks(tanksCoords);
    initColors();
    initMap(tanksCoords);
    setInputFunction(Raylib::ESCAPE, [&]() {
        _isPaused = !_isPaused;
    });
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
            _objects.emplace_back(std::make_shared<Tank>(playerSettings.name,
                coords(tanksCoords[tankCounter].first, 0,
                    tanksCoords[tankCounter].second), coords(10, 10, 10), 8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                std::make_pair(Tank::darkGreen, Tank::cannonModel)));
            setInputsTank(_settings._keysPlayers[setOfKeyInputs],
                _objects.back());
            setOfKeyInputs++;
            initTankUi(tankCounter,
                std::dynamic_pointer_cast<Tank>(_objects.back()),
                playerSettings);
        } else if (playerSettings.type == IA) {
            _objects.emplace_back(std::make_shared<TankAI>("grosTankSaMere",
                coords(tanksCoords[tankCounter].first, 0,
                    tanksCoords[tankCounter].second), coords(10, 10, 10), 8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        }
        // initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), playerSettings);
        tankCounter++;
    }
}

void SceneGame::initTankUi(int tankCounter, std::shared_ptr<Tank> tank,
    PlayerSettings &settings
)
{
    for (int y = 0; y != tank->getLife(); y++) {
        _objects.emplace_back(std::make_shared<LifeGame>(tank->getName(),
            coords(_uiLifePosPlayer[tankCounter].first + (30 * y),
                _uiLifePosPlayer[tankCounter].second)));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_playerPos[tankCounter].first,
                _playerPos[tankCounter].second), std::make_pair(50, 50),
            settings.name, 20, 1, std::make_pair(RGB(150), RGB())));
        _objects.emplace_back(std::make_shared<TexteUI>(
            coords(_scorePos[tankCounter].first, _scorePos[tankCounter].second),
            std::make_pair(50, 50), std::to_string(tank->getScore()), 20, 1,
            std::make_pair(RGB(150), RGB())));
    }
    std::cout << std::endl;
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
    if (_settings.load == false) {
        _map->createDestructibleMap(std::make_pair(-6, -7),
            std::make_pair(0, 0));
        _map->createDestructibleMap(std::make_pair(-6, 1),
            std::make_pair(-1, -7));
        _map->createDestructibleMap(std::make_pair(0, 0), std::make_pair(6, 7));
        _map->createDestructibleMap(std::make_pair(0, -7),
            std::make_pair(6, 0));
    } else
        _map->readDestructibleList();
    _map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));
    std::cout << _map->_objectNoDestructibleList.size() << std::endl;
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

    for (unsigned int i = 0; i != _objects.size(); i++) {
        if (_objects[i]->getTypeField().isLife) {
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
    bool started = true;
    std::random_device rd;
    std::default_random_engine rng(rd());
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::vector<std::shared_ptr<Tank>> tanks;
    std::vector<std::shared_ptr<TankAI>> AIs;

    for (auto &it : _objects) {
        if (it->getTypeField().isTank) {
            tanks.emplace_back(std::dynamic_pointer_cast<Tank>(it));
        }
        if (it->getTypeField().isIa) {
            AIs.emplace_back(std::dynamic_pointer_cast<TankAI>(it));
        }
    }
    while (lib.gameLoop()) {
        auto nAI = 0;
        end = std::chrono::steady_clock::now();
        lib.displayMusic(core::_gameMusic, _settings._musicVol);
        triggerInputActions(lib);
        lib.printObjects(_objects);
        if (_isPaused) {
            auto newScene = _scenePause.run(lib);
            if (newScene == Scenes::SAVE) {
                saveTanks();
                _map->writeDestructibleList();
            } else if (newScene != Scenes::GAME)
                return (newScene);
            _isPaused = false;
        }
        for (auto it = _objects.begin(); it != _objects.end(); ++it) {
            if ((*it)->getTypeField().isTank) {
                auto tank = std::dynamic_pointer_cast<Tank>(*it);
                manageHeart(tank->getName(), tank->getLife());
                tank->moveBullets();
            }
            if ((*it)->getTypeField().isParticule == true) {
                std::dynamic_pointer_cast<Particles>(*it)->update();
            } else if ((*it)->getTypeField().isPowerUps == true) {
                std::dynamic_pointer_cast<PowerUps>(*it)->rotate(0.5f);
            }
        }
        for (auto &AI : AIs) {
            AI->target(tanks[nAI]->getPosition());
            ++nAI;
            AI->autoMove();
            AI->fire();
        }
        if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >=
            std::chrono::seconds(10) || started) {
            start = std::chrono::steady_clock::now();
            std::shuffle(tanks.begin(), tanks.end(), rng);
        }
        started = false;
    }
    return (Scenes::QUIT);
}

void SceneGame::managePause(Raylib &lib)
{
}