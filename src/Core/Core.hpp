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
#include "SceneMenu.hpp"
#include "SceneNewGame.hpp"
#include "SceneOption.hpp"
#include "SceneIntro.hpp"
#include "SceneSplash.hpp"
#include "SceneWin.hpp"
#include "SceneGame.hpp"

/**
 * @brief contains core's class
 * @namespace core
 * 
 */
namespace core {

    enum soundPath {
        MENU,
        GAME,
        SPLASH,
        ANIMATION,
        WIN,
        DEFEAT,
        PAUSE
    };

    /**
     * @brief all music filepath
     * 
     */
    static const std::unordered_map<soundPath, std::string> MAP_MUSIC = {
        {MENU,      "asset/music/menu_music.mp3"},
        {GAME,      "asset/music/game_music.mp3"},
        {SPLASH,    "asset/music/splash_music.mp3"},
        {ANIMATION, "asset/music/animation_music.mp3"},
        {WIN,       "asset/music/win_music.mp3"},
        {DEFEAT,    "asset/music/defeat_music.mp3"},
        {PAUSE,     "asset/music/pause_music.mp3"}
    };

    /**
     * @brief sound when mouseClick filepath
     * 
     */
    static const std::string _mouseClick = "asset/sound_effects/click.wav";
    /**
     * @brief sound when you pause the game
     * 
     */
    static const std::string _pauseClick = "asset/sound_effects/settings.wav";
    /**
     * @brief sound when you start the game
     * 
     */
    static const std::string _startGame = "asset/sound_effects/start_play.mp3";
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
        {Scenes::NEW_GAME,          [](Setting &settings){return std::make_unique<newGame::SceneNewGame>(settings);}},
        {Scenes::MENU,              [](Setting &settings){return std::make_unique<menu::SceneMenu>(settings);}},
        {Scenes::GAME,              [](Setting &settings){return std::make_unique<SceneGame>(settings);}},
        {Scenes::OPTION,            [](Setting &settings){return std::make_unique<option::SceneOption>(settings);}},
        {Scenes::ENDGAME,           [](Setting &settings){return std::make_unique<win::SceneWin>(settings);}}
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
