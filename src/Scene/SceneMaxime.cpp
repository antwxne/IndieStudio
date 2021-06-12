/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#include "SceneMaxime.hpp"
#include "Core.hpp"

SceneMaxime::SceneMaxime()
{
    //init _objects
}
SceneMaxime::~SceneMaxime()
{

    _objects.clear();
}

int SceneMaxime::run(Raylib &lib)
{
    const Vector3 BoxPosition = {0.0f, 0.0f, 0.0f};

    Vector3 enemySpherePos = {4.0f, 0.0f, 0.0f};
    float enemySphereSize = 1.5f;

    // Vector3 playerPosition = {0.0f, 1.0f, 2.0f};
    // Color playerColor = GREEN;

    Model modelBox = LoadModel("asset/box_test/Box.obj");
    Texture2D textureBox = LoadTexture("asset/box_test/box-textures.png");    // Load model texture and set material
    SetMaterialTexture(&modelBox.materials[0], MAP_DIFFUSE, textureBox);    // Set model material map texture
    Vector3 playerPosition = {0.0f, 1.0f, 2.0f};
    Color playerColor = GREEN;

    while (lib.gameLoop()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(lib.getCamera());
        DrawModel(modelBox, BoxPosition, 0.05f, WHITE);
        //we will only use Raylib::printObjects(std::vector<unique_ptr<IObject>> objects) later

        //lib.printSphere(Raylib::BASIC, enemySpherePos, enemySphereSize, {0,0}, GRAY);
        //lib.printSphere(Raylib::WIRES, enemySpherePos, enemySphereSize, {16, 16}, DARKGRAY);
        // lib.printCube(Raylib::WIRES, enemyBoxPos, enemyBoxSize, DARKGRAY);
        // lib.printSphere(Raylib::BASIC, enemySpherePos, enemySphereSize, {0,0}, GRAY);
        // lib.printSphere(Raylib::WIRES, enemySpherePos, enemySphereSize, {16, 16}, DARKGRAY);

        // Draw player
        lib.printGrid(10, 1);
        lib.printFps({10, 10});

        //3D display here
        EndMode3D();
        //2D display here
        EndDrawing();
    }
    UnloadTexture(textureBox);
    UnloadModel(modelBox);
    return (Core::Scenes::QUIT);
}