/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP_
#define SCENEMENU_HPP_

#include <array>
#include "Scene/AScene.hpp"

namespace menu {

    enum menu_e {
        START,
        LOAD,
        OPTION,
        LEADERBOARD,
        QUIT
    };

    enum assetsPath_e {
        BACKGROUND,
        MUSIC_BG,
        TIC,
        ACCEPT
    };

    static const std::vector<std::string> _menuText {
        "Start game",
        "Load game",
        "Settings",
        "Leaderboard",
        "Quit"
    };

    static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos {
        {{std::make_pair(860.0f, 500.0f), std::make_pair(200.0f, 50.0f)}},
        {{std::make_pair(860.0f, 600.0f), std::make_pair(200.0f, 50.0f)}},
        {{std::make_pair(860.0f, 700.0f), std::make_pair(200.0f, 50.0f)}},
        {{std::make_pair(860.0f, 800.0f), std::make_pair(200.0f, 50.0f)}},
        {{std::make_pair(860.0f, 900.0f), std::make_pair(200.0f, 50.0f)}}
    };

    static const std::vector<std::string> _assetsPath {
        "Assets/olivier_bg.png",
    };

    static const std::vector<std::string> _soundsPath {
        "truc_tank/Sample_0000.wav",
        "truc_tank/Sample_0005.wav"
    };

    static const std::unordered_map<menu_e, Scenes> _returnScene {
        {menu_e::START, Scenes::NEW_GAME},
        {menu_e::LOAD, Scenes::GAME},
        {menu_e::OPTION, Scenes::OPTION},
        {menu_e::LEADERBOARD, Scenes::LEADERBOARD},
        {menu_e::QUIT, Scenes::QUIT}
    };

    static const std::string _musicPath = "Assets/menu_music.mp3";

    class SceneMenu : public AScene
    {
        public:
            SceneMenu(std::shared_ptr<Setting> settings);
            ~SceneMenu();
            Scenes run(Raylib &lib, Scenes const &prevScene) final;
            void InitAssets() final;
            bool clockGame();

        protected:
        private:
            std::size_t _select;
            bool _enter;
    };
}

#endif /* !SCENEMENU_HPP_ */
