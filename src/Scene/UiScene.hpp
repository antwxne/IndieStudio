/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** UiScene
*/

#ifndef UISCENE_HPP_
#define UISCENE_HPP_

#include "AScene.hpp"
#include "UiObject/Button/Button.hpp"
#include "Object/Collisionable/Destructible/Movable/Animator/Animator.hpp"
class UiScene : public AScene
{
    public:
        UiScene(Setting &settings);
        ~UiScene();
        Scenes run(Raylib &lib) final;
        virtual void eventScene(Raylib &lib) = 0;
        virtual Scenes endScene(Raylib &lib) noexcept = 0;

    protected:
        std::pair<float, float> _mousePos;
        int _state;
        bool _pressed;
};

#endif /* !UISCENE_HPP_ */
