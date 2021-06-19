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

#include "Core.hpp"
#include "SceneGame.hpp"
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

    _objects.emplace_back(std::make_shared<Ground>(
        coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(core::groundTexture, core::groundModel)));
    if (_settings.load == false) {
        initTanks(tanksCoords);
    }
    else {
        initSaveTanks();
    }
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
        if (playerSettings.type == PLAYER && setOfKeyInputs < _settings._keysPlayers.size()) {
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

void SceneGame::initSaveTanks()
{
    auto tanks = Tank::readTank();
    std::size_t setOfKeyInputs = 0;
    int tankCounter = 0;

    for (auto &tank : tanks) {
            _objects.emplace_back(std::make_shared<Tank>(
                tank.getName(),
                coords(tank.getPosition().first,0, tank.getPosition().third),
                coords(10, 10, 10),
                8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                std::make_pair(Tank::darkGreen, Tank::cannonModel)));
            auto tk = std::dynamic_pointer_cast<Tank>(_objects.back());
            tk->setSpeed(tank.getSpeed());
            tk->setLife(tank.getLife());
            setInputsTank(_settings._keysPlayers[setOfKeyInputs], _objects.back());
            setOfKeyInputs++;
            initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), _settings._playersSettings[tankCounter]);
            tankCounter++;
    }
        /*} else if (playerSettings.type == IA) {
            // _objects.emplace_back(std::make_shared<TankIA>("grosTankSaMere", coords(0,0,0), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        }*/
        // initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), playerSettings);
}

void SceneGame::initTankUi(int tankCounter, std::shared_ptr<Tank> tank, PlayerSettings &settings)
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
                if (idx >= life) {
                    heart->setTransparancy(true);
                    ++idx;
                    continue;
                }
                if (idx <= life) {
                    heart->setTransparancy(false);
                    ++idx;
                    continue;
                }
            }
        }
    }
}

void SceneGame::saveAll() noexcept
{
    std::vector<Tank> tk;
    std::vector<DestructibleWall> walls;
    for (auto &it: _objects) {
        if (it->getTypeField().isTank && it->getTypeField().isIa == false) {
            auto tank = std::dynamic_pointer_cast<Tank>(it);
            tk.push_back(dynamic_cast<Tank &>(*tank));
        }
        if (it->getTypeField().isDestructibleWall) {
            auto wall = std::dynamic_pointer_cast<DestructibleWall>(it);
            walls.push_back(dynamic_cast<DestructibleWall &>(*wall));
        }
    }
    Tank::writeTankList(tk);
    _map->writeDestructibleList(walls);
}

Scenes SceneGame::run(Raylib &lib)
{
    bool isLock = false;
    bool started = true;
    std::random_device rd;
    std::default_random_engine rng(rd());
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    static auto startFire = std::chrono::steady_clock::now();
    auto endFire = std::chrono::steady_clock::now();
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
        endFire = std::chrono::steady_clock::now();
        lib.displayMusic(core::_gameMusic, _settings._musicVol);
        triggerInputActions(lib);
        if (_isPaused) {
            auto newScene = _scenePause.run(lib);
            if (newScene == Scenes::SAVE) {
                saveAll();
            } else if (newScene != Scenes::GAME)
                return (newScene);
            _isPaused = false;
        }
        for (auto &AI : AIs) {
            AI->target(tanks[nAI]->getPosition());
            ++nAI;
            AI->autoMove();
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= std::chrono::seconds(3)) {
                AI->fire();
                startFire = std::chrono::steady_clock::now();
            }
        }
        if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= std::chrono::seconds(3) || started) {
            start = std::chrono::steady_clock::now();
            std::shuffle(tanks.begin(), tanks.end(), rng);
        }
        started = false;
        updateObjects(lib);
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}

void SceneGame::updateObjects(Raylib &lib) noexcept
{
    int VictoryCond = 0;
    bool isSupr = false;

    for (auto object = _objects.begin(); object != _objects.end();) {
        isSupr = false;
        if ((*object)->getTypeField().isTank) {
            auto tank = std::dynamic_pointer_cast<Tank>(*object);
            manageHeart(tank->getName(), tank->getLife());
            tank->moveBullets();
            if (tank->getLife() <= 0) {
                for (auto &it :_settings._playersSettings)
                    if (it.name.compare(tank->getName()) == 0)
                        it.isLooser = true;
                _objects.emplace_back(std::make_shared<Particles>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(20, 12, 9), RGB()), 100, coords(0, 0.002f, 0), 2000.0f));
                object = _objects.erase(object);
                isSupr = true;
            }
            //else if (tank->getPosition() != tank->getPreviousPos())
                //_objects.emplace_back(std::make_shared<Particles>(coords((tank->getCannon().getPosition().first - tank->getCannon().getPrevPos().first) * -1, 1.0f, (tank->getCannon().getPosition().third - tank->getCannon().getPrevPos().third) * -1), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(128,128,128), RGB()), 50, coords(0.002f, 0, 0), 100.0f));
        }
        if ((*object)->getTypeField().isParticule == true) {
            if (std::dynamic_pointer_cast<Particles>(*object)->update() == true) {
                object = _objects.erase(object);
                isSupr = true;
            }
        }
        else if ((*object)->getTypeField().isPowerUps == true)
            std::dynamic_pointer_cast<PowerUps>(*object)->rotate(0.5f);
        if (object->get()->getTypeField().isDestructibleWall && std::dynamic_pointer_cast<DestructibleWall>(*object)->getLife() <= 0) {
            _objects.emplace_back(std::make_shared<PowerUps>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), coords(1, 1, 1), std::pair<std::string, std::string>("", "")));
            _objects.emplace_back(std::make_shared<Particles>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(218, 165, 32), RGB()), 100, coords(0, 0.2f, 0), 10000.0f));
            object = _objects.erase(object);
            isSupr = true;
        }
        if (object->get()->getTypeField().isPowerUps && std::dynamic_pointer_cast<PowerUps>(*object)->getLife() <= 0) {
            object = _objects.erase(object);
            isSupr = true;
        }

        if (object->get()->getTypeField().isTank)
            ++VictoryCond;
        if (!isSupr)
            ++object;
    }
    // if (VictoryCond == 1)
    //     std::cout << "You Win\n";
}

void SceneGame::applyBonuses() noexcept
{
    // selon les bonus choisis cette fonction sera utile ou non
    // peut etre mieux de le faire directement a l'instanciation pour les tanks par exemple
    if (_settings.bonuses.SpeedUpBonus) {
    }
    if (_settings.bonuses.LifeUpBonus) {
    }
    if (_settings.bonuses.DamageUpBonus) {
    }
}