/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include "Scene/IScene.hpp"
#include "Setting.hpp"
#include <memory>
#include <unordered_map>
#include "SceneMaxime.hpp"
#include "SceneRobin.hpp"
#include "SceneMenu.hpp"
#include "SceneNewGame.hpp"
#include "SceneOption.hpp"
#include "SceneBoard.hpp"
#include "SceneIntro.hpp"
#include "SceneSplash.hpp"
#include "SceneWin.hpp"
#include "SceneGame.hpp"

namespace core {
    /**
     * @brief menu music file path
     * 
     */
    static const std::string _menuMusic = "asset/music/menu_music.mp3";
    /**
     * @brief game music file path
     * 
     */
    static const std::string _gameMusic = "asset/music/game_music.mp3";
    /**
     * @brief win music file path
     * 
     */
    static const std::string _winMusic = "asset/music/win_music.mp3";
    /**
     * @brief splash menu music file path
     * 
     */
    static const std::string _splashMusic = "asset/music/splash_music.mp3";
    /**
     * @brief animation music file path
     * 
     */
    static const std::string _animMusic = "asset/music/animation_music.mp3";
    /**
     * @brief mouse clic sound file path
     * 
     */
    static const std::string _mouseClick = "asset/sound_effects/click.wav";
    /**
     * @brief sound when mouseOver filepath
     * 
     */
    static const std::string _mouseOver = "asset/sound_effects/over.wav";
    /**
     * @brief ground asset filepath
     * 
     */
    static const std::string groundTexture = "asset/background_asset/ground.png";
    /**
     * @brief ground model file path
     * 
     */
    static const std::string groundModel = "asset/OBJFormat/ground.obj";
    /**
     * @brief power up model filepath
     * 
     */
    static const std::string powerUpModel = "asset/bonus/arrow.obj";

    /**
     * @brief map to associate enum to scene
     * 
     */
    static const std::unordered_map<Scenes, std::function<std::unique_ptr<IScene>(Setting &settings)>> _enumToConstructor {
        {Scenes::SPLASHSCREEN,      [](Setting &settings){return std::make_unique<newGame::SceneNewGame>(settings);}},
        {Scenes::INTRODUCTION,      [](Setting &settings){return std::make_unique<SceneIntro>(settings);}},
        {Scenes::NEW_GAME,      [](Setting &settings){return std::make_unique<newGame::SceneNewGame>(settings);}},
        {Scenes::MENU,          [](Setting &settings){return std::make_unique<menu::SceneMenu>(settings);}},
        {Scenes::GAME,          [](Setting &settings){return std::make_unique<SceneGame>(settings);}},
        {Scenes::OPTION,        [](Setting &settings){return std::make_unique<option::SceneOption>(settings);}},
        // {Scenes::LOAD,          [](const Setting & &settings){return std::make_unique<SceneRobin>(settings);}},
        // {Scenes::LEADERBOARD,   [](const Setting & &settings){return std::make_unique<SceneBoard>(settings);}}
    };
    /**
     * @class Core
     * @brief core of the game
     */
    class Core {
        public:
            /**
             * @brief Construct a new Core object
             * 
             * @param screenWidth 
             * @param screenHeight 
             * @param title 
             * @param fps 
             */
            Core(int screenWidth = 1920, int screenHeight = 1080, std::string const &title = "default", const std::size_t &fps = 60);
            /**
             * @brief Destroy the Core object
             * 
             */
            ~Core();
            /**
             * @brief start game
             * 
             */
            void start();

        protected:
        private:
            /**
             * @brief current scene
             * 
             */
            std::unique_ptr<IScene> _scene;
            /**
             * @brief settings
             * 
             */
            Setting _settings;
            /**
             * @brief number of the scene
             * 
             */
            Scenes _scenePos;
            /**
             * @brief title of the scene
             * 
             */
            std::string _title;
    };

}
#endif /* !CORE_HPP_ */
