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
        {{{860.0f, 600.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 700.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 800.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 900.0f}, {200.0f, 50.0f}}}
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

    void SceneMenu::run(Raylib &lib)
    {
        lib.set3d(false);
        while (!lib.isKeyPressed(KEY_ENTER)) {
            if (lib.isKeyPressed(KEY_DOWN))
                _select = (_select + 1) % (QUIT + 1);
            if (lib.isKeyPressed(KEY_UP))
                _select = !_select ? QUIT : _select - 1;
            lib.drawingLoopBegin();
            ClearBackground(RAYWHITE);
            for (auto &i : _menuPos)
                lib.printRectangle(Raylib::BASIC, i.at(0), i.at(1), {ORANGE, ORANGE});
            lib.printRectangle(Raylib::GRADIENT, _menuPos.at(_select).at(0), _menuPos.at(_select).at(1), {RED, RED});
            lib.drawingLoopEnd();
        }
    }
}

