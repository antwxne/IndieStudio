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
#include "Settings.hpp"
#include <memory>
#include <unordered_map>
#include "SceneMaxime.hpp"
#include "SceneRobin.hpp"
#include "SceneMenu.hpp"
#include "SceneNewGame.hpp"
#include "SceneOption.hpp"
#include "SceneBoard.hpp"

namespace core {

    static const std::unordered_map<Scenes, std::function<std::unique_ptr<IScene>(std::shared_ptr<Setting> settings)>> _enumToConstructor {
        {Scenes::MENU,          [](const std::shared_ptr<Setting> &settings){return std::make_unique<menu::SceneMenu>(settings);}},
        {Scenes::NEW_GAME,      [](const std::shared_ptr<Setting> &settings){return std::make_unique<SceneNewGame>(settings);}},
        {Scenes::LOAD,          [](const std::shared_ptr<Setting> &settings){return std::make_unique<SceneRobin>(settings);}},
        {Scenes::GAME,          [](const std::shared_ptr<Setting> &settings){return std::make_unique<SceneMaxime>(settings);}},
        {Scenes::OPTION,        [](const std::shared_ptr<Setting> &settings){return std::make_unique<SceneOption>(settings);}},
        {Scenes::LEADERBOARD,   [](const std::shared_ptr<Setting> &settings){return std::make_unique<SceneBoard>(settings);}}
    };

    class Core {
        public:
            Core(int screenWidth = 1920, int screenHeight = 1080, std::string const &title = "default", std::size_t const fps = 60);
            ~Core();

            void start();

        protected:
        private:
            std::unique_ptr<IScene> _scene;
            std::shared_ptr<Setting> _settings;
            Scenes _scenePos;
            std::string _title;
    };

}
#endif /* !CORE_HPP_ */
