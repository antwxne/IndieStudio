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
    /**
     * @brief paths to animated object
     * 
     */
    const std::vector<std::string> assetsPath {
        "asset/Animation/idle/idle.iqm",
        "asset/Animation/idle/idleAnimation.iqm",
        "asset/Animation/dance/DanceAnim.iqm",
        "asset/Animation/textures/Soldier_Body_diffuse.png"
    };

    /**
     * @brief buttons un menu
     * @enum menu_e
     * 
     */
    enum menu_e {
        START,
        LOAD,
        OPTION,
        QUIT
    };
    /**
     * @brief assets paths
     * @enum assetsPath_e
     * 
     */
    enum assetsPath_e {
        BACKGROUND,
        MUSIC_BG,
        TIC,
        ACCEPT
    };
    /**
     * @brief text in button
     * 
     */
    static const std::vector<std::string> _menuText {
        "New game",
        "Load game",
        "Settings",
        "Quit"
    };

    /**
     * @brief position button
     * 
     */
    static const std::vector<struct coords> _menuPos {
        {coords(800.0f, 300.0f, 0.0f)},
        {coords(800.0f, 450.0f, 0.0f)},
        {coords(800.0f, 600.0f, 0.0f)},
        {coords(800.0f, 750.0f, 0.0f)},
    };
    /**
     * @brief back ground path
     * 
     */
    static const std::string _bgPath = "asset/background_asset/Background_01.png";
    /**
     * @brief associate button to scene
     * 
     */
    static const std::unordered_map<menu_e, Scenes> _returnScene {
        {menu_e::START,         Scenes::NEW_GAME},
        {menu_e::LOAD,          Scenes::GAME},
        {menu_e::OPTION,        Scenes::OPTION},
        {menu_e::QUIT,          Scenes::QUIT}
    };
    /**
     * @brief scene menu class
     * @class SceneMenu
     * 
     */
    class SceneMenu : public UiScene
    {
        public:
            /**
             * @brief Construct a new Scene Menu object
             * 
             * @param settings 
             */
            SceneMenu(Setting &settings);
            /**
             * @brief Destroy the Scene Menu object
             * 
             */
            ~SceneMenu();
            /**
             * @brief manage event in scene
             * 
             * @param lib 
             */
            void eventScene(Raylib &lib) final;
            /**
             * @brief end of the scene
             * 
             * @param lib 
             * @return Scenes 
             */
            Scenes endScene(Raylib &lib) noexcept final;
            /**
             * @brief try to open files
             * 
             * @return true 
             * @return false 
             */
            bool canOpen();
        private:
            /**
             * @brief bool to move the animation
             * 
             */
            bool _isDancing;
            /**
             * @brief is lock
             * 
             */
            bool _isLock;
    };
}

#endif /* !SCENEMENU_HPP_ */
