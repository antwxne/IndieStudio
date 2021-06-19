/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneIntro
*/

#include "Core.hpp"
#include "Object/Collisionable/Wall/Wall.hpp"
#include "Object/Ground/Ground.hpp"
#include "Map/Map.hpp"
#include "Tank.hpp"
#include "SceneIntro.hpp"
#include "Object/UiObject/UiGame/TexteUi.hpp"
#include "Object/Collisionable/Destructible/Movable/Cannon.hpp"
#include <vector>
#include <string>
#include <iostream>

SceneIntro::SceneIntro(Setting &settings) : AScene(settings), _enter(false)
{
    std::vector<std::pair<float, float>> size;

    for (auto &i : _objects)
        if (i->getTypeField().isTank)
            size.push_back(std::make_pair(static_cast<int>(i->getPosition().first), static_cast<int>(i->getPosition().third)));
    auto const &map = std::make_unique<Map>(size);
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));
    _objects.emplace_back(std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(core::groundTexture, core::groundModel)));
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));

    _objects.emplace_back(std::make_shared<Tank>("tankRight", coords(-8,0,7), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
    std::dynamic_pointer_cast<Tank>(_objects.back())->rotateCannon(90);

    _objects.emplace_back(std::make_shared<Tank>("tankLeft", coords(8,0, -7), coords(10, 10, 10), 8, std::make_pair(Tank::bodyTexture, Tank::bodyModel), std::make_pair(Tank::darkGreen, Tank::cannonModel)));
    std::dynamic_pointer_cast<Tank>(_objects.back())->rotateCannon(270);

    _objects.emplace_back(std::make_shared<TexteUI>(coords(((settings._widthScreen / 2) - 50), ((settings._heightScreen / 4))), std::make_pair(100, 100), "Our Tank", 20, 1, std::make_pair(RGB(221, 131, 68), RGB())));
    _objects.emplace_back(std::make_shared<TexteUI>(coords(((settings._widthScreen / 2) - 110), ((settings._heightScreen / 1.1))), std::make_pair(50, 50), "press space to start", 20, 1, std::make_pair(RGB(177, 129, 78), RGB())));
    setInputFunction(Raylib::SPACE, [&]() {
        _enter = !_enter;
    });
}

SceneIntro::~SceneIntro() noexcept
{
    _objects.clear();
}

Scenes SceneIntro::run(Raylib &lib)
{
    std::vector<Direction> direction {NEUTRAL, NEUTRAL};

    while (!_enter) {
        if (!lib.gameLoop())
            return (Scenes::QUIT);
        lib.displayMusic(core::_animMusic, _settings._musicVol);
        int dir = 0;
        triggerInputActions(lib);
            for (auto &i : _objects) {
                if (i->getTypeField().isTank) {
                    if (std::dynamic_pointer_cast<Tank>(i)->getPosition().third >= 6)
                        direction.at(dir) = UP;
                    else if (std::dynamic_pointer_cast<Tank>(i)->getPosition().third <= -6)
                        direction.at(dir) = DOWN;
                    if (direction.at(dir) == UP)
                        std::dynamic_pointer_cast<Tank>(i)->move(coords(0, 0, -1));
                    else if (direction.at(dir) == DOWN)
                        std::dynamic_pointer_cast<Tank>(i)->move(coords(0, 0, 1));
                    ++dir;
                    if (dir == 2)
                        dir = 0;
                }
                else if (i->getTypeField().isText) {
                    std::dynamic_pointer_cast<TexteUI>(i)->upTextSize(1, 100, coords(-2, 0, 0));
                    break;
                }
            }
        lib.printObjects(_objects);
    }
    fadeBlack(lib, false);
    return (Scenes::MENU);
}