/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneTest
*/

#ifndef SCENETEST_HPP_
#define SCENETEST_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

class SceneTest : AScene {
    public:
        SceneTest();
        ~SceneTest();

        void run(Raylib &lib) override;
    protected:
    private:
};

#endif /* !SCENETEST_HPP_ */
