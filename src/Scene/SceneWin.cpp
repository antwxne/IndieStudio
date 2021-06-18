/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneWin
*/

#include "SceneWin.hpp"
#include "UiObject/UiGame/TexteUi.hpp"

namespace win {

    SceneWin::SceneWin(Setting &settings) : UiScene(settings)
    {
        setInputFunction(Raylib::RELEASED, [&]() {
            _pressed = false;
            for (auto &it : _objects)
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    if (std::find(_menuText.begin(), _menuText.end(), button->getText()) != _menuText.end() && button->isInside(_mousePos)) {
                        _state = std::find(_menuText.begin(), _menuText.end(), button->getText()) - _menuText.begin();
                        return;
                    }
                }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        // _objects.emplace_back(std::make_shared<TexteUI>(_textPos, std::make_pair(0, 0), "Player " + std::find_if(_settings._playersSettings.begin(), _settings._playersSettings.end(), [](auto &player){return (player->isWin);})->name, 50, 1, std::make_pair(RGB(), RGB())));
        for (std::size_t i = 0; i != _menuPos.size(); ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), button::_buttonSize, button::_buttonNavigPath, _menuText[i], 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
    }

    SceneWin::~SceneWin()
    {
    }

    void SceneWin::eventScene(Raylib &lib)
    {

    }

    Scenes SceneWin::endScene(Raylib &lib) noexcept
    {
        return (_returnScene[_state]);
    }

}