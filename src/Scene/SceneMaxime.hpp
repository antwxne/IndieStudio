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