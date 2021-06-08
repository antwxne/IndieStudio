/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#include "Core.hpp"
#include "Raylib.hpp"
#include "SceneTest.hpp"

Core::Core(int screenWidth = 1920, int screenHeight = 1080, std::string const &title = "default", std::size_t const fps = 60)
    : _screenWidth(screenWidth), _screenHeight(screenHeight), _title(title), _fps(fps)
{
}

Core::~Core()
{
}

void Core::start()
{
    Raylib lib;
    SceneTest sceneTest;

    lib.createWindow(_screenWidth, _screenHeight, _title, _fps);
    sceneTest.run(lib);
}
