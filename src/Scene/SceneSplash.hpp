/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneSplash
*/

#ifndef SCENESPLASH_HPP_
#define SCENESPLASH_HPP_

#include "UiScene.hpp"

/**
 * @brief scene splash
 * @class SceneSplash
 * 
 */
class SceneSplash : public UiScene
{
    public:
        /**
         * @brief Construct a new Scene Splash object
         * 
         * @param settings 
         */
        SceneSplash(Setting &settings);
        /**
         * @brief Destroy the Scene Splash object
         * 
         */
        ~SceneSplash();
        /**
         * @brief manage event in scene
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

    private:
        /**
         * @brief n frame
         * 
         */
        std::size_t _frame;
        /**
         * @brief position X logo
         * 
         */
        int _logoPositionX;
        /**
         * @brief position Y logo
         * 
         */
        int _logoPositionY;
        /**
         * @brief count frames
         * 
         */
        int _framesCounter;
        /**
         * @brief count letters
         * 
         */
        int _lettersCount;
        /**
         * @brief size rect width
         * 
         */
        int _topSideRecWidth;
        /**
         * @brief size rect height
         * 
         */
        int _leftSideRecHeight;
        /**
         * @brief bottom width
         * 
         */
        int _bottomSideRecWidth;
        /**
         * @brief right height
         * 
         */
        int _rightSideRecHeight;
        /**
         * @brief number scene
         * 
         */
        int _scene;
        /**
         * @brief alpha of color
         * 
         */
        float _alpha;
};

#endif /* !SCENESPLASH_HPP_ */
