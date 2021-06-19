/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneWin
*/

#include "SceneWin.hpp"
#include "Setting.hpp"
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
        auto winner = std::find_if(settings._playersSettings.begin(), settings._playersSettings.end(), [](auto &player){return (!player.isLooser);});
        if (winner->type == PLAYER)
            _objects.emplace_back(std::make_shared<button::Button>(coords(960 - (button::_buttonSize.first * 5 / 2), 200), button::_buttonSize, button::_buttonWinnerPath, "Player " + winner->name + " Wins !", 15, 5, std::make_pair(RGB(), RGB(89, 102, 67))));
        else
            _objects.emplace_back(std::make_shared<button::Button>(coords(960 - (button::_buttonSize.first * 5 / 2), 200), button::_buttonSize, button::_buttonWinnerPath, "BOT " + winner->name + " Wins !", 15, 5, std::make_pair(RGB(), RGB(133, 6, 6))));
        for (std::size_t i = 0; i != _menuPos.size(); ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), button::_buttonSize, button::_buttonNavigPath, _menuText[i], 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
        std::sort(_settings._playersSettings.begin(), _settings._playersSettings.begin(), [](auto &player, auto &player2){return player.score < player2.score;});
        if (_settings._playersSettings.begin()->name != winner->name)
            std::iter_swap(_settings._playersSettings.begin(), std::find_if(_settings._playersSettings.begin(), _settings._playersSettings.end(), [winner](auto &it){return winner->name == it.name;}));
        for (auto it = 0; it != _settings._playersSettings.size(); ++it)
            _objects.emplace_back(std::make_shared<TexteUI>(coords(960 - (button::_buttonSize.first / 2), 500 + (100 * it)), button::_buttonSize, _settings._playersSettings[it].name + ": " + std::to_string(_settings._playersSettings[it].score) + "pts", 30, 4, std::make_pair(RGB(0, 0, 0), RGB(0, 0, 0))));
    }

    SceneWin::~SceneWin()
    {
    }

    void SceneWin::eventScene(Raylib &lib)
    {
        // lib.displayMusic();
    }

    Scenes SceneWin::endScene(Raylib &lib) noexcept
    {
        return (_returnScene[_state]);
    }

}