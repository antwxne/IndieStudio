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
#include "BoolButton.hpp"

/**
 * @brief new game's class
 * @namespace newGame
 * 
 */
namespace newGame {
    /**
     * @brief text in button in text
     * 
     */
    static const std::vector<std::string> _menuText {
        "Return",
        "Start game"
    };
    /**
     * @brief different state for player
     * 
     */
    static const std::vector<std::string> _playerIA {
        "IA",
        "Player",
        "None"
    };
    /**
     * @brief position for buttons
     * 
     */
    static const std::vector<struct coords> _menuPos {
        {coords(200.0f,     900.0f, 0.0f)},
        {coords(1200.0f,    900.0f, 0.0f)}
    };
    /**
     * @brief position for player button
     * 
     */
    static const std::vector<struct coords> _playerPos {
        {coords(200.0f,     200.0f, 0.0f)},
        {coords(600.0f,     200.0f, 0.0f)},
        {coords(1000.0f,    200.0f, 0.0f)},
        {coords(1400.0f,    200.0f, 0.0f)}
    };
    /**
     * @brief position for input box
     * 
     */
    static const std::vector<struct coords> _inputPos {
        {coords(200.0f,     300.0f, 0.0f)},
        {coords(600.0f,     300.0f, 0.0f)},
        {coords(1000.0f,    300.0f, 0.0f)},
        {coords(1400.0f,    300.0f, 0.0f)}
    };
    /**
     * @brief background path
     * 
     */
    static const std::string _bgPath = "asset/background_asset/Background_02.png";
    /**
     * @brief scene New game selection option
     * @class SceneNewGame
     * 
     */
    class SceneNewGame : public UiScene
    {
        public:
            /**
             * @brief Construct a new Scene New Game object
             * 
             * @param settings 
             */
            SceneNewGame(Setting & settings);
            /**
             * @brief Destroy the Scene New Game object
             * 
             */
            ~SceneNewGame();
            /**
             * @brief manage event in scene
             * 
             * @param lib 
             */
            void eventScene(Raylib &lib) final;
            /**
             * @brief ending of the scene
             * 
             * @param lib 
             * @return Scenes 
             */
            Scenes endScene(Raylib &lib) noexcept final;

        private:
            /**
             * @brief create AI
             * 
             */
            void fillAi();
            /**
             * @brief set name of players / AI
             * 
             */
            void fillName();
            /**
             * @brief buttons for controller
             * 
             */
            std::vector<std::shared_ptr<button::BoolButton>> _controllerButtons;
            /**
             * @brief set bonus needed
             * 
             */
            std::vector<std::shared_ptr<button::BoolButton>> _bonusButtons;
    };

}
#endif /* !SCENENEWGAME_HPP_ */
