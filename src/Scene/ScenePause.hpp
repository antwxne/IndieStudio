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
    /**
     * @brief text in button
     * 
     */
    static const std::vector<std::string> _pauseText {
        "Resume",
        "Save",
        "Option",
        "Main menu",
        "Quit"
    };
    /**
     * @brief scene in button
     * 
     */
    static const std::array<Scenes, 5> _returnScene {
        Scenes::GAME,
        Scenes::SAVE,
        Scenes::OPTION,
        Scenes::MENU,
        Scenes::QUIT
    };
    /**
     * @brief position for button
     * 
     */
    static const std::vector<struct coords> _pausePos {
        {coords(780.0f, 100.0f, 0.0f)},
        {coords(780.0f, 300.0f, 0.0f)},
        {coords(780.0f, 500.0f, 0.0f)},
        {coords(780.0f, 700.0f, 0.0f)},
        {coords(780.0f, 900.0f, 0.0f)}
    };
    /**
     * @brief size of button
     * 
     */
    static const std::vector<std::pair<float, float>> _pauseSize {
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)},
        {std::make_pair(200.0f, 50.0f)}
    };
    /**
     * @brief background filepath
     * 
     */
    static const std::string _bgPath = "asset/background_asset/Background_03.png";
    /**
     * @brief scene pause
     * @class ScenePause
     * 
     */
    class ScenePause : public UiScene
    {
        public:
            /**
             * @brief Construct a new Scene Pause object
             * 
             * @param settings 
             */
            ScenePause(Setting &settings);
            /**
             * @brief Destroy the Scene Pause object
             * 
             */
            ~ScenePause();
            /**
             * @brief 
             * 
             * @param lib 
             */
            void eventScene(Raylib &lib) final;
            /**
             * @brief 
             * 
             * @param lib 
             * @return Scenes 
             */
            Scenes endScene(Raylib &lib) noexcept final;
            /**
             * @brief change audio
             * 
             * @param name 
             */
            void changeAudio(const std::string &name);
        
        private:
            bool _option;
    };

}
#endif /* !SCENEPAUSE_HPP_ */
