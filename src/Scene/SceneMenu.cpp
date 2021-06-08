/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#include "Raylib/Raylib.hpp"
#include "Scene/SceneMenu.hpp"

namespace menu {

    const std::vector<std::array<std::pair<float, float>, 2>> SceneMenu::_menuPos {
        {{{300.0f, 300.0f}, {100.0f, 100.0f}}},
        {{{300.0f, 400.0f}, {100.0f, 100.0f}}},
        {{{300.0f, 500.0f}, {100.0f, 100.0f}}},
        {{{300.0f, 600.0f}, {100.0f, 100.0f}}}
    };

    const std::vector<std::string> SceneMenu::_assetsPath {
        {"Assets/olivier_bg.png"}
    };

    SceneMenu::SceneMenu() : _select(menu_e::START)
    {
    }

    SceneMenu::~SceneMenu()
    {
    }

    void SceneMenu::StartLoop(Raylib &lib)
    {
        lib.set3d(false);
        while (!lib.isKeyPressed(KEY_ENTER)) {
            lib.drawingLoopBegin();
            // for (auto &i : _menuPos)
            //     lib.printRectangle(Raylib::BASIC, i.at(0), i.at(1), {ORANGE, ORANGE});
            lib.drawingLoopEnd();
        }
    }
}

