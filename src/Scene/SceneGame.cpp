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
    {std::make_pair(300.0f, 990.0f)}, {std::make_pair(800.0f, 990.0f)},
    {std::make_pair(1300.0f, 990.0f)}, {std::make_pair(1800.0f, 990.0f)},};

const std::vector<std::pair<float, float>> SceneGame::_uiLifePosPlayer = {
    std::make_pair(265, 1050), std::make_pair(765, 1050),
    std::make_pair(1265, 1050), std::make_pair(1765, 1050)};

SceneGame::SceneGame(Setting &settings) : AScene(settings), _isPaused(false),
    _scenePause(settings), _endGame(false)
{
    std::cout << "PROBLEME EST ICI SUREMENT OU PAS\n";
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
    createRect();
    initMap(tanksCoords);
    setInputFunction(Raylib::ESCAPE, [&]() {
        _isPaused = !_isPaused;
    });
}

SceneGame::~SceneGame()
{
}

void SceneGame::createRect() noexcept
{
    auto const &carre = std::make_unique<FrameUI>();
    for (auto const &carr : carre->getBorder())
        _objects.emplace_back(std::make_shared<BorderPlayer>(carr));
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
            applyBonuses(std::dynamic_pointer_cast<Tank>(_objects.back()));
            initTankUi(tankCounter,
                std::dynamic_pointer_cast<Tank>(_objects.back()),
                playerSettings);
        } else if (playerSettings.type == IA) {
            _objects.emplace_back(std::make_shared<TankAI>(playerSettings.name,
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

    std::cout << "GROS LOLOLO\n";
    for (auto &tank : tanks) {
        std::cout << "GROS LOLOLO 01\n";
        _objects.emplace_back(std::make_shared<Tank>(
                tank.getName(),
                coords(tank.getPosition().first,0, tank.getPosition().third),
                coords(10, 10, 10),
                8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        std::cout << "GROS LOLOLO 02\n";
        auto tk = std::dynamic_pointer_cast<Tank>(_objects.back());
        std::cout << "GROS LOLOLO 03\n";
        tk->setSpeed(tank.getSpeed());
        std::cout << "GROS LOLOLO 04\n";
        tk->setLife(tank.getLife());
        std::cout << "GROS LOLOLO 05\n";
        setInputsTank(_settings._keysPlayers[setOfKeyInputs], _objects.back());
        std::cout << "GROS LOLOLO 06\n";
        setOfKeyInputs++;
        std::cout << "GROS LOLOLO 07\n";
        initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), _settings._playersSettings[tankCounter]);
        std::cout << "GROS LOLOLO 08\n";
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
            tank->getName(), 20, 1, std::make_pair(RGB(150), RGB())));
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
    while (!_endGame) {
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
            if (std::chrono::duration_cast<std::chrono::seconds>(endFire - startFire) >= std::chrono::seconds(5)) {
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
    return (Scenes::ENDGAME);
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
                _objects.emplace_back(std::make_shared<Particles>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.2f, std::make_pair(RGB(20, 12, 9), RGB()), 100, coords(0, 0.02f, 0), 2000.0f));
                _objects.emplace_back(std::make_shared<Particles>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.1f, std::make_pair(RGB(240, 70, 70), RGB()), 150, coords(0, 0.02f, 0), 2000.0f));
                object = _objects.erase(object);
                isSupr = true;
            }
            else if (tank->getPosition() != tank->getPreviousPos() && _settings._playersSettings.size() <= 2) {
                auto newAngle = (static_cast<int>(tank->getRotationAngle()) + 180) % 360;
                _objects.emplace_back(std::make_shared<Particles>(coords(tank->getPosition().first + (std::sin(M_PI *  newAngle / 180)), 0, tank->getPosition().third + std::cos(M_PI * newAngle / 180)), std::make_pair(1, 1), 1.0f, 0.1f, std::make_pair(RGB(128,128,128), RGB()), 10, coords(0, 0.02f, 0), 100.0f));
            }
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
            _objects.emplace_back(std::make_shared<Particles>(coords(object->get()->getPosition().first, object->get()->getPosition().second + 1.0f, object->get()->getPosition().third), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(218, 165, 32), RGB()), 100, coords(0, 0.2f, 0), 3000.0f));
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
    if (VictoryCond == 1)
        _endGame = true;
}

void SceneGame::applyBonuses(std::shared_ptr<Tank> tank) noexcept
{
    if (_settings.bonuses.SpeedUpBonus)
        tank->increaseSpeed(3);
    if (_settings.bonuses.LifeUpBonus)
        tank->setLife(5);
    if (_settings.bonuses.DamageUpBonus)
        tank->increaseDamage(2);
}