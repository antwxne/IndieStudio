/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneIntro
*/

#include "Object/Collisionable/Wall/Wall.hpp"
#include "Object/Ground/Ground.hpp"
#include "Map/Map.hpp"
#include "SceneIntro.hpp"
#include "Object/UiObject/UiGame/TexteUi.hpp"
#include <vector>
#include <string>
#include <iostream>

const std::vector<std::string> SceneIntro::_assetsPath {
    "asset/background_asset/ground.png",
    "asset/OBJFormat/ground.obj",
};

SceneIntro::SceneIntro(Setting &settings) : AScene(settings)
{
    std::vector<std::pair<int, int>> size;

    for (auto &i : _objects)
        if (i->getTypeField().isTank)
            size.push_back(std::make_pair(static_cast<int>(i->getPosition().first), static_cast<int>(i->getPosition().third)));
    auto const &map = std::make_unique<Map>(size);
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));
    _objects.emplace_back(std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(_assetsPath.at(0), _assetsPath.at(1))));
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));

    _objects.emplace_back(std::make_shared<TexteUI>(coords(((settings._widthScreen / 2) - 50), ((settings._heightScreen / 4))), std::make_pair(100, 100), "Our Tank", 20, 1, std::make_pair(RGB(221, 131, 68), RGB())));
    _objects.emplace_back(std::make_shared<TexteUI>(coords(((settings._widthScreen / 2) - 150), ((settings._heightScreen / 1.1))), std::make_pair(50, 50), "press enter to start", 20, 1, std::make_pair(RGB(177, 129, 78), RGB())));
    setInputFunction(Raylib::ENTER, [&]() {
        _enter = !_enter;
    });
}

SceneIntro::~SceneIntro() noexcept
{
    _objects.clear();
}

Scenes SceneIntro::run(Raylib &lib, const Scenes &prevScene)
{
    while (lib.gameLoop() && !_enter) {
        triggerInputActions(lib);
            for (auto &i : _objects) {
                if (i->getTypeField().isText) {
                    std::dynamic_pointer_cast<TexteUI>(i)->upTextSize(1, 100, coords(-3, 0, 0));
                    break;
                }
            }
        lib.printObjects(_objects);
    }
    return (Scenes::MENU);
}