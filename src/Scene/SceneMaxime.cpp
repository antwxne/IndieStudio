/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#include "SceneMaxime.hpp"

SceneMaxime::SceneMaxime()
{
    //init _objects
}

SceneMaxime::~SceneMaxime()
{
    _objects.clear();
}

void SceneMaxime::run(Raylib &lib)
{
    const Vector3 playerSize = {1.0f, 2.0f, 1.0f};
    const Vector3 enemyBoxPos = {-4.0f, 1.0f, 0.0f};
    const Vector3 enemyBoxSize = {2.0f, 2.0f, 2.0f};

    Vector3 enemySpherePos = {4.0f, 0.0f, 0.0f};
    float enemySphereSize = 1.5f;

    Vector3 playerPosition = {0.0f, 1.0f, 2.0f};
    Color playerColor = GREEN;



    while (lib.gameLoop()) {
        BeginDrawing();
        BeginMode3D(lib.getCamera());
        //we will only use Raylib::printObjects(std::vector<unique_ptr<IObject>> objects) later
        lib.printCube(Raylib::WIRES, enemyBoxPos, enemyBoxSize, DARKGRAY);

        lib.printSphere(Raylib::BASIC, enemySpherePos, enemySphereSize, {0,0}, GRAY);
        lib.printSphere(Raylib::WIRES, enemySpherePos, enemySphereSize, {16, 16}, DARKGRAY);

        // Draw player
        DrawCubeV(playerPosition, playerSize, playerColor);
        lib.printGrid(10, 1);
        lib.printFps({10, 10});

        //3D display here
        EndMode3D();
        //2D display here
        EndDrawing();
    }
}