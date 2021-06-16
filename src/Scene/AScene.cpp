/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AScene
*/

#include "AScene.hpp"
#include "MovableObject.hpp"
#include "Tank.hpp"

AScene::AScene(Setting &settings) : _settings(settings)
{
}

void AScene::triggerInputActions(Raylib &lib)
{
    int input = Raylib::NULL_KEY;
    std::unordered_map<int,std::function<void()>>::iterator itKey;

    for (auto const &key : lib.getKeysDown()) {
        itKey = _keys.find(key);
        if (itKey != _keys.end())
            itKey->second();
    }
    if (lib.isMouseDown()) {
        itKey = _keys.find(Raylib::PRESSED);
        if (itKey != _keys.end())
            itKey->second();
    }
    if (lib.isMouseReleased()) {
        itKey = _keys.find(Raylib::RELEASED);
        if (itKey != _keys.end())
            itKey->second();
    }
}

void AScene::setInputFunction(Raylib::Inputs key, std::function<void()> func)
{
    std::unordered_map<int,std::function<void()>>::iterator itKey;

    itKey = _keys.find(key);
    if (itKey != _keys.end())
        itKey->second = func;
}

//  - events not repeated if key keep being pressed
#include <math.h>
void AScene::setTankInputs()
{
    setInputFunction(_settings._keysPlayerOne[0], [this](){
        auto x = std::dynamic_pointer_cast<Tank>(_objects.back());
        x->move(coords(cos(x->getRotation()),0,sin(x->getRotation())));
    });
    setInputFunction(_settings._keysPlayerOne[1], [this](){
        auto x = std::dynamic_pointer_cast<Tank>(_objects.back());
        x->move(coords((cos(x->getRotation())) * (-1), 0, (sin(x->getRotation()) * (-1))));
    });
    // setInputFunction(keys[0], [](Tank &tank){tank.move(coords(cos(tank.getRotation()), 0, sin(tank.getRotation())));});
}