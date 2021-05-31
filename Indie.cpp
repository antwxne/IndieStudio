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
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    const Vector3 playerSize = {1.0f, 2.0f, 1.0f};
    const Vector3 enemyBoxPos = {-4.0f, 1.0f, 0.0f};
    const Vector3 enemyBoxSize = {2.0f, 2.0f, 2.0f};

    Vector3 enemySpherePos = {4.0f, 0.0f, 0.0f};
    float enemySphereSize = 1.5f;

    Vector3 playerPosition = {0.0f, 1.0f, 2.0f};
    Color playerColor = GREEN;

    Lib->CreateWindow(screenWidth, screenHeight, "LETS GO", Fps);
    Lib->Set3d(true);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Lib->DrawingLoopBegun();

        Lib->PrintText("ET C'EST PARTIS", {190, 200}, 20, LIGHTGRAY);

        Lib->PrintCube("Basic", enemyBoxPos, enemyBoxSize, GRAY);
        Lib->PrintCube("Wires", enemyBoxPos, enemyBoxSize, DARKGRAY);

        Lib->PrintSphere("Basic", enemySpherePos, enemySphereSize, {0,0}, GRAY);
        Lib->PrintSphere("Wires", enemySpherePos, enemySphereSize, {16, 16}, DARKGRAY);

        // Draw player
        DrawCubeV(playerPosition, playerSize, playerColor);
        Lib->PrintGrid(10, 1);
        Lib->PrintFps({10, 10});
        // if (Lib->IsControllerDetected(0))
        // {
            // std::cout << "Controller is Detected" << '\n';
            // std::cout << Lib->GetControllerName(0) << '\n';
            // if (Lib->IsControllerValid(0, "xbox"))
                // std::cout << "CECI EST UNE MANETTE DE XBOX" << '\n';
        // }

        Lib->DrawingLoopEnd();
    }
    Lib->DestroyWindow();
    ///////////////////////////////////////////
    return 0;
}