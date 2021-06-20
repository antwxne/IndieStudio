/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#ifndef SCENEOPTION_HPP_
#define SCENEOPTION_HPP_

#pragma once
#include "Raylib.hpp"
#include "UiObject/Button/InputBox/InputBox.hpp"
#include "UiScene.hpp"

/**
 * @brief option's class
 * @namespace option 
 * 
 */
namespace option {
    /**
     * @brief text in return button
     * 
     */
    static const std::string _returnText = "Return";
    /**
     * @brief pos button
     * 
     */
    static const struct coords _menuPos = coords(200.0f, 900.0f, 0.0f);
    /**
     * @brief background path
     * 
     */
    static const std::string _bgPath = "asset/background_asset/Background_02.png";
    /**
     * @brief text in audio configuration buttons
     * 
     */
    static const std::array<std::string, 6> _configAudio {
        "Music: 0%",
        "Music: 50%",
        "Music: 100%",
        "Sound: 0%",
        "Sound: 50%",
        "Sound: 100%"
    };
    /**
     * @brief position for audio button
     * 
     */
    static const std::array<coords, 6> _posAudio {
        coords(200, 300),
        coords(500, 300),
        coords(800, 300),
        coords(200, 500),
        coords(500, 500),
        coords(800, 500)
    };
    /**
     * @brief position for binding player 1
     * 
     */
    static const std::vector<coords> _posBindingP1 {
        coords(1500, 300),
        coords(1500, 380),
        coords(1500, 460),
        coords(1500, 540),
        coords(1500, 620),
        coords(1500, 700),
        coords(1500, 780)
    };
    /**
     * @brief position for binding player 2
     * 
     */
    static const std::vector<coords> _posBindingP2 {
        coords(1600, 300),
        coords(1600, 380),
        coords(1600, 460),
        coords(1600, 540),
        coords(1600, 620),
        coords(1600, 700),
        coords(1600, 780)
    };
    /**
     * @brief text description for binding
     * 
     */
    static const std::vector<std::string> _textBinding {
        "Forward",
        "Backward",
        "Left",
        "Right",
        "Canon left",
        "Canon right",
        "Fire"
    };
    /**
     * @brief display binding
     * 
     */
    static const std::vector<std::pair<Raylib::Inputs, std::string>> _inputToText {
        {Raylib::Inputs::A,     "A"},
        {Raylib::Inputs::B,     "B"},
        {Raylib::Inputs::C,     "C"},
        {Raylib::Inputs::D,     "D"},
        {Raylib::Inputs::E,     "E"},
        {Raylib::Inputs::F,     "F"},
        {Raylib::Inputs::G,     "G"},
        {Raylib::Inputs::H,     "H"},
        {Raylib::Inputs::I,     "I"},
        {Raylib::Inputs::J,     "J"},
        {Raylib::Inputs::K,     "K"},
        {Raylib::Inputs::L,     "L"},
        {Raylib::Inputs::M,     "M"},
        {Raylib::Inputs::N,     "N"},
        {Raylib::Inputs::O,     "O"},
        {Raylib::Inputs::P,     "P"},
        {Raylib::Inputs::Q,     "Q"},
        {Raylib::Inputs::R,     "R"},
        {Raylib::Inputs::S,     "S"},
        {Raylib::Inputs::T,     "T"},
        {Raylib::Inputs::U,     "U"},
        {Raylib::Inputs::V,     "V"},
        {Raylib::Inputs::W,     "W"},
        {Raylib::Inputs::X,     "X"},
        {Raylib::Inputs::Y,     "Y"},
        {Raylib::Inputs::Z,     "Z"},
        {Raylib::Inputs::SPACE, "SP"},
        {Raylib::Inputs::UP,    "AU"},
        {Raylib::Inputs::DOWN,  "AD"},
        {Raylib::Inputs::LEFT,  "AL"},
        {Raylib::Inputs::RIGHT, "AR"}
    };
    /**
     * @brief Scene for options
     * @class SceneOption
     * 
     */
    class SceneOption : public UiScene
    {
        public:
            /**
             * @brief Construct a new Scene Option object
             * 
             * @param settings 
             */
            SceneOption(Setting &settings);
            /**
             * @brief Destroy the Scene Option object
             * 
             */
            ~SceneOption();
            /**
             * @brief 
             * 
             * @param lib 
             */
            void eventScene(Raylib &lib) final;
            /**
             * @brief end of the scene
             * 
             * @param lib 
             * @return Scenes 
             */
            Scenes endScene(Raylib &lib) noexcept final;
            /**
             * @brief change music
             * 
             * @param name 
             */
            void changeAudio(const std::string &name);

        private:
            /**
             * @brief different buttons
             * 
             */
            std::vector<std::shared_ptr<button::Button>> _buttons;
    };

}

#endif /* !SCENEOPTION_HPP_ */
