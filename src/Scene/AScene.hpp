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

/**
 * @brief time to fade between scene
 * 
 */
static const std::size_t _frameFade = 25;

/**
 * @brief base class for scenes
 * @class AScene
 * 
 */
class AScene : public IScene
{
public:
    /**
     * @brief Construct a new AScene object
     * 
     * @param settings 
     */
    AScene(Setting &settings);
    /**
     * @brief Destroy the AScene object
     * 
     */
    virtual ~AScene() = default;

protected:
    /**
     * @brief do action with input
     * 
     * @param lib 
     */
    void triggerInputActions(Raylib &lib);
    /**
     * @brief fade between scene
     * 
     * @param lib 
     * @param out 
     */
    void fadeBlack(Raylib &lib, bool out);
    /**
     * @brief Set the Inputs First Tank object
     * 
     * @param controls 
     */
    void setInputsFirstTank(const std::array<Raylib::Inputs, 7> &controls);
    /**
     * @brief Set the Inputs Second Tank object
     * 
     * @param controls 
     */
    void setInputsSecondTank(const std::array<Raylib::Inputs, 7> &controls);
    /**
     * @brief Set the Inputs Tank object
     * 
     * @param controls 
     * @param tank 
     */
    void setInputsTank(const std::array<Raylib::Inputs, 7> &controls, std::shared_ptr<AObject> tank);
    /**
     * @brief Set the Input Function object
     * 
     * @param function 
     */
    void setInputFunction(Raylib::Inputs, std::function<void()> function);

    /**
     * @brief scene's settings
     * 
     */
    Setting &_settings;
    /**
     * @brief save inputs
     * 
     */
    std::vector<int> _inputSave;
    /**
     * @brief all objects in scene
     * 
     */
    std::vector<std::shared_ptr<AObject>> _objects;
    /**
     * @brief associate key to function
     * 
     */
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
    };
};
