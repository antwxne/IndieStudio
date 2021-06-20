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
#include "Score.hpp"
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
    tanksCoords tanksCoords = _tanksPosNbPlayers[_settings._playersSettings.size()];
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
        } else if (playerSettings.type == IA) {
            _objects.emplace_back(std::make_shared<TankAI>(playerSettings.name,
                coords(tanksCoords[tankCounter].first, 0,
                    tanksCoords[tankCounter].second), coords(10, 10, 10), 8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        }
        auto newTank = std::dynamic_pointer_cast<Tank>(_objects.back());
        applyBonuses(newTank);
        initTankUi(tankCounter, newTank, playerSettings);
        tankCounter++;
    }
}

void SceneGame::initSaveTanks()
{
    auto tanks = Tank::readTank();
    auto iaTanks = TankAI::readAiTankList();
    std::size_t setOfKeyInputs = 0;
    int tankCounter = 0;

    _settings._playersSettings.clear();
    for (auto &tank : tanks) {
        _objects.emplace_back(std::make_shared<Tank>(tank.getName(),
            coords(tank.getPosition().first, 0, tank.getPosition().third),
            coords(10, 10, 10), 8,
            std::make_pair(Tank::bodyTexture, Tank::bodyModel),
            std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        auto tk = std::dynamic_pointer_cast<Tank>(_objects.back());
        tk->setSpeed(tank.getSpeed());
        tk->setLife(tank.getLife());
        tk->setScore(tank.getScore());
        _settings._playersSettings.emplace_back(PLAYER, tk->getName(),
            tk->getScore());
        setInputsTank(_settings._keysPlayers[setOfKeyInputs], _objects.back());
        setOfKeyInputs++;
        initTankUi(tankCounter,
            std::dynamic_pointer_cast<Tank>(_objects.back()),
            _settings._playersSettings[tankCounter]);
        tankCounter++;
    }
    for (auto &iaTank : iaTanks) {
        _objects.emplace_back(std::make_shared<TankAI>(iaTank.getName(), coords(iaTank.getPosition().first,0,iaTank.getPosition().third), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        auto aitk = std::dynamic_pointer_cast<TankAI>(_objects.back());
        aitk->setSpeed(iaTank.getSpeed());
        aitk->setLife(iaTank.getLife());
        aitk->setScore(iaTank.getScore());
        _settings._playersSettings.emplace_back(IA, aitk->getName(),
            aitk->getScore());
        initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), _settings._playersSettings[tankCounter]);
        tankCounter++;
    }
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
      /*  _objects.emplace_back(std::make_shared<Score>(tank->getName(),
            coords(_scorePos[tankCounter].first, _scorePos[tankCounter].second),
            std::make_pair(50, 50), std::to_string(tank->getScore()), 20, 1,
            std::make_pair(RGB(150), RGB())));*/
    }
    _objects.emplace_back(std::make_shared<Score>(tank->getName(),
        coords(_scorePos[tankCounter].first, _scorePos[tankCounter].second),
        std::make_pair(50, 50), tank->getScore(), 20, 1,
        std::make_pair(RGB(150), RGB())));
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
    std::vector<TankAI> iaTanks;

    for (auto &it: _objects) {
        if (it->getTypeField().isTank && it->getTypeField().isIa == false) {
            auto tank = std::dynamic_pointer_cast<Tank>(it);
            tk.push_back(dynamic_cast<Tank &>(*tank));
        }
        if (it->getTypeField().isDestructibleWall) {
            auto wall = std::dynamic_pointer_cast<DestructibleWall>(it);
            walls.push_back(dynamic_cast<DestructibleWall &>(*wall));
        }
        if (it->getTypeField().isTank && it->getTypeField().isIa == true) {
            auto iaTank = std::dynamic_pointer_cast<TankAI>(it);
            iaTanks.push_back(dynamic_cast<TankAI &>(*iaTank));
        }
    }
    Tank::writeTankList(tk);
    TankAI::writeIATankList(iaTanks);
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

    lib.displaySound(core::_startGame, _settings._soundVol);
    for (auto &it : _objects) {
        if (it->getTypeField().isTank) {
            tanks.emplace_back(std::dynamic_pointer_cast<Tank>(it));
        }
        if (it->getTypeField().isIa) {
            AIs.emplace_back(std::dynamic_pointer_cast<TankAI>(it));
        }
    }
    while (!_endGame) {
        if (!lib.gameLoop())
            return (Scenes::QUIT);
        auto nAI = 0;
        end = std::chrono::steady_clock::now();
        endFire = std::chrono::steady_clock::now();
        lib.displayMusic(core::MAP_MUSIC.at(core::soundPath::GAME), _settings._musicVol);
        triggerInputActions(lib);
        if (_isPaused) {
            lib.displaySound(core::_pauseClick, _settings._soundVol);
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

void SceneGame::timeIncrementScore(std::shared_ptr<Tank> &tank)
{
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start) >= std::chrono::milliseconds(1000)) {
        tank->setScore(tank->getScore() + 1);
        std::find_if(_settings._playersSettings.begin(), _settings._playersSettings.end(), [tank](auto &it){return it.name == tank->getName();})->score += 1;
    }
}

void SceneGame::updateScore(std::string const &name, std::size_t &scoreTank) noexcept
{
    for (auto &k : _objects) {
        if (k->getTypeField().isScore) {
            auto score = std::dynamic_pointer_cast<Score>(k);
            score->updateDisplay();
        }
    }
}

void SceneGame::updateObjects(Raylib &lib) noexcept
{
    int VictoryCond = 0;
    bool isSupr = false;

    for (auto object = _objects.begin(); object != _objects.end();) {
        isSupr = false;
        if ((*object)->getTypeField().isTank) {
            auto tank = std::dynamic_pointer_cast<Tank>(*object);
            timeIncrementScore(tank);
            updateScore(tank->getName(), tank->getScore());
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
            else if (tank->getPosition() != tank->getPreviousPos() && _settings._playersSettings.size() <= 2 && !_settings.bonuses.LifeUpBonus) {
                auto newAngle = (static_cast<int>(tank->getRotationAngle()) + 180) % 360;
                _objects.emplace_back(std::make_shared<Particles>(coords(tank->getPosition().first + (std::sin(M_PI *  newAngle / 180)), 0, tank->getPosition().third + std::cos(M_PI * newAngle / 180)), std::make_pair(1, 1), 1.0f, 0.05f, std::make_pair(RGB(128,128,128), RGB()), 10, coords(0, 0.05f, 0), 100.0f));
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