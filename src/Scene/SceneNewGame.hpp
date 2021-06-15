/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneNewGame
*/

#ifndef SCENENEWGAME_HPP_
#define SCENENEWGAME_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

namespace newGame {

    static const std::vector<std::string> _menuText {
        "Return",
        "Start game"
    };

    static const std::vector<struct coords> _menuPos {
        {coords(300.0f, 800.0f, 0.0f)},
        {coords(1500.0f, 800.0f, 0.0f)}
    };

    static const std::vector<std::pair<float, float>> _menuSize {
        {std::make_pair(500.0f, 300.0f)},
        {std::make_pair(500.0f, 300.0f)}
    };

    static const std::string _bgPath = "asset/background_asset/Background_02.png";

    class SceneNewGame : public AScene
    {
        public:
            SceneNewGame(Setting & settings);
            ~SceneNewGame();
            Scenes run(Raylib &lib, Scenes const &prevScene) final;
        private:
            bool _play;
            bool _return;
    };

}
#endif /* !SCENENEWGAME_HPP_ */
