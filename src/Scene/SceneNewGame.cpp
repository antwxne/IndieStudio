/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#include <memory>
#include "UiObject/Button/Button.hpp"
#include "InputBox.hpp"
#include "TexteUi.hpp"
#include "Core.hpp"
#include "SceneNewGame.hpp"

namespace newGame {

    static const std::vector<std::string> _bonusButton {
        "Speed Up!",
        "Life Up!",
        "Damage Up!"
    };

    static const std::vector<std::string> _controllerText {
        "KeyBoard",
        "Controller"
    };

    SceneNewGame::SceneNewGame(Setting &settings) : UiScene(settings)
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
                    if (std::find(_playerIA.begin(), _playerIA.end(), button->getText()) != _playerIA.end() && button->isInside(_mousePos))
                        button->setText(_playerIA.at((std::find(_playerIA.begin(), _playerIA.end(), button->getText()) - _playerIA.begin() + 1) % _playerIA.size()));     //(button->getText() == _playerIA[0] ? _playerIA[1] : _playerIA[0]);
                }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        for (std::size_t i = 0; i != _menuPos.size(); ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), button::_buttonSize, button::_buttonNavigPath, _menuText[i], 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
        for (auto &it : _playerPos)
            _objects.emplace_back(std::make_shared<button::Button>(it, button::_buttonSize, button::_buttonPlayerPath, _playerIA[0], 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
        for (auto &it : _inputPos)
            _objects.emplace_back(std::make_shared<button::InputBox>(it, button::_buttonSize, button::_buttonNavigPath, 20, 15, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
        for (std::size_t i = 0; i != _inputPos.size() - 1; ++i) {
            _objects.emplace_back(std::make_shared<button::BoolButton>(coords(_inputPos.at(i).first, _inputPos.at(i).second + 100), button::_buttonSize, button::_soloPath, _controllerText[0 + (1 * (i >= 2))], 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
            _controllerButtons.emplace_back(std::dynamic_pointer_cast<button::BoolButton>(_objects.back()));
        }
        for (std::size_t i = 0; i != _bonusButton.size(); ++i) {
            _objects.emplace_back(std::make_shared<button::BoolButton>(coords(_inputPos.at(i).first + 200, _inputPos.at(i).second + 400), button::_buttonSize, button::_buttonNavigPath, _bonusButton[i], 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
            _bonusButtons.emplace_back(std::dynamic_pointer_cast<button::BoolButton>(_objects.back()));
        }
        _objects.emplace_back(std::make_shared<TexteUI>(coords(850 - 150, 65), std::make_pair(0, 0), "New Game", 110, 1, std::make_pair(RGB(0, 0, 0), RGB())));
        _objects.emplace_back(std::make_shared<TexteUI>(coords(910 - 110, 550), std::make_pair(0, 0), "Bonuses", 70, 1, std::make_pair(RGB(0, 0, 0), RGB())));
    }

    SceneNewGame::~SceneNewGame()
    {
    }

    void SceneNewGame::fillAi()
    {
        for (auto &it : _objects) {
            if (!it->getTypeField().isButton || it->getTypeField().isInputBox)
                continue;
            auto button = std::dynamic_pointer_cast<button::Button>(it);
            if (std::find(_playerIA.begin(), _playerIA.end(), button->getText()) == _playerIA.end() || button->getText() == "None")
                continue;
            std::srand(std::time(0));
            auto newPlayer = PlayerSettings();
            while (std::find_if(_settings._playersSettings.begin(), _settings._playersSettings.end(), [newPlayer](auto &it){return it.name == newPlayer.name;}) != _settings._playersSettings.end())
                newPlayer = PlayerSettings();
            _settings._playersSettings.emplace_back(newPlayer);
            _settings._playersSettings.back().type = static_cast<playerType>(std::find(_playerIA.begin(), _playerIA.end(), button->getText()) - _playerIA.begin());
        }
    }

    void SceneNewGame::fillName()
    {
        std::size_t fillSetting = 0;

        for (auto &it : _objects) {
            if (!it->getTypeField().isInputBox || fillSetting == _settings._playersSettings.size())
                continue;
            auto button = std::dynamic_pointer_cast<button::InputBox>(it);
            auto nbName = 0;
            for (auto &name : _settings._playersSettings)
                    nbName += name.name.find(button->getText()) != name.name.npos;
            if (nbName && !button->getText().empty())
                button->setText(button->getText() + "(" + std::to_string(nbName) + ")");
            if (!button->getText().empty()) {
                _settings._playersSettings[fillSetting].name = button->getText();
                ++fillSetting;
            }
        }
    }

    void SceneNewGame::eventScene(Raylib &lib)
    {
        char input;

        lib.displayMusic(core::MAP_MUSIC.at(core::soundPath::MENU), _settings._musicVol);
        input = lib.getPressedCharacter();
        std::for_each(_bonusButtons.begin(), _bonusButtons.end(), [&](auto &it) {
            it->setState(_mousePos, _pressed);
        });
        std::for_each(_objects.begin(), _objects.end(), [&, input](auto &it) {
            if (it->getTypeField().isInputBox) {
                auto button = std::dynamic_pointer_cast<button::InputBox>(it);
                button->changeText(input, _mousePos);
            }
        });
    }

    Scenes SceneNewGame::endScene(Raylib &lib) noexcept
    {
        if (!_state)
            return (Scenes::MENU);
        _settings._playersSettings.clear();
        fillAi();
        fillName();
        _settings.bonuses.SpeedUpBonus = _bonusButtons.at(0)->getPressed();
        _settings.bonuses.LifeUpBonus = _bonusButtons.at(1)->getPressed();
        _settings.bonuses.DamageUpBonus = _bonusButtons.at(2)->getPressed();
        return (Scenes::GAME);
    }
}