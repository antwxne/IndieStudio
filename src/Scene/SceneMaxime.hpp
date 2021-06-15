/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#pragma once

#include "AScene.hpp"

class SceneMaxime : public AScene {
    public:
        SceneMaxime(Setting &settings);
        ~SceneMaxime();
        Scenes run(Raylib &lib, Scenes const &prevScene) final;

    private:
        static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
        static const std::vector<std::string> _assetsPath;
        bool _enter;
};

static const std::vector<std::string> _playerName {
    "player1",
    "player2",
    "player3",
    "player4"
};

static const std::vector<std::pair<float, float>> _playerPos {
    {std::make_pair(170.0f, 1035.0f)},
    {std::make_pair(670.0f, 1035.0f)},
    {std::make_pair(1170.0f, 1035.0f)},
    {std::make_pair(1670.0f, 1035.0f)},
};

static const std::vector<int> _playerScore {
    0,
    0,
    0,
    0
};

static const std::vector<std::pair<float, float>> _scorePos {
    {std::make_pair(270.0f, 975.0f)},
    {std::make_pair(770.0f, 975.0f)},
    {std::make_pair(1270.0f, 975.0f)},
    {std::make_pair(1770.0f, 975.0f)},
};