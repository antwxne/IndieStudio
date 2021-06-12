/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#include "Core/Core.hpp"
#include <chrono>
#include "Raylib/Raylib.hpp"
#include "Object/AObject.hpp"
#include "Scene/SceneMenu.hpp"
#include "Raylib/RayObj/RayTexture2D.hpp"
#include "Raylib/RayObj/RaySquare.hpp"
#include "Raylib/RayObj/RayText.hpp"

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

    SceneMenu::SceneMenu() : _select(menu_e::START), _enter(false)
    {
        setInputFunction(Raylib::ENTER, [&](){_enter = !_enter;});
        setInputFunction(Raylib::DOWN, [&](){_select = (_select + 1) % (QUIT + 1);});
        setInputFunction(Raylib::UP, [&](){_select = !_select ? QUIT : _select - 1;});
    }

    SceneMenu::~SceneMenu()
    {
    }

    void SceneMenu::InitAssets()
    {
        _objects.emplace_back(std::make_unique<AObject>(std::make_pair(0, 0), std::make_pair(0, 0), std::make_unique<RayTexture2D>(_assetsPath.at(0))));
        _objects.emplace_back(std::make_unique<AObject>(_menuPos[_select].at(0), std::make_pair(_menuPos[_select].at(1).first + 5, _menuPos[_select].at(1).second + 5), std::make_pair(RGB(255, 127, 0, 255), RGB(255, 127, 0, 255)), std::make_unique<RaySquare>(objType_e::BASIC)));
        for (auto &it : _menuPos)
            _objects.emplace_back(std::make_unique<AObject>(it.at(0), it.at(1), std::make_pair(RGB(255, 0, 0, 255), RGB(255, 0, 0, 255)), std::make_unique<RaySquare>(objType_e::BASIC)));
        for (std::size_t i = 0; i <= QUIT; ++i)
            _objects.emplace_back(std::make_unique<AObject>(_menuPos[i].at(0), std::make_pair(30, 30), std::make_pair(RGB(0, 0, 0, 255), RGB(0, 0, 0, 255)), std::make_unique<RayText>(_menuText[i])));
    }

    int SceneMenu::run(Raylib &lib)
    {
        // Music music = LoadMusicStream(_assetsPath.at(assetsPath_e::MUSIC_BG).c_str());
        // Sound sound = LoadSound(_assetsPath.at(assetsPath_e::TIC).c_str());
        // Sound sound2 = LoadSound(_assetsPath.at(assetsPath_e::ACCEPT).c_str());

        // music.looping = true;
        // PlayMusicStream(music);
        while (!_enter && lib.gameLoop()) {
            // UpdateMusicStream(music);
                // PlaySound(sound2);
            _objects.at(1)->setPosition(_menuPos[_select].at(0));
            triggerInputActions(lib);
            lib.printObjects(_objects);
        }
        if (_select == QUIT)
            return (Core::Scenes::QUIT);
        return (Core::Scenes::QUIT);
    }
}

