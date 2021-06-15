/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#include "Core.hpp"
#include "Raylib.hpp"

namespace core {

<<<<<<< HEAD
    Core::Core(int screenWidth, int screenHeight, std::string const &title, const std::size_t &fps)
        : _settings(screenWidth, screenHeight, fps, 1.0f, 1.0f), _scenePos(Scenes::MENU), _title(title)
=======
    Core::Core(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
        : _title(title), _scenePos(Scenes::MENU), _settings(screenWidth, screenHeight, fps)
>>>>>>> 45b6de4b5229598a7bd0f302740cc8b3f941e278
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
            _scenePos = _scene->run(lib, _scenePos);
            _scene.reset();
            lib.freeResources();
        }
    }
}
