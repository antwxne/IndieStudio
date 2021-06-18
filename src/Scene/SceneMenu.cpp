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

    SceneMenu::SceneMenu(Setting &settings) : UiScene(settings), _isDancing(false), _isLock(false)
    {
        setInputFunction(Raylib::PRESSED, [&]() {
            _pressed = true;
        });
        setInputFunction(Raylib::SPACE, [&]() {
        _isDancing = true;
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
        _objects.emplace_back(std::make_shared<Animator>(coords(5, 0, 11), std::make_pair(1, 1), std::make_pair(menu::assetsPath.at(3), menu::assetsPath.at(0)), menu::assetsPath.at(1)));
        _objects.back()->setScale(0.03f);
        for (std::size_t i = 0; i != QUIT + 1; ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), button::_buttonSize, button::_buttonNavigPath, _menuText[i], 20, 1, std::make_pair(RGB(), RGB(0, 0, 0))));
    }

    SceneMenu::~SceneMenu()
    {
        _objects.clear();
    }

    void SceneMenu::eventScene(Raylib &lib)
    {
        lib.displayMusic(core::_musicPath, _settings._musicVol);
        if (lib.isMousePressed())
            lib.displaySound(core::_soundsPath, _settings._soundVol);

        for (auto it = _objects.begin(); it != _objects.end();) {
            if (it->get()->getTypeField().isAnimator) {
                if (_isDancing && !_isLock) {
                    _objects.emplace_back(std::make_shared<Animator>(coords(5, 0, 11), std::make_pair(1, 1), std::make_pair(menu::assetsPath.at(3), menu::assetsPath.at(0)), menu::assetsPath.at(2)));
                    _objects.back()->setScale(0.03f);
                    it = _objects.erase(it);
                    _isLock = true;
                    continue;
                }
                auto anim = std::dynamic_pointer_cast<Animator>(*it);
                anim->addFrameCount(1);
                if (anim->getFrameActual() >= lib.getFrameMax(assetsPath.at(1)))
                    anim->setFrameCount(0);
            }
            it++;
        }
    }

    Scenes SceneMenu::endScene(Raylib &lib) noexcept
    {
        return (_returnScene.at(static_cast<menu_e>(_state)));
    }

}