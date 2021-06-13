/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#include "Core.hpp"
#include "SceneOption.hpp"

SceneOption::SceneOption(std::shared_ptr<Setting> settings) : AScene(settings)
{
}

SceneOption::~SceneOption()
{
}

void SceneOption::initAssets()
{

}

Scenes SceneOption::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.getKeyPressed() != KEY_ENTER) {

    }
    return (prevScene);
}