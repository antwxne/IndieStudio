/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneBoard
*/

#ifndef SCENEBOARD_HPP_
#define SCENEBOARD_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

/**
 * @brief Board Scene
 * @class SceneBoard
 * 
 */
class SceneBoard : public AScene
{
    public:
        /**
         * @brief Construct a new Scene Board object
         * 
         * @param settings 
         */
        SceneBoard(Setting &settings);
        /**
         * @brief Destroy the Scene Board object
         * 
         */
        ~SceneBoard();
        /**
         * @brief run scene
         * 
         * @param lib 
         * @return Scenes 
         */
        Scenes run(Raylib &lib) final;
};

#endif /* !SCENEBOARD_HPP_ */
