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

    class SceneMenu : public AScene
    {
        public:
            SceneMenu();
            ~SceneMenu();
            void StartLoop(Raylib &lib);
            void InitAssets();

        protected:
        private:

            std::size_t _select;
            static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
            static const std::vector<std::string> _assetsPath;
    };
}

#endif /* !SCENEMENU_HPP_ */
