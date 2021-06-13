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

Core::Core(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
    : _screenWidth(screenWidth), _screenHeight(screenHeight), _title(title), _fps(fps), _scenePos(0)
{
    _vecScenes.emplace_back(std::make_unique<SceneMaxime>());
    //_vecScenes.emplace_back(std::make_unique<menu::SceneMenu>());
}

Core::~Core()
{
}

void Core::start()
{
    Raylib lib;

    lib.createWindow(_screenWidth, _screenHeight, _title, _fps);
    while (_scenePos != QUIT) {
        _scenePos = _vecScenes.at(_scenePos)->run(lib);
    }
}
