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

Core::Core(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
    : _screenWidth(screenWidth), _screenHeight(screenHeight), _title(title), _fps(fps)
{
}

Core::~Core()
{
}

void Core::start()
{
    Raylib lib;
    SceneRobin sceneRobin;
    SceneMaxime sceneMaxime;

    lib.createWindow(_screenWidth, _screenHeight, _title, _fps);
    sceneRobin.run(lib);
    // sceneMaxime.run(lib);
}
