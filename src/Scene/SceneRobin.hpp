/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneRobin
*/

#ifndef SCENEROBIN_HPP_
#define SCENEROBIN_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

/**
 * @brief scene Robin
 * @class SceneRobin
 * 
 */
class SceneRobin : public AScene {
    public:
        /**
         * @brief Construct a new Scene Robin object
         * 
         * @param settings 
         */
        SceneRobin(Setting &settings);
        /**
         * @brief Destroy the Scene Robin object
         * 
         */
        ~SceneRobin();
        /**
         * @brief run scene
         * 
         * @param lib 
         * @return Scenes 
         */
        Scenes run(Raylib &lib) override;
};

#endif /* !SCENEROBIN_HPP_ */
