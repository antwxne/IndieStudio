//
// Created by clement on 17/06/2021.
//

#pragma once
#include "AScene.hpp"

class SceneIntro : public AScene {
    SceneIntro(Setting &settings);
    ~SceneIntro() noexcept;
    Scenes run(Raylib &lib) final;
};