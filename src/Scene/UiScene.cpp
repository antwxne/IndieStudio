/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** UiScene
*/

#include "UiScene.hpp"
#include "Core.hpp"

UiScene::UiScene(Setting &settings) : AScene(settings), _pressed(false), _state(-1)
{
    setInputFunction(Raylib::PRESSED, [&]() {
        _pressed = true;
    });
}

UiScene::~UiScene()
{
    _objects.clear();
}

Scenes UiScene::run(Raylib &lib)
{
    while (_state == -1) {
        _mousePos = lib.getMousePosition();
        triggerInputActions(lib);
        if (lib.isMousePressed())
            lib.displaySound(core::_mouseClick, _settings._soundVol);
        std::for_each(_objects.begin(), _objects.end(), [&](auto &it){
            if (it->getTypeField().isButton) {
                auto button = std::dynamic_pointer_cast<button::Button>(it);
                button->setState(_mousePos, _pressed);
            }
        });
        eventScene(lib);
        lib.printObjects(_objects);
    }
    return (endScene(lib));
}