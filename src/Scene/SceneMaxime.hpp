/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#pragma once
#include "AScene.hpp"
#include <vector>

class SceneMaxime : public AScene {
    public:
        SceneMaxime(Setting &settings);
        ~SceneMaxime();
        Scenes run(Raylib &lib, Scenes const &prevScene) final;
        void manageHeart(const std::string &name, const int life);

    private:
        std::vector<int> _iterator;
        static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
        static const std::vector<std::string> _assetsPath;
        bool _enter;
};

static const std::vector<std::pair<float, float>> _playerPos {
    {std::make_pair(170.0f, 1035.0f)},
    {std::make_pair(670.0f, 1035.0f)},
    {std::make_pair(1170.0f, 1035.0f)},
    {std::make_pair(1670.0f, 1035.0f)},
};

static const std::vector<std::pair<float, float>> _scorePos {
    {std::make_pair(270.0f, 975.0f)},
    {std::make_pair(770.0f, 975.0f)},
    {std::make_pair(1270.0f, 975.0f)},
    {std::make_pair(1770.0f, 975.0f)},
};

static const std::vector<std::pair<float, float>> _uiLifePosPlayer{
    std::make_pair(265, 1050),
    std::make_pair(765, 1050),
    std::make_pair(1265, 1050),
    std::make_pair(1765, 1050)
};