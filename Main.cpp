/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Indie
*/

#include "Raylib/Raylib.hpp"
#include "Scene/SceneMenu.hpp"
#include "Scene/SceneMaxime.hpp"

int main(void)
{
    menu::SceneMenu menu;
    SceneMaxime test3d;

    Raylib Lib;

    Lib.createWindow(1920, 1080, "LETS GO", 60);
    //menu.run(Lib);
    test3d.run(Lib);
    return 0;
}