/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#include "Core.hpp"
#include "Raylib.hpp"
#include "SceneMaxime.hpp"
#include "SceneRobin.hpp"
#include "SceneMenu.hpp"
#include "SceneNewGame.hpp"
#include "SceneOption.hpp"
#include "SceneBoard.hpp"

namespace core {

    Core::Core(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
        : _screenWidth(screenWidth), _screenHeight(screenHeight), _title(title), _fps(fps), _scenePos(Scenes::MENU), _settings(std::make_shared<Setting>())
    {
        _vecScenes.emplace_back(std::make_unique<menu::SceneMenu>(_settings));
        //_vecScenes.emplace_back(std::make_unique<SceneNewGame>(_settings));
        _vecScenes.emplace_back(std::make_unique<SceneMaxime>(_settings));
        _vecScenes.emplace_back(std::make_unique<SceneRobin>(_settings));
        _vecScenes.emplace_back(std::make_unique<SceneOption>(_settings));
        _vecScenes.emplace_back(std::make_unique<SceneBoard>(_settings));
    }

    Core::~Core()
    {
    }

    void Core::start()
    {
        Raylib lib;
        SceneRobin sceneRobin(_settings);
        menu::SceneMenu menu(_settings);
        // SceneMaxime test3d;

        lib.createWindow(_screenWidth, _screenHeight, _title, _fps);
        // sceneRobin.run(lib);
        // test3d.run(lib);
        while (_scenePos != QUIT) {
            _scenePos = _vecScenes.at(_scenePos)->run(lib, _scenePos);
        }
        // // test3d.run(lib);
    }

}
