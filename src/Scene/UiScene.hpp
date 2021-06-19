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

/**
 * @brief UI class
 * @class UiScene
 * 
 */
class UiScene : public AScene
{
    public:
        /**
         * @brief Construct a new Ui Scene object
         * 
         * @param settings 
         */
        UiScene(Setting &settings);
        /**
         * @brief Destroy the Ui Scene object
         * 
         */
        ~UiScene();
        /**
         * @brief run scene
         * 
         * @param lib 
         * @return Scenes 
         */
        Scenes run(Raylib &lib) final;
        /**
         * @brief manage event in scene
         * 
         * @param lib 
         */
        virtual void eventScene(Raylib &lib) = 0;
        /**
         * @brief end of the scene
         * 
         * @param lib 
         * @return Scenes 
         */
        virtual Scenes endScene(Raylib &lib) noexcept = 0;

    protected:
        /**
         * @brief mouse position
         * 
         */
        std::pair<float, float> _mousePos;
        /**
         * @brief state
         * 
         */
        int _state;
        /**
         * @brief button is pressed
         * 
         */
        bool _pressed;
};

#endif /* !UISCENE_HPP_ */
