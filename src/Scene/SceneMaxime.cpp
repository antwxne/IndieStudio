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

#include "Raylib/RayObj/RayTexture2D.hpp"
#include "Raylib/RayObj/RayModel.hpp"
#include "Raylib/RayObj/RaySquare.hpp"
#include "Raylib/RayObj/RayText.hpp"

const std::vector<std::string> SceneMaxime::_assetsPath {
    "asset/box_test/box-textures.png",
    "asset/box_test/Box.obj",
};

SceneMaxime::SceneMaxime()
{
    //init _objects
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

void SceneMaxime::InitAssets() {
    _objects.emplace_back(std::make_unique<AObject>(std::make_pair(0, 0), std::make_pair(0, 0), 1, std::make_unique<RayModel>(_assetsPath.at(0), _assetsPath.at(1))));
    _objects[0]->set3d(true);
}

int SceneMaxime::run(Raylib &lib)
{
    while (lib.gameLoop()) {
        lib.printObjects(_objects);
    }
    return (Core::Scenes::QUIT);
}