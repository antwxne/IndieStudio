/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** ScenePause
*/

#ifndef SCENEPAUSE_HPP_
#define SCENEPAUSE_HPP_

#include "UiScene.hpp"

namespace pause {

    static const std::vector<std::string> _pauseText {
        "Resume",
        "Save",
        "Option",
        "Main menu",
        "Quit"
    };

    static const std::array<Scenes, 5> _returnScene {
        Scenes::GAME,
        Scenes::SAVE,
        Scenes::OPTION,
        Scenes::MENU,
        Scenes::QUIT
    };

    static const std::vector<struct coords> _pausePos {
        {coords(780.0f, 100.0f, 0.0f)},
        {coords(780.0f, 300.0f, 0.0f)},
        {coords(780.0f, 500.0f, 0.0f)},
        {coords(780.0f, 700.0f, 0.0f)},
        {coords(780.0f, 900.0f, 0.0f)}
    };

    static const std::vector<std::pair<float, float>> _pauseSize {
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)}
    };

    static const std::string _bgPath = "asset/background_asset/Background_03.png";

    class ScenePause : public UiScene
    {
        public:
            ScenePause(Setting &settings);
            ~ScenePause();
            void eventScene(Raylib &lib) final;
            Scenes endScene(Raylib &lib) noexcept final;
            void changeAudio(const std::string &name);
        
        private:
            bool _option;
    };

}
#endif /* !SCENEPAUSE_HPP_ */
