/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_

#include "AScene.hpp"
#include "Map.hpp"
#include "FrameUI.hpp"
#include "ScenePause.hpp"

class SceneGame : public AScene {
    public:
        using tanksCoords = std::vector<std::pair<float, float>>;

        SceneGame(Setting &settings);
        ~SceneGame();

        Scenes run(Raylib &lib) final;
    protected:
        void initTanks(const tanksCoords &coords);
        void initTankUi(int tankCounter, std::shared_ptr<Tank> tank, PlayerSettings &settings);
        void initColors();
        void initMap(const tanksCoords &tanksCoords);

        void manageHeart(const std::string &name, const int life);
        
        void saveAll() noexcept;

        void updateObjects(Raylib &lib) noexcept;

        void createRect() noexcept;

        void initSaveTanks();

        void applyBonuses() noexcept;

        static const std::vector<std::pair<float, float>> _playerPos;
        static const std::vector<std::pair<float, float>> _scorePos;
        static const std::vector<std::pair<float, float>> _uiLifePosPlayer;

        std::unique_ptr<Map> _map;

        bool _isPaused;
        pause::ScenePause _scenePause;


    const tanksCoords _zeroTankPos = {};
    const tanksCoords _oneTankPos = {
        {std::make_pair(-8.0f, -5.0f)}
    };
    const tanksCoords _twoTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(8.0f, -5.0f)}
    };
    const tanksCoords _threeTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(8.0f, -5.0f)}, {std::make_pair(-8.0f, 5.0f)}
    };
    const tanksCoords _fourTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(8.0f, -5.0f)}, {std::make_pair(-8.0f, 5.0f)}, {std::make_pair(8.0f, 5.0f)}
    };
    const std::array<tanksCoords, 5> _tanksPosNbPlayers = {
        _zeroTankPos,
        _oneTankPos,
        _twoTanksPos,
        _threeTanksPos,
        _fourTanksPos
    };
};

#endif /* !SCENEGAME_HPP_ */
