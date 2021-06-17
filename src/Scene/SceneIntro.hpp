//
// Created by clement on 17/06/2021.
//

#pragma once
#include "AScene.hpp"

enum Direction {
    NEUTRAL,
    UP,
    DOWN,
};


class SceneIntro : public AScene {
public:
    SceneIntro(Setting &settings);
    ~SceneIntro() noexcept;
    Scenes run(Raylib &lib) final;
private:
    bool _enter;
    static const std::vector<std::string> _assetsPath;
};