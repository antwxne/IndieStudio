/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#include "SceneOption.hpp"
#include "UiObject/Button/Button.hpp"
#include "TexteUi.hpp"
#include "Core.hpp"

namespace option {

    SceneOption::SceneOption(Setting &settings) : UiScene(settings)
    {
        setInputFunction(Raylib::RELEASED, [&]() {
            _pressed = !_pressed;
            for (auto &it : _objects) {
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    _state += button->isInside(_mousePos) && (button->getText() == _returnText);
                    if (button->isInside(_mousePos)) {
                        changeAudio(button->getText());
                    }
                }
            }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        _objects.emplace_back(std::make_shared<TexteUI>(coords(670, 100), std::make_pair(0, 0), "Option", 90, 1, std::make_pair(RGB(0, 0, 0), RGB())));
        _objects.emplace_back(std::make_shared<button::Button>(_menuPos, button::_buttonSize, button::_buttonNavigPath, _returnText, 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
        for (size_t i = 0; i != _configAudio.size(); ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_posAudio[i], button::_buttonSize, button::_buttonNavigPath, _configAudio[i], 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
        _objects.emplace_back(std::make_shared<TexteUI>(coords(_posBindingP1.begin()->first, _posBindingP1.begin()->second - 50), std::make_pair(0, 0), "P1", 30, 1, std::make_pair(RGB(0, 0, 0), RGB())));
        _objects.emplace_back(std::make_shared<TexteUI>(coords(_posBindingP2.begin()->first, _posBindingP2.begin()->second - 50), std::make_pair(0, 0), "P2", 30, 1, std::make_pair(RGB(0, 0, 0), RGB())));
        for (size_t i = 0; i != _settings._keysPlayerOne.size(); ++i) {
            _objects.emplace_back(std::make_shared<TexteUI>(coords(_posBindingP1[i].first - 200, _posBindingP1[i].second + 10), std::make_pair(0, 0), _textBinding[i], 30, 1, std::make_pair(RGB(0, 0, 0), RGB())));
            _objects.emplace_back(std::make_shared<button::Button>(_posBindingP1[i], button::_buttonSettingSize, button::_buttonSettingPath, std::find_if(_inputToText.begin(), _inputToText.end(), [&, i] (auto &in) {return (in.first == _settings._keysPlayerOne[i]);})->second, 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
            _buttons.emplace_back(std::dynamic_pointer_cast<button::Button>(_objects.back()));
        }
        for (size_t i = 0; i != _settings._keysPlayerTwo.size(); ++i) {
            _objects.emplace_back(std::make_shared<button::Button>(_posBindingP2[i], button::_buttonSettingSize, button::_buttonSettingPath, std::find_if(_inputToText.begin(), _inputToText.end(), [&, i] (auto &in) {return (in.first == _settings._keysPlayerTwo[i]);})->second, 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
            _buttons.emplace_back(std::dynamic_pointer_cast<button::Button>(_objects.back()));
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
        auto in = 0;

        lib.displayMusic(core::MAP_MUSIC.at(core::soundPath::MENU), _settings._musicVol);
        in = lib.getKeyPressed();
        for (auto &it : _buttons) {
            if (it->isInside(_mousePos)) {
                if (std::find_if(_inputToText.begin(), _inputToText.end(), [in](auto &text){return in == text.first;}) == _inputToText.end())
                    continue;
                it->clearText();
                it->setText(std::find_if(_inputToText.begin(), _inputToText.end(), [in](auto &text){return in == text.first;})->second);
            }
        }
    }

    Scenes SceneOption::endScene(Raylib &lib) noexcept
    {
        for (std::size_t i = 0; i != 7; ++i)
            _settings._keysPlayerOne[i] = std::find_if(_inputToText.begin(), _inputToText.end(), [&, i](auto &text){return _buttons[i]->getText() == text.second;})->first;
        for (std::size_t i = 0; i != 7; ++i)
            _settings._keysPlayerTwo[i] = std::find_if(_inputToText.begin(), _inputToText.end(), [&, i](auto &text){return _buttons[i + 7]->getText() == text.second;})->first;
        return (Scenes::MENU);
    }

}