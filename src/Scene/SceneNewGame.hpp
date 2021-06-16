/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#ifndef SCENENEWGAME_HPP_
#define SCENENEWGAME_HPP_

#include "Raylib.hpp"
#include "UiScene.hpp"

namespace newGame {

    static const std::vector<std::string> _menuText {
        "Return",
        "Start game"
    };

    static const std::vector<std::string> _playerIA {
        "IA",
        "Player"
    };

    static const std::vector<struct coords> _menuPos {
        {coords(200.0f,     900.0f, 0.0f)},
        {coords(1200.0f,    900.0f, 0.0f)}
    };

    static const std::vector<struct coords> _playerPos {
        {coords(200.0f,     200.0f, 0.0f)},
        {coords(600.0f,     200.0f, 0.0f)},
        {coords(1000.0f,    200.0f, 0.0f)},
        {coords(1400.0f,    200.0f, 0.0f)}
    };

    static const std::vector<struct coords> _inputPos {
        {coords(200.0f,     300.0f, 0.0f)},
        {coords(600.0f,     300.0f, 0.0f)},
        {coords(1000.0f,    300.0f, 0.0f)},
        {coords(1400.0f,    300.0f, 0.0f)}
    };

    static const std::string _bgPath = "asset/background_asset/Background_02.png";

    class SceneNewGame : public UiScene
    {
        public:
            SceneNewGame(Setting & settings);
            ~SceneNewGame();
            void eventScene(Raylib &lib) final;
            Scenes endScene(Scenes const &prevScene) noexcept final;

        private:
            void fillAi();
            void fillName();
    };

}
#endif /* !SCENENEWGAME_HPP_ */
