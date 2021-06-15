/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#include "Core.hpp"
#include "SceneOption.hpp"

<<<<<<< HEAD
SceneOption::SceneOption(Setting &settings) : AScene(settings), _quit(false)
=======
SceneOption::SceneOption(Setting & settings) : AScene(settings), _quit(false)
>>>>>>> 45b6de4b5229598a7bd0f302740cc8b3f941e278
{
    setInputFunction(Raylib::ENTER, [&]() {
        _quit = !_quit;
    });
}

SceneOption::~SceneOption()
{
}

Scenes SceneOption::run(Raylib &lib, Scenes const &prevScene)
{
    while (!_quit && lib.gameLoop()) {
        triggerInputActions(lib);
        lib.printObjects(_objects);
    }
    if (lib.gameLoop())
        return (Scenes::QUIT);
    return (prevScene);
}