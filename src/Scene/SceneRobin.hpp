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

class SceneRobin : public AScene {
    public:
<<<<<<< HEAD
        SceneRobin(Setting &settings);
=======
        SceneRobin(Setting & settings);
>>>>>>> 45b6de4b5229598a7bd0f302740cc8b3f941e278
        ~SceneRobin();

        Scenes run(Raylib &lib, Scenes const &prevScene) override;
};

#endif /* !SCENEROBIN_HPP_ */
