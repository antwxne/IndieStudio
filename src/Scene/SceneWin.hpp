/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneWin
*/

#ifndef SCENEWIN_HPP_
#define SCENEWIN_HPP_

#include "UiScene.hpp"
/**
 * @brief win's class
 * @namespace win
 * 
 */
namespace win {
    /**
     * @brief text in button
     * 
     */
    static const std::vector<std::string> _menuText {
        "Main menu",
        "Re-match",
        "Quit"
    };
    /**
     * @brief scene in button
     * 
     */
    static const std::vector<Scenes> _returnScene {
        Scenes::MENU,
        Scenes::NEW_GAME,
        Scenes::QUIT
    };
    /**
     * @brief background path
     * 
     */
    static const std::string _bgPath = "asset/background_asset/Background_01.png";

    /**
     * @brief text position
     * 
     */
    static const struct coords _textPos = coords(200.0f, 200.0f);
    /**
     * @brief position button
     * 
     */
    static const std::vector<struct coords> _menuPos {
        {coords(200.0f,     900.0f)},
        {coords(700.0f,     900.0f)},
        {coords(1200.0f,    900.0f)}
    };
    /**
     * @brief Scene win
     * @class SceneWin
     * 
     */
    class SceneWin : public UiScene
    {
        public:
            /**
             * @brief Construct a new Scene Win object
             * 
             * @param settings 
             */
            SceneWin(Setting &settings);
            /**
             * @brief Destroy the Scene Win object
             * 
             */
            ~SceneWin();
            /**
             * @brief manage event in scene
             * 
             * @param lib 
             */
            void eventScene(Raylib &lib) final;
            /**
             * @brief end of scene
             * 
             * @param lib 
             * @return Scenes 
             */
            Scenes endScene(Raylib &lib) noexcept final;
    };

}

#endif /* !SCENEWIN_HPP_ */
