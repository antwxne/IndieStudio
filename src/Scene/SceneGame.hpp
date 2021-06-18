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
#include "ScenePause.hpp"

class SceneGame : public AScene {
    public:
        SceneGame(Setting &settings);
        ~SceneGame();

        Scenes run(Raylib &lib) final;
    protected:
        void initTanks(const Setting::tanksCoords &coords);
        void initTankUi(int tankCounter, std::shared_ptr<Tank> tank, PlayerSettings &settings);
        void initColors();
        void initMap(const Setting::tanksCoords &tanksCoords);

        void manageHeart(const std::string &name, const int life);

        void managePause(Raylib &lib);
        
        void saveTanks() noexcept;

        static const std::vector<std::pair<float, float>> _playerPos;
        static const std::vector<std::pair<float, float>> _scorePos;
        static const std::vector<std::pair<float, float>> _uiLifePosPlayer;

        std::unique_ptr<Map> _map;

        bool _isPaused;
        pause::ScenePause _scenePause;

};

#endif /* !SCENEGAME_HPP_ */
