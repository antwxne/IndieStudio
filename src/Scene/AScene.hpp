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
#include "AObject.hpp"
#include "IScene.hpp"
#include "Setting.hpp"

static const std::size_t _frameFade = 25;

class AScene : public IScene
{
public:
    AScene(Setting &settings);
    virtual ~AScene() = default;

protected:
    void triggerInputActions(Raylib &lib);
    void fadeBlack(Raylib &lib, bool out);
    void setInputsFirstTank(const std::array<Raylib::Inputs, 7> &controls);
    void setInputsSecondTank(const std::array<Raylib::Inputs, 7> &controls);
    void setInputsTank(const std::array<Raylib::Inputs, 7> &controls, std::shared_ptr<AObject> tank);
    void setInputFunction(Raylib::Inputs, std::function<void()> function);

    Setting &_settings;
    std::vector<int> _inputSave;
    std::vector<std::shared_ptr<AObject>> _objects;
    std::unordered_map<int,std::function<void()>> _keys = {
        {Raylib::NULL_KEY, [](){}},
        {Raylib::ENTER, [](){}},
        {Raylib::SPACE, [](){}},
        {Raylib::ESCAPE, [](){}},
        {Raylib::TAB, [](){}},
        {Raylib::PRESSED, [](){}},
        {Raylib::RELEASED, [](){}},
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
        {Raylib::JLL, [](){}},
        {Raylib::JLR, [](){}},
        {Raylib::JRL, [](){}},
        {Raylib::JRR, [](){}},
        {Raylib::JRU, [](){}},
        {Raylib::JRD, [](){}},
        {Raylib::JA, [](){}},
    };
};
