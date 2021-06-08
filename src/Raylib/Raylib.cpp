/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Raylib
*/

#include "Raylib.hpp"

Raylib::Raylib() : _is3D(false)
{
    _camera = {{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0};
}

Raylib::~Raylib() {}

void Raylib::SetCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection)
{
    _camera.position = pos;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
};

Camera Raylib::GetCamera(void)
{
    return _camera;
};

void Raylib::Set3d(bool is3d)
{
    _is3D = is3d;
};
bool Raylib::Get3d(void)
{
    return _is3D;
};

void Raylib::CreateWindow(int screenWidth, int screenHeight, std::string title, std::size_t fps)
{
    _screenSize.first = screenWidth;
    _screenSize.second = screenHeight;
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(fps);
}

void Raylib::DestroyWindow()
{
    CloseWindow();
}

void Raylib::DrawingLoopBegun()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (_is3D)
        BeginMode3D(_camera);
}

void Raylib::DrawingLoopEnd()
{
    EndDrawing();
    if (_is3D)
        EndMode3D();
}

void Raylib::PrintText(std::string text, std::pair<int, int> position, int fontSize, Color color)
{
    DrawText(text.c_str(), position.first, position.second, fontSize, color);
}

void Raylib::PrintCircle(type type, std::pair<int, int> position, float radius, std::pair<Color, Color> color)
{
    if (type == BASIC)
        DrawCircle(position.first, position.second, radius, color.first);
    else if (type == GRADIENT)
        DrawCircleGradient(position.first, position.second, radius, color.first, color.second);
    else if (type = LINES)
        DrawCircleLines(position.first, position.second, radius, color.first);
    else
        std::cout << "[-] Unknow Circle Type, valid are Basic, Gradient, Lines" << '\n';
}

void Raylib::PrintRectangle(type type, std::pair<int, int> position, std::pair<int, int> size, std::pair<Color, Color> color)
{
    if (type == BASIC)
        DrawRectangle(position.first, position.second, size.first, size.second, color.first);
    else if (type == GRADIENT)
        DrawRectangleGradientH(position.first, position.second, size.first, size.second, color.first, color.second);
    else if (type == LINES)
        DrawRectangleLines(position.first, position.second, size.first, size.second, color.first);
    else
        std::cout << "[-] Unknow Rectangle Type, valid are Basic, Gradient, Lines" << '\n';
}

void Raylib::PrintCube(type type, Vector3 position, Vector3 size, Color color)
{
    if (type == BASIC)
        DrawCube(position, size.x, size.y, size.z, color);
    else if (type == WIRES)
        DrawCubeWires(position, size.x, size.y, size.z, color);
    else
        std::cout << "[-] Unknow Cube Type, valid are Basic, Wires" << '\n';
}

void Raylib::PrintSphere(type type, Vector3 position, float size, std::pair<int, int> Vertex, Color color)
{
    if (type == BASIC)
        DrawSphere(position, size, color);
    else if (type == WIRES)
        DrawSphereWires(position, size, Vertex.first, Vertex.second, color);
    else
        std::cout << "[-] Unknow Shpere Type, valid are Basic, Wires" << '\n';
}

void Raylib::PrintGrid(int slices, float space)
{
    DrawGrid(slices, space);
}
void Raylib::PrintFps(std::pair<int, int> pos)
{
    DrawFPS(pos.first, pos.second);
}