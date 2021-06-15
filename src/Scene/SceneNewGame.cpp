/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#include "UiObject/Button/Button.hpp"
#include "SceneNewGame.hpp"

namespace newGame {

    SceneNewGame::SceneNewGame(Setting &settings) : AScene(settings), _pressed(false), _select(-1)
    {
        setInputFunction(Raylib::PRESSED, [&]() {
            _pressed = true;
        });
        setInputFunction(Raylib::RELEASED, [&]() {
            _pressed = false;
            for (auto &it : _objects)
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    if (std::find(_menuText.begin(), _menuText.end(), button->getText()) != _menuText.end() && button->isInside(_mousePos)) {
                        _select = std::find(_menuText.begin(), _menuText.end(), button->getText()) - _menuText.begin();
                        return;
                    }
                    if (std::find(_playerIA.begin(), _playerIA.end(), button->getText()) != _playerIA.end() && button->isInside(_mousePos))
                        button->setText(button->getText() == _playerIA[0] ? _playerIA[1] : _playerIA[0]);
                }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        for (std::size_t i = 0; i != _menuPos.size(); ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), button::_buttonSize, button::_buttonNavigPath[button::buttonState_e::NOTHING], _menuText[i], 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
        for (std::size_t i = 0; i != _playerPos.size(); ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_playerPos.at(i), button::_buttonSize, button::_buttonPlayerPath[button::buttonState_e::NOTHING], _playerIA[0], 20, 1.5, std::make_pair(RGB(), RGB(0, 0, 0))));
    }

    SceneNewGame::~SceneNewGame()
    {
    }

    Scenes SceneNewGame::run(Raylib &lib, Scenes const &prevScene)
    {
        while (_select == -1) {
            _mousePos = lib.getMousePosition();
            triggerInputActions(lib);
            for (auto &it : _objects)
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    button->setState(_mousePos, std::find(_menuText.begin(), _menuText.end(), button->getText()) != _menuText.end() ? button::_buttonNavigPath : button::_buttonPlayerPath, _pressed);
                }
            lib.printObjects(_objects);
        }
        if (!_select)
            return (Scenes::MENU);
        return (Scenes::GAME);
    }

}