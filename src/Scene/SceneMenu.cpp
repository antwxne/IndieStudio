/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#include "Core/Core.hpp"
#include <chrono>
#include "Raylib/Raylib.hpp"
#include "Scene/SceneMenu.hpp"

namespace menu {

    const std::vector<std::string> SceneMenu::_menuText {
        "Start game",
        "Load game",
        "Settings",
        "Quit"
    };

    const std::vector<std::array<std::pair<float, float>, 2>> SceneMenu::_menuPos {
        {{{860.0f, 600.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 700.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 800.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 900.0f}, {200.0f, 50.0f}}}
    };

    const std::vector<std::string> SceneMenu::_assetsPath {
        "Assets/olivier_bg.png",
        "Assets/menu_music.mp3",
        "truc_tank/Sample_0000.wav",
        "truc_tank/Sample_0005.wav"
    };

    SceneMenu::SceneMenu() : _select(menu_e::START)
    {
    }

    SceneMenu::~SceneMenu()
    {
    }

    int SceneMenu::run(Raylib &lib)
    {
        bool enter = 0;
        Texture2D bg = LoadTexture(_assetsPath.at(assetsPath_e::BACKGROUND).c_str());
        Music music = LoadMusicStream(_assetsPath.at(assetsPath_e::MUSIC_BG).c_str());
        Sound sound = LoadSound(_assetsPath.at(assetsPath_e::TIC).c_str());
        Sound sound2 = LoadSound(_assetsPath.at(assetsPath_e::ACCEPT).c_str());

        music.looping = true;
        PlayMusicStream(music);
        while (!lib.isKeyReleased(KEY_ENTER) && lib.gameLoop()) {
            UpdateMusicStream(music);
            if (lib.isKeyPressed(KEY_ENTER)) {
                enter = !enter;
                PlaySound(sound2);
            }
            if (lib.isKeyPressed(KEY_DOWN)) {
                _select = (_select + 1) % (QUIT + 1);
                PlaySound(sound);
            }
            if (lib.isKeyPressed(KEY_UP)) {
                _select = !_select ? QUIT : _select - 1;
                PlaySound(sound);
            }
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(bg, 0, 0, WHITE);
            // for (auto &i : _menuPos)
            //     lib.printRectangle(Raylib::BASIC, i.at(0), i.at(1), {ORANGE, ORANGE});
            // lib.printRectangle(Raylib::GRADIENT, _menuPos.at(_select).at(0), _menuPos.at(_select).at(1), {RED, RED});
            // if (enter)
            //     lib.printRectangle(Raylib::GRADIENT, _menuPos.at(_select).at(0), _menuPos.at(_select).at(1), {PINK, PINK});
            // for (std::size_t i = 0; i <= QUIT; ++i)
            //     lib.printText(_menuText[i], _menuPos[i].at(0), 30, BLACK);
            EndDrawing();
        }
        if (_select == QUIT)
            return (Core::Scenes::QUIT);
        return (Core::Scenes::QUIT);
    }
}

