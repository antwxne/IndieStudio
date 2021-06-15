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

static const std::vector<std::pair<float, float>>_uiLifePos {
    {std::make_pair(100, 925)},
    {std::make_pair(500, 925)},
    {std::make_pair(900, 925)},
    {std::make_pair(1300, 925)},
};

static const std::vector<std::pair<float, float>> _uiGameSize{
    {std::make_pair(100, 100)},
    {std::make_pair(100, 100)},
    {std::make_pair(100, 100)},
    {std::make_pair(100, 100)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},
    {std::make_pair(80, 50)},

};

static const std::vector<std::pair<float, float>> _uiGamePos {
    {std::make_pair(150, 925)},
    {std::make_pair(650, 925)},
    {std::make_pair(1150, 925)},
    {std::make_pair(1550, 925)},
    {std::make_pair(260, 975)},
    {std::make_pair(760, 975)},
    {std::make_pair(1260, 975)},
    {std::make_pair(1660, 975)},
};