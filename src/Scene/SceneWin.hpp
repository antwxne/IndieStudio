/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneWin
*/

#ifndef SCENEWIN_HPP_
#define SCENEWIN_HPP_

#include "UiScene.hpp"

namespace win {

    static const std::vector<std::string> _menuText {
        "Main menu",
        "Re-match",
        "Quit"
    };

    static const std::vector<Scenes> _returnScene {
        Scenes::MENU,
        Scenes::NEW_GAME,
        Scenes::QUIT
    };

    static const std::string _bgPath = "asset/background_asset/Background_01.png";

    static const struct coords _textPos = coords(200.0f, 200.0f);

    static const std::vector<struct coords> _menuPos {
        {coords(200.0f,     900.0f)},
        {coords(700.0f,     900.0f)},
        {coords(1200.0f,    900.0f)}
    };

    class SceneWin : public UiScene
    {
        public:
            SceneWin(Setting &settings);
            ~SceneWin();
            void eventScene(Raylib &lib) final;
            Scenes endScene(Raylib &lib) noexcept final;
    };

}

#endif /* !SCENEWIN_HPP_ */
