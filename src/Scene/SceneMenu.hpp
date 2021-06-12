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
        QUIT
    };

    enum assetsPath_e {
        BACKGROUND,
        MUSIC_BG,
        TIC,
        ACCEPT
    };

    class SceneMenu : public AScene
    {
        public:
            SceneMenu();
            ~SceneMenu();
            int run(Raylib &lib) final;
            void InitAssets() final;
            bool clockGame();

        protected:
        private:
            std::size_t _select;
            bool _enter;
            static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
            static const std::vector<std::string> _assetsPath;
            static const std::vector<std::string> _menuText;
    };
}

#endif /* !SCENEMENU_HPP_ */
