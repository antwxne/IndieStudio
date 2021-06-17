/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP_
#define SCENEMENU_HPP_

#include <array>
#include "Scene/UiScene.hpp"

namespace menu {

    enum menu_e {
        START,
        LOAD,
        OPTION,
        QUIT
    };

    enum assetsPath_e {
        BACKGROUND,
        MUSIC_BG,
        TIC,
        ACCEPT
    };

    static const std::vector<std::string> _menuText {
        "New game",
        "Load game",
        "Settings",
        "Quit"
    };

    static const std::vector<struct coords> _menuPos {
        {coords(860.0f, 500.0f, 0.0f)},
        {coords(860.0f, 600.0f, 0.0f)},
        {coords(860.0f, 700.0f, 0.0f)},
        {coords(860.0f, 800.0f, 0.0f)},
    };

    static const std::string _bgPath = "asset/background_asset/Background_01.png";

    static const std::unordered_map<menu_e, Scenes> _returnScene {
        {menu_e::START,         Scenes::NEW_GAME},
        {menu_e::LOAD,          Scenes::GAME},
        {menu_e::OPTION,        Scenes::OPTION},
        {menu_e::QUIT,          Scenes::QUIT}
    };

    class SceneMenu : public UiScene
    {
        public:
            SceneMenu(Setting &settings);
            ~SceneMenu();
            void eventScene(Raylib &lib) final;
            Scenes endScene(Raylib &lib) noexcept final;
    };
}

#endif /* !SCENEMENU_HPP_ */
