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

namespace option {

    static const std::string _returnText = "Return";

    static const struct coords _menuPos = coords(200.0f, 900.0f, 0.0f);

    static const std::string _bgPath = "asset/background_asset/Background_02.png";

    static const std::array<std::string, 6> _configAudio {
        "Music: 0%",
        "Music: 50%",
        "Music: 100%",
        "Sound: 0%",
        "Sound: 50%",
        "Sound: 100%"
    };

    static const std::array<coords, 6> _posAudio {
        coords(200, 300),
        coords(500, 300),
        coords(800, 300),
        coords(200, 500),
        coords(500, 500),
        coords(800, 500)
    };

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

    class SceneOption : public UiScene
    {
        public:
            SceneOption(Setting &settings);
            ~SceneOption();
            void eventScene(Raylib &lib) final;
            Scenes endScene(Raylib &lib) noexcept final;
            void changeAudio(const std::string &name);

        private:
            std::vector<std::shared_ptr<button::Button>> _buttons;
    };

}

#endif /* !SCENEOPTION_HPP_ */
