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
        SceneBoard(Setting & settings);
        ~SceneBoard();
        Scenes run(Raylib &lib, Scenes const &prevScene) final;
};

#endif /* !SCENEBOARD_HPP_ */
