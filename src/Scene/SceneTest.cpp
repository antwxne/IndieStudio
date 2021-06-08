/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneTest
*/

#include "SceneTest.hpp"

SceneTest::SceneTest()
{
    //init _objects
}

SceneTest::~SceneTest()
{
    _objects.clear();
}

void SceneTest::run(Raylib &lib)
{
    while (lib.gameLoop()) {
        lib.drawingLoopBegin();
        lib.drawingLoopEnd();
    }
}