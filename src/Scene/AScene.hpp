/*
** EPITECH PROJECT, 2021
** AScene.hpp
** File description:
** AScene.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Raylib.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "Settings.hpp"

class AScene : public IScene
{
public:
    AScene(std::shared_ptr<Setting> settings);
    virtual ~AScene() = default;

protected:
    void triggerInputActions(Raylib &lib);
    void setInputFunction(Raylib::Keys, std::function<void()> function);
    std::shared_ptr<Setting> _settings;
    std::vector<std::shared_ptr<IObject>> _objects;
    std::unordered_map<int,std::function<void()>> _keys = {
        {Raylib::NULL_KEY, [](){}},
        {Raylib::ENTER, [](){}},
        {Raylib::SPACE, [](){}},
        {Raylib::ESCAPE, [](){}},
        {Raylib::TAB, [](){}},
        {Raylib::UP, [](){}},
        {Raylib::DOWN, [](){}},
        {Raylib::RIGHT, [](){}},
        {Raylib::LEFT, [](){}},
        {Raylib::A, [](){}},
        {Raylib::B, [](){}},
        {Raylib::C, [](){}},
        {Raylib::D, [](){}},
        {Raylib::E, [](){}},
        {Raylib::E, [](){}},
        {Raylib::F, [](){}},
        {Raylib::G, [](){}},
        {Raylib::H, [](){}},
        {Raylib::I, [](){}},
        {Raylib::J, [](){}},
        {Raylib::K, [](){}},
        {Raylib::L, [](){}},
        {Raylib::M, [](){}},
        {Raylib::N, [](){}},
        {Raylib::O, [](){}},
        {Raylib::P, [](){}},
        {Raylib::Q, [](){}},
        {Raylib::R, [](){}},
        {Raylib::S, [](){}},
        {Raylib::T, [](){}},
        {Raylib::U, [](){}},
        {Raylib::V, [](){}},
        {Raylib::W, [](){}},
        {Raylib::X, [](){}},
        {Raylib::Y, [](){}},
        {Raylib::Z, [](){}},
    };
};
