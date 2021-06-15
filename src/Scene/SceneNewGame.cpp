/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#include "UiObject/Button/Button.hpp"
#include "SceneNewGame.hpp"

namespace newGame {

    SceneNewGame::SceneNewGame(Setting &settings) : AScene(settings)
    {
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        for (std::size_t i = 0; i != 2; ++i)
            _objects.emplace_back(std::make_shared<Button>(_menuPos.at(i), _buttonSize, _buttonPath[buttonState_e::NOTHING], _menuText[i], 20, 1, std::make_pair(RGB(), RGB(0, 0, 0))));
    }

    SceneNewGame::~SceneNewGame()
    {
    }

    Scenes SceneNewGame::run(Raylib &lib, Scenes const &prevScene)
    {
        while (lib.gameLoop()) {
            triggerInputActions(lib);
            lib.printObjects(_objects);
        }
        if (lib.gameLoop())
            return (Scenes::QUIT);
        return (Scenes::GAME);
    }

}