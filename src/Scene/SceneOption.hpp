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

    class SceneOption : public UiScene
    {
        public:
            SceneOption(Setting &settings);
            ~SceneOption();
            void eventScene(Raylib &lib) final;
            Scenes endScene(Scenes const &prevScene) noexcept final;

        private:
            std::pair<float, float> _mousePos;
            bool _quit;
            bool _clicked;
    };

}

#endif /* !SCENEOPTION_HPP_ */
