/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AScene
*/

#include "AScene.hpp"
#include "MovableObject.hpp"
#include "Tank.hpp"
#include <cmath>

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

void AScene::setInputsNewTank()
{
    if (!_objects.back()->getTypeField().isTank)
        return;
    setInputFunction(_settings._keysPlayerOne[0], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(_objects.back());
        tank->move(coords(std::cos(tank->getRotationAngle()),0,std::sin(tank->getRotationAngle())));
    });
    setInputFunction(_settings._keysPlayerOne[1], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(_objects.back());
        tank->move(coords((std::cos(tank->getRotationAngle())) * (-1), 0, (std::sin(tank->getRotationAngle()) * (-1))));
    });
}