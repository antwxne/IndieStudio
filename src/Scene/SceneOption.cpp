/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#include "Core.hpp"
#include "SceneOption.hpp"
#include "UiObject/Button/Button.hpp"

namespace option {

    SceneOption::SceneOption(Setting &settings) : UiScene(settings)
    {
        setInputFunction(Raylib::RELEASED, [&]() {
            _pressed = !_pressed;
            for (auto &it : _objects) {
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    _state += button->isInside(_mousePos) && (button->getText() == _returnText);
                    if (button->isInside(_mousePos))
                        changeAudio(button->getText());
                }
            }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        _objects.emplace_back(std::make_shared<button::Button>(_menuPos, button::_buttonSize, button::_buttonNavigPath, _returnText, 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
        for (size_t i = 0; i != _configAudio.size(); ++i) {
            _objects.emplace_back(std::make_shared<button::Button>(_posAudio[i], button::_buttonSize, button::_buttonNavigPath, _configAudio[i], 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
        }
    }

    SceneOption::~SceneOption()
    {
    }

    void SceneOption::changeAudio(const std::string &name)
    {
        if (name.find("Music") != name.npos)
            _settings._musicVol = std::stof(name.substr(7)) / 100;
        else if (name.find("Sound") != name.npos)
            _settings._soundVol = std::stof(name.substr(7)) / 100;
    }

    void SceneOption::eventScene(Raylib &lib)
    {
        lib.displayMusic(core::_musicPath, _settings._musicVol);
        if (lib.isMousePressed())
            lib.displaySound(core::_soundsPath, _settings._soundVol);
    }

    Scenes SceneOption::endScene(Raylib &lib) noexcept
    {
        return (Scenes::MENU);
    }

}