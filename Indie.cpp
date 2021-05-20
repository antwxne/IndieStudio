/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Indie
*/

#include "RaylibEncapsulation/RaylibEncapsulation.hpp"

int main(void)
{
    /////////////////////TEST GRAPHIQUE////////////
    auto Lib = std::make_unique<RaylibEncapsulation>();
    const std::size_t Fps = 60;
    const int screenWidth = 800;
    const int screenHeight = 450;

    Lib->CreateWindow(screenWidth, screenHeight, "LETS GO", Fps);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Lib->DrawingLoopBegun();
        Lib->PrintText("ET C'EST PARTIS", {190, 200}, 20, LIGHTGRAY);
        Lib->DrawingLoopEnd();
    }
    Lib->DestroyWindow();
    ///////////////////////////////////////////
    return 0;
}