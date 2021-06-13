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

namespace menu {

    SceneMenu::SceneMenu(std::shared_ptr<Setting> settings) : _select(menu_e::START), _enter(false), AScene(settings)
    {
        setInputFunction(Raylib::ENTER, [&]() {
            _enter = !_enter;
        });
        setInputFunction(Raylib::DOWN, [&]() {
            _select = (_select + 1) % (QUIT + 1);
        });
        setInputFunction(Raylib::UP, [&]() {
            _select = !_select ? QUIT : _select - 1;
        });
    }

    SceneMenu::~SceneMenu()
    {
    }

    void SceneMenu::InitAssets()
    {
        // _music = std::make_unique<RayMusic>(_musicPath, true, _settings->_musicVol);
        // for (auto &it : _soundsPath)
        //     _sounds.emplace_back(it, _settings->_soundVol);
        // _objects.emplace_back(std::make_unique<AObject>(std::make_unique<RayTexture2D>(_assetsPath.at(0))));
        // _objects.emplace_back(std::make_unique<AObject>(_menuPos[_select].at(0), std::make_pair(_menuPos[_select].at(1).first + 5, _menuPos[_select].at(1).second + 5), 1, std::make_pair(RGB(255, 127, 0, 255), RGB(255, 127, 0, 255)), std::make_unique<RaySquare>(objType_e::BASIC)));
        // for (auto &it : _menuPos)
        //     _objects.emplace_back(
        //         std::make_unique<AObject>(it.at(0), it.at(1), 1,
        //             std::make_pair(RGB(255, 0, 0, 255), RGB(255, 0, 0, 255)),
        //             std::make_unique<RaySquare>(objType_e::BASIC)));
        // for (std::size_t i = 0; i <= QUIT; ++i)
        //     _objects.emplace_back(std::make_unique<AObject>(_menuPos[i].at(0),
        //         std::make_pair(30, 30), 1,
        //         std::make_pair(RGB(0, 0, 0, 255), RGB(0, 0, 0, 255)),
        //         std::make_unique<RayText>(_menuText[i])));
    }

    Scenes SceneMenu::run(Raylib &lib, Scenes const &prevScene)
    {
        InitAssets();
        //_music->StartMusic();
        while (!_enter && lib.gameLoop()) {
            //_music->UpdateMusic();
            _objects.at(1)->setPosition(_menuPos[_select].at(0));
            triggerInputActions(lib);
            lib.printObjects(_objects);
        }
        return (_returnScene.at(static_cast<menu_e>(_select)));
    }
}