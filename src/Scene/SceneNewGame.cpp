/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#include "UiObject/Button/Button.hpp"
#include "InputBox.hpp"
#include "Core.hpp"
#include "TexteUi.hpp"
#include "SceneNewGame.hpp"

namespace newGame {

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
            _objects.emplace_back(std::make_shared<InputBox>(it, button::_buttonSize, button::_buttonNavigPath, 20, 15, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
        _objects.emplace_back(std::make_shared<TexteUI>(coords(670, 100), std::make_pair(0, 0), "New Game", 90, 1, std::make_pair(RGB(0, 0, 0), RGB())));
    }

    SceneNewGame::~SceneNewGame()
    {
    }

    void SceneNewGame::fillAi()
    {
        std::size_t fillStruct = 0;

        for (auto &it : _objects) {
            if (!it->getTypeField().isButton || it->getTypeField().isInputBox)
                continue;
            auto button = std::dynamic_pointer_cast<button::Button>(it);
            _settings._playersSettings[fillStruct].type = static_cast<playerType>(std::find(_playerIA.begin(), _playerIA.end(), button->getText()) - _playerIA.begin());
            ++fillStruct;
        }
    }

    void SceneNewGame::fillName()
    {
        std::size_t fillStruct = 0;

        for (auto &it : _objects) {
            if (!it->getTypeField().isInputBox)
                continue;
            auto button = std::dynamic_pointer_cast<button::Button>(it);
            if (!button->getText().empty())
                _settings._playersSettings[fillStruct].name.assign(button->getText());
            ++fillStruct;
        }
    }

    void SceneNewGame::eventScene(Raylib &lib)
    {
        char input;

        lib.displayMusic(core::_menuMusic, _settings._musicVol);
        input = lib.getPressedCharacter();
        std::for_each(_objects.begin(), _objects.end(), [&, input](auto &it){
            if (it->getTypeField().isInputBox) {
                auto button = std::dynamic_pointer_cast<InputBox>(it);
                button->changeText(input, _mousePos);
            }
        });
    }

    Scenes SceneNewGame::endScene(Raylib &lib) noexcept
    {
        fillAi();
        fillName();
        if (!_state)
            return (Scenes::MENU);
        return (Scenes::GAME);
    }

}