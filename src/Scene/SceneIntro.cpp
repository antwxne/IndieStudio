//
// Created by clement on 17/06/2021.
//

#include "SceneIntro.hpp"

SceneIntro::SceneIntro(Setting &settings) : AScene(settings)
{
}

SceneIntro::~SceneIntro() noexcept
{
}

Scenes SceneIntro::run(Raylib &lib)
{
    while (lib.gameLoop()) {
    }
    if (lib.gameLoop())
        return (Scenes::QUIT);
    return (Scenes::MENU);
}