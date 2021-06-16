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
        setInputFunction(Raylib::ENTER, [&]() {
            _quit = !_quit;
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        _objects.emplace_back(std::make_shared<button::Button>(_menuPos, button::_buttonSize, button::_buttonNavigPath, _returnText, 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
    }

    SceneOption::~SceneOption()
    {
    }

    void SceneOption::eventScene(Raylib &lib)
    {

    }

    Scenes SceneOption::endScene(Scenes const &prevScene) noexcept
    {

    }

}