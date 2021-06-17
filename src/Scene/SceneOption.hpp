/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#ifndef SCENEOPTION_HPP_
#define SCENEOPTION_HPP_

#include "Raylib.hpp"
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

    class SceneOption : public UiScene
    {
        public:
            SceneOption(Setting &settings);
            ~SceneOption();
            void eventScene(Raylib &lib) final;
            Scenes endScene(Raylib &lib) noexcept final;
            void changeAudio(const std::string &name);
    };

}

#endif /* !SCENEOPTION_HPP_ */
