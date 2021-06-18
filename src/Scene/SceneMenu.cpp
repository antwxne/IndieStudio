/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#include <chrono>
#include "Core.hpp"
#include "Raylib.hpp"
#include <fstream>
#include "SceneMenu.hpp"
#include "UiGame/TexteUi.hpp"
#include "Button/Button.hpp"

namespace menu {

    SceneMenu::SceneMenu(Setting &settings) : UiScene(settings), _isDancing(false)
    {
        setInputFunction(Raylib::PRESSED, [&]() {
            _pressed = true;
        });
        setInputFunction(Raylib::RELEASED, [&]() {
            _pressed = false;
            for (auto &it : _objects)
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    if (button->isInside(_mousePos)) {
                        _state = std::find(_menuText.begin(), _menuText.end(), button->getText()) - _menuText.begin();
                        return;
                    }
                }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        for (std::size_t i = 0; i != QUIT + 1; ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), button::_buttonSize, button::_buttonNavigPath, _menuText[i], 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
        _objects.emplace_back(std::make_shared<TexteUI>(coords(670, 100), std::make_pair(0, 0), "DOOM TANK", 90, 1, std::make_pair(RGB(0, 0, 0), RGB())));
    }

    SceneMenu::~SceneMenu()
    {
        _objects.clear();
    }

    bool SceneMenu::canOpen()
    {
        std::ifstream file("tank.txt");
        std::ifstream map("destructibleList.txt");
        if(file.good() && map.good())
            return true;
        return false;
    }

    void SceneMenu::eventScene(Raylib &lib)
    {
        lib.displayMusic(core::_menuMusic, _settings._musicVol);
    }

    Scenes SceneMenu::endScene(Raylib &lib) noexcept
    {
        if (_state == 1) {
            if (canOpen() == true) {
                _settings.load = true;
            } else {
                _settings._statementLoad = true;
            }
        }            fadeBlack(lib);
        return (_returnScene.at(static_cast<menu_e>(_state)));
    }
}