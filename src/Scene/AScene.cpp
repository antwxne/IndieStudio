/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AScene
*/

#include "AScene.hpp"
#include "FullSquare.hpp"
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

void AScene::setInputsTank(const std::array<Raylib::Inputs, 7> &controls, std::shared_ptr<AObject> obj)
{
    auto tank = std::dynamic_pointer_cast<Tank>(obj);
    setInputFunction(controls[0], [tank](){
        tank->move(coords(std::sin(M_PI * tank->getRotationAngle() / 180), 0, std::cos(M_PI * tank->getRotationAngle() / 180)));
    });
    setInputFunction(controls[1], [tank](){
        auto newAngle = (static_cast<int>(tank->getRotationAngle()) + 180) % 360;
        tank->move(coords(std::sin(M_PI *  newAngle / 180), 0, std::cos(M_PI * newAngle / 180)));
    });
    setInputFunction(controls[2], [tank](){ tank->rotate(1.0f); });
    setInputFunction(controls[3], [tank](){ tank->rotate(-1.0f); });
    setInputFunction(controls[4], [tank](){ tank->rotateCannon(1.5f); });
    setInputFunction(controls[5], [tank](){ tank->rotateCannon(-1.5f); });
    setInputFunction(controls[6], [tank](){ tank->fire(); });
}

void AScene::fadeBlack(Raylib &lib, bool out)
{
    _objects.emplace_back(std::make_shared<FullSquare>(coords(), std::make_pair(1920, 1080), 1, std::make_pair(RGB(0.0f, 0.0f, 0.0f, 0.0f + 255 * out), RGB())));
    for (std::size_t i = 0; i != 255 / 10; ++i) {
        auto color = _objects.back()->getColors();
        color.first.a += out ? -10 : 10;
        _objects.back()->setColor(color);
        lib.printObjects(_objects);
    }
    _objects.pop_back();
}