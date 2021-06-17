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

std::shared_ptr<AObject> const &AScene::getNthTank(const std::size_t &n)
{
    std::size_t counter = 1;

    for (auto &object : _objects) {
        if (object->getTypeField().isTank) {
            std::cout << "counter: " << counter << std::endl;
            if (counter == n)
                return object;
            counter += 1;
        }
    }
    return *(_objects.begin());
}

void AScene::setInputsFirstTank(const std::array<Raylib::Inputs, 7> &controls)
{
    setInputFunction(controls[0], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(1));
        tank->move(coords(std::sin(M_PI * tank->getRotationAngle() / 180), 0, std::cos(M_PI * tank->getRotationAngle() / 180)));
    });
    setInputFunction(controls[1], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(1));
        auto newAngle = (static_cast<int>(tank->getRotationAngle()) + 180) % 360;
        tank->move(coords(std::sin(M_PI *  newAngle / 180), 0, std::cos(M_PI * newAngle / 180)));
    });
    setInputFunction(controls[2], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(1));
        tank->rotate(0.8f);
    });
    setInputFunction(controls[3], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(1));
        tank->rotate(-0.8f);
    });
    setInputFunction(controls[4], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(1));
        tank->rotateCannon(1.2f);
    });
    setInputFunction(controls[5], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(1));
        tank->rotateCannon(-1.2f);
    });
}

void AScene::setInputsSecondTank(const std::array<Raylib::Inputs, 7> &controls)
{
    setInputFunction(controls[0], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(2));
        tank->move(coords(std::sin(M_PI * tank->getRotationAngle() / 180), 0, std::cos(M_PI * tank->getRotationAngle() / 180)));
    });
    setInputFunction(controls[1], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(2));
        auto newAngle = (static_cast<int>(tank->getRotationAngle()) + 180) % 360;
        tank->move(coords(std::sin(M_PI *  newAngle / 180), 0, std::cos(M_PI * newAngle / 180)));
    });
    setInputFunction(controls[2], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(2));
        tank->rotate(0.8f);
    });
    setInputFunction(controls[3], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(2));
        tank->rotate(-0.8f);
    });
    setInputFunction(controls[4], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(2));
        tank->rotateCannon(1.2f);
    });
    setInputFunction(controls[5], [this](){
        auto tank = std::dynamic_pointer_cast<Tank>(getNthTank(2));
        tank->rotateCannon(-1.2f);
    });
}