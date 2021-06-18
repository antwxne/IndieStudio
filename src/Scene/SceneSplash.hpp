/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneSplash
*/

#ifndef SCENESPLASH_HPP_
#define SCENESPLASH_HPP_

#include "UiScene.hpp"

class SceneSplash : public UiScene
{
    public:
        SceneSplash(Setting &settings);
        ~SceneSplash();
        void eventScene(Raylib &lib) final;
        Scenes endScene(Raylib &lib) noexcept final;

    private:
        std::size_t _frame;
        int _logoPositionX;
        int _logoPositionY;
        int _framesCounter;
        int _lettersCount;
        int _topSideRecWidth;
        int _leftSideRecHeight;
        int _bottomSideRecWidth;
        int _rightSideRecHeight;
        int _scene;
        float _alpha;
};

#endif /* !SCENESPLASH_HPP_ */
