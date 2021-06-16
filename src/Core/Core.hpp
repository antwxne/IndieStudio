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

namespace core {

    static const std::unordered_map<Scenes, std::function<std::unique_ptr<IScene>(Setting &settings)>> _enumToConstructor {
        // {Scenes::NEW_GAME,      [](Setting &settings){return std::make_unique<newGame::SceneNewGame>(settings);}},
        {Scenes::MENU,          [](Setting &settings){return std::make_unique<SceneRobin>(settings);}},
        // {Scenes::GAME,          [](Setting &settings){return std::make_unique<SceneMaxime>(settings);}},
        // {Scenes::LOAD,          [](const Setting & &settings){return std::make_unique<SceneRobin>(settings);}},
        // {Scenes::OPTION,        [](const Setting & &settings){return std::make_unique<SceneOption>(settings);}},
        // {Scenes::LEADERBOARD,   [](const Setting & &settings){return std::make_unique<SceneBoard>(settings);}}
    };
    /**
     * @class Core
     * @brief core of the game
     */
    class Core {
        public:
            Core(int screenWidth = 1920, int screenHeight = 1080, std::string const &title = "default", const std::size_t &fps = 60);
            ~Core();

            void start();

        protected:
        private:
            std::unique_ptr<IScene> _scene;
            Setting _settings;
            Scenes _scenePos;
            std::string _title;
    };

}
#endif /* !CORE_HPP_ */
