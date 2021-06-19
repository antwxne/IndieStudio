/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#include "Core.hpp"
#include "Raylib.hpp"
#include <filesystem>

namespace core {

    Core::Core(int screenWidth, int screenHeight, std::string const &title, const std::size_t &fps)
        : _settings(screenWidth, screenHeight, fps, 1.0f, 1.0f), _scenePos(Scenes::NEW_GAME), _title(title)
    {
    }

    Core::~Core()
    {
    }

    void Core::start()
    {
        Raylib lib;

        lib.createWindow(_settings._widthScreen, _settings._heightScreen, _title, _settings._fps);
        while (_scenePos != QUIT) {
                _scene = _enumToConstructor.at(_scenePos)(_settings);
                if (_settings._statementLoad == true) {
                    _scenePos = Scenes::NEW_GAME;
                    _scene = _enumToConstructor.at(_scenePos)(_settings);
                    _settings._statementLoad = false;
                }
            _scenePos = _scene->run(lib);
            _scene.reset();
            lib.freeResources();
        }
    }
}
