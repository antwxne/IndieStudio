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
        : _title(title), _scenePos(Scenes::GAME), _settings(std::make_shared<Setting>(screenWidth, screenHeight, fps))
    {
    }

    Core::~Core()
    {
    }

    void Core::start()
    {
        Raylib lib;

        lib.createWindow(_settings->_widthScreen, _settings->_heightScreen, _title, _settings->_fps);
        while (_scenePos != QUIT) {
            _scene = _enumToConstructor.at(_scenePos)(_settings);
            _scenePos = _scene->run(lib, _scenePos);
            _scene.reset();
            lib.freeResources();
        }
    }
}
