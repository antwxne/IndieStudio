/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** ScenePause
*/

#include "ScenePause.hpp"
#include "Core.hpp"
#include "Object/UiObject/Button/Button.hpp"

namespace pause {

    ScenePause::ScenePause(Setting &settings) : UiScene(settings)
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
                        _state = std::find(_pauseText.begin(), _pauseText.end(), button->getText()) - _pauseText.begin();
                        return;
                    }
                }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        for (std::size_t i = 0; i != _pauseText.size(); ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_pausePos.at(i), _pauseSize.at(i), button::_buttonNavigPath, _pauseText[i], 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
    }

    ScenePause::~ScenePause()
    {
    }

    void ScenePause::eventScene(Raylib &lib)
    {
        if (_state != -1 && _returnScene[_state] == Scenes::OPTION) {
            option::SceneOption option(_settings);
            option.run(lib);
            _state = -1;
        }
        lib.displayMusic(core::_musicPath, _settings._musicVol);
        if (lib.isMousePressed())
            lib.displaySound(core::_soundsPath, _settings._soundVol);
    }

    Scenes ScenePause::endScene(Raylib &lib) noexcept
    {
        auto tmp = _state;
        _state = -1;
        return (_returnScene[tmp]);
    }

}