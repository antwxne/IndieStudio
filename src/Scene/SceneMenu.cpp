/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#include <chrono>
#include "Core.hpp"
#include "Raylib.hpp"
#include "SceneMenu.hpp"
#include "Button/Button.hpp"

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
        // for (std::size_t i = 0; i != QUIT + 1; ++i)
        //     _objects.emplace_back(std::make_shared<Button>(_menuPos[i].at(0), _menuPos[i].at(1), _menuText[i]));
    }

    SceneMenu::~SceneMenu()
    {
        _objects.clear();
    }

    Scenes SceneMenu::run(Raylib &lib, Scenes const &prevScene)
    {
        //_music->StartMusic();
        while (!_enter && lib.gameLoop()) {
            //_music->UpdateMusic();
            //_objects.at(1)->setPosition(_menuPos[_select].at(0));
            triggerInputActions(lib);
            lib.printObjects(_objects);
        }
        if (lib.gameLoop())
            return (Scenes::QUIT);
        return (_returnScene.at(static_cast<menu_e>(_select)));
    }
}