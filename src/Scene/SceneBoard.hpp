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

class SceneBoard : public AScene
{
    public:
<<<<<<< HEAD
        SceneBoard(Setting &settings);
=======
        SceneBoard(Setting & settings);
>>>>>>> 45b6de4b5229598a7bd0f302740cc8b3f941e278
        ~SceneBoard();
        Scenes run(Raylib &lib, Scenes const &prevScene) final;
};

#endif /* !SCENEBOARD_HPP_ */
