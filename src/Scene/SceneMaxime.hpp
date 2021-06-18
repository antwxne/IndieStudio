/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#pragma once
#include "AScene.hpp"
#include "ScenePause.hpp"
#include "Object/Collisionable/Destructible/Movable/Tank.hpp"
#include <vector>

class SceneMaxime : public AScene {
    public:
        SceneMaxime(Setting &settings);
        ~SceneMaxime();
        Scenes run(Raylib &lib) final;
        void manageHeart(const std::string &name, const int life);
        void checkHeart() noexcept;
        void initTanks();
    private:
        std::vector<int> _listPosHeart;
        static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
        static const std::vector<std::string> _assetsPath;
        pause::ScenePause _scenePause;
        std::shared_ptr<Tank> _tanks;
        bool _pressed;
        bool _enter;
        bool _isPaused;
        bool _state;
};

static const std::vector<std::pair<float, float>> _playerPos {
    {std::make_pair(170.0f, 1035.0f)},
    {std::make_pair(670.0f, 1035.0f)},
    {std::make_pair(1170.0f, 1035.0f)},
    {std::make_pair(1670.0f, 1035.0f)},
};

static const std::vector<std::pair<float, float>> _scorePos {
    {std::make_pair(280.0f, 990.0f)},
    {std::make_pair(780.0f, 990.0f)},
    {std::make_pair(1280.0f, 990.0f)},
    {std::make_pair(1780.0f, 990.0f)},
};

static const std::vector<std::pair<float, float>> _uiLifePosPlayer{
    std::make_pair(265, 1050),
    std::make_pair(765, 1050),
    std::make_pair(1265, 1050),
    std::make_pair(1765, 1050)
};

static const std::vector<std::pair<float, float>> _posTank {
    std::make_pair(-8, -5),
    std::make_pair(-8, 5),
    std::make_pair(8, 5),
    std::make_pair(8,-5)
};