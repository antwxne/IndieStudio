/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_

#include "AScene.hpp"

class SceneGame : public AScene {
    public:
        SceneGame(Setting &settings);
        ~SceneGame();

        Scenes run(Raylib &lib) final;
    protected:
    private:
};

#endif /* !SCENEGAME_HPP_ */
