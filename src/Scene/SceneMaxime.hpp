/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#ifndef SCENEMAXIME_HPP_
#define SCENEMAXIME_HPP_

#include "AScene.hpp"

class SceneMaxime : AScene {
    public:
        SceneMaxime();
        ~SceneMaxime();

        int run(Raylib &lib) override;
    protected:
    private:
};

#endif /* !SCENEMAXIME_HPP_ */
