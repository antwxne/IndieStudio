/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Raylib/Raylib.hpp"

/**
 * @brief all scenes
 * @enum Scenes
 * 
 */
enum Scenes {
    QUIT = -1,
    MENU,
    NEW_GAME,
    GAME,
    LOAD,
    OPTION,
    SAVE,
    INTRODUCTION,
    SPLASHSCREEN,
    ENDGAME
};

/**
 * @brief Interface for Scenes
 * @class IScene
 * 
 */
class IScene {
    public:
        /**
         * @brief Destroy the IScene object
         * 
         */
        virtual ~IScene() {};
        /**
         * @brief run the scene
         * 
         * @param lib 
         * @return Scenes 
         */
        virtual Scenes run(Raylib &lib) = 0;
};

#endif /* !ISCENE_HPP_ */