/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Indie
*/

#include "Raylib/Raylib.hpp"
#include "Scene/SceneMenu.hpp"

int main(void)
{
    menu::SceneMenu menu;
    /////////////////////TEST GRAPHIQUE////////////
    Raylib Lib;
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

    Lib.createWindow(screenWidth, screenHeight, "LETS GO", Fps);
    menu.StartLoop(Lib);

    // Main game loop
    while (Lib.gameLoop()) // Detect window close button or ESC key
    {
        BeginDrawing();
        Lib.drawingLoopBegun();

        Lib.printText("ET C'EST PARTIS", {190, 200}, 20, LIGHTGRAY);

        Lib.printCube(Raylib::BASIC, enemyBoxPos, enemyBoxSize, GRAY);
        Lib.printCube(Raylib::WIRES, enemyBoxPos, enemyBoxSize, DARKGRAY);

        Lib.printSphere(Raylib::BASIC, enemySpherePos, enemySphereSize, {0,0}, GRAY);
        Lib.printSphere(Raylib::WIRES, enemySpherePos, enemySphereSize, {16, 16}, DARKGRAY);

        // Draw player
        DrawCubeV(playerPosition, playerSize, playerColor);
        Lib.printGrid(10, 1);
        Lib.printFps({10, 10});
        // if (Lib.IsControllerDetected(0))
        // {
            // std::cout << "Controller is Detected" << '\n';
            // std::cout << Lib.GetControllerName(0) << '\n';
            // if (Lib.IsControllerValid(0, "xbox"))
                // std::cout << "CECI EST UNE MANETTE DE XBOX" << '\n';
        // }

        Lib.drawingLoopEnd();
        EndDrawing();
    }
    //Lib->destroyWindow();
    ///////////////////////////////////////////
    return 0;
}