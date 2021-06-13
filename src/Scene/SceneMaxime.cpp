/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#include "SceneMaxime.hpp"
#include "Core.hpp"
#include "Map/Map.hpp"

#include "Raylib/Raylib.hpp"
#include "Object/AObject.hpp"
#include "Object/Collisionable/Wall.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath {
    "asset/box_test/box-textures.png",
    "asset/box_test/Box.obj",
};

SceneMaxime::SceneMaxime(std::shared_ptr<Setting> settings) : AScene(settings)
{
    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

void SceneMaxime::InitAssets()
{
    //_objects.emplace_back(std::make_unique<Wall>(std::make_pair(0, 0), std::make_pair(0, 0), std::make_pair(_assetsPath.at(0), _assetsPath.at(1))));
    // _objects.at(0)->set3d(true);
    // _objects.at(0)->setScale(0.05f);
}

Scenes SceneMaxime::run(Raylib &lib, Scenes prevScene)
{
    InitAssets();
    while (!_enter && lib.gameLoop()) {
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}