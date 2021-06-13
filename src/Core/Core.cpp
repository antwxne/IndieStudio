/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#include "Core.hpp"
#include "Raylib.hpp"

namespace core {

    Core::Core(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
        : _screenWidth(screenWidth), _screenHeight(screenHeight), _title(title), _fps(fps), _scenePos(Scenes::MENU), _settings(std::make_shared<Setting>())
    {
    }

    Core::~Core()
    {
    }

    void Core::start()
    {
        Raylib lib;

        lib.createWindow(_screenWidth, _screenHeight, _title, _fps);
        while (_scenePos != QUIT) {
            _scene = _enumToConstructor.at(_scenePos)(_settings);
            _scenePos = _scene->run(lib, _scenePos);
            _scene.reset();
        }
    }

}
