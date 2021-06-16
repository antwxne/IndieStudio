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

    SceneMenu::SceneMenu(Setting &settings) : _select(-1), AScene(settings), _pressed(false)
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
                        _select = std::find(_menuText.begin(), _menuText.end(), button->getText()) - _menuText.begin();
                        return;
                    }
                }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        for (std::size_t i = 0; i != QUIT + 1; ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), _menuSize.at(i), button::_buttonNavigPath, _menuText[i], 20, 1, std::make_pair(RGB(), RGB(0, 0, 0))));
    }

    SceneMenu::~SceneMenu()
    {
        _objects.clear();
    }

    Scenes SceneMenu::run(Raylib &lib, Scenes const &prevScene)
    {
        lib.displayMusic(_musicPath, _settings._musicVol);
        while (_select == -1) {
            lib.updateMusic(_musicPath);
            _mousePos = lib.getMousePosition();
            triggerInputActions(lib);
            if (lib.isMousePressed())
                lib.displaySound(_soundsPath, _settings._soundVol);
            for (auto &it : _objects)
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    button->setState(_mousePos, _pressed);
                }
            lib.printObjects(_objects);
        }
        return (_returnScene.at(static_cast<menu_e>(_select)));
    }
}