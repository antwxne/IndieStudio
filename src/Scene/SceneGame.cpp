/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneGame
*/

#include <memory>
#include "SceneGame.hpp"
#include "Tank.hpp"
#include "Ground.hpp"
#include "LifeGame.hpp"
#include "TexteUi.hpp"


const std::vector<std::string> _assetsPath{
    "asset/background_asset/ground.png",
    "asset/OBJFormat/ground.obj",
    "asset/bonus/arrow.obj"
};

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

SceneGame::SceneGame(Setting &settings) : AScene(settings)
{
    _objects.emplace_back(std::make_shared<Ground>(
        coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(_assetsPath.at(0), _assetsPath.at(1))));
    initTanks();
}

SceneGame::~SceneGame()
{
}

void SceneGame::initTanks()
{
    int tankCounter = 0;
    std::size_t setOfKeyInputs = 0;
    Setting::tanksCoords tanksCoords = Setting::_tanksPosNbPlayers.at(_settings._playersSettings.size());

    for (auto &playerSettings : _settings._playersSettings) {
        if (playerSettings.type == NONE)
            continue;
        if (playerSettings.type == PLAYER && setOfKeyInputs < 2) {
            _objects.emplace_back(std::make_shared<Tank>(
                playerSettings.name,
                coords(tanksCoords[tankCounter].first,0,tanksCoords[tankCounter].second),
                coords(10, 10, 10),
                8,
                std::make_pair(Tank::bodyTexture, Tank::bodyModel),
                std::make_pair(Tank::darkGreen, Tank::cannonModel))
            );
            setInputsTank(_settings._keysPlayers[setOfKeyInputs], _objects.back());
            setOfKeyInputs++;
        } else if (playerSettings.type == IA) {
            // _objects.emplace_back(std::make_shared<TankIA>("grosTankSaMere", coords(0,0,0), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
        }
        initTankUi(tankCounter, std::dynamic_pointer_cast<Tank>(_objects.back()), playerSettings);
        tankCounter++;
    }
}

void SceneGame::initTankUi(int tankCounter, std::shared_ptr<Tank> tank, PlayerSettings &settings)
{
    for (int y = 0; y != tank->getLife(); y++)
        _objects.emplace_back(std::make_shared<LifeGame>(
            tank->getName(), coords(_uiLifePosPlayer[tankCounter].first + (30 * y), _uiLifePosPlayer[i].second)));
    _objects.emplace_back(std::make_shared<TexteUI>(
        coords(_playerPos[tankCounter].first, _playerPos[tankCounter].second),
        std::make_pair(50, 50), dynamic_cast<Tank &>(*tmp).getName(), 20,
        1, std::make_pair(RGB(150), RGB())));
    _objects.emplace_back(std::make_shared<TexteUI>(
        coords(_scorePos[i].first, _scorePos[i].second),
        std::make_pair(50, 50),
        std::to_string(dynamic_cast<Tank &>(*tmp).getScore()), 20, 1,
        std::make_pair(RGB(150), RGB())));
}