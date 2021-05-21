/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaylibEncapsulation
*/

#include "RaylibEncapsulation.hpp"

RaylibEncapsulation::RaylibEncapsulation() : _is3D(false)
{
    _camera = {{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0};
}

RaylibEncapsulation::~RaylibEncapsulation() {}

void RaylibEncapsulation::SetCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection)
{
    _camera.position = pos;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
};

Camera RaylibEncapsulation::GetCamera(void)
{
    return _camera;
};

void RaylibEncapsulation::Set3d(bool is3d)
{
    _is3D = is3d;
};
bool RaylibEncapsulation::Get3d(void)
{
    return _is3D;
};

void RaylibEncapsulation::CreateWindow(int screenWidth, int screenHeight, std::string title, std::size_t fps)
{
    _screenSize.first = screenWidth;
    _screenSize.second = screenHeight;
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(fps);
}

void RaylibEncapsulation::DestroyWindow()
{
    CloseWindow();
}

void RaylibEncapsulation::DrawingLoopBegun()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (_is3D)
        BeginMode3D(_camera);
}

void RaylibEncapsulation::DrawingLoopEnd()
{
    EndDrawing();
    if (_is3D)
        EndMode3D();
}

void RaylibEncapsulation::PrintText(std::string text, std::pair<int, int> position, int fontSize, Color color)
{
    DrawText(text.c_str(), position.first, position.second, fontSize, color);
}

void RaylibEncapsulation::PrintCircle(std::string type, std::pair<int, int> position, float radius, std::pair<Color, Color> color)
{
    if (type.compare("Basic") == 0)
        DrawCircle(position.first, position.second, radius, color.first);
    else if (type.compare("Gradient") == 0)
        DrawCircleGradient(position.first, position.second, radius, color.first, color.second);
    else if (type.compare("Lines") == 0)
        DrawCircleLines(position.first, position.second, radius, color.first);
    else
        std::cout << "[-] Unknow Circle Type, valid are Basic, Gradient, Lines" << '\n';
}

void RaylibEncapsulation::PrintRectangle(std::string type, std::pair<int, int> position, std::pair<int, int> size, std::pair<Color, Color> color)
{
    if (type.compare("Basic") == 0)
        DrawRectangle(position.first, position.second, size.first, size.second, color.first);
    else if (type.compare("Gradient") == 0)
        DrawRectangleGradientH(position.first, position.second, size.first, size.second, color.first, color.second);
    else if (type.compare("Lines") == 0)
        DrawRectangleLines(position.first, position.second, size.first, size.second, color.first);
    else
        std::cout << "[-] Unknow Rectangle Type, valid are Basic, Gradient, Lines" << '\n';
}

void RaylibEncapsulation::PrintCube(std::string type, Vector3 position, Vector3 size, Color color)
{
    if (type.compare("Basic") == 0)
        DrawCube(position, size.x, size.y, size.z, color);
    else if (type.compare("Wires") == 0)
        DrawCubeWires(position, size.x, size.y, size.z, color);
    else
        std::cout << "[-] Unknow Cube Type, valid are Basic, Wires" << '\n';
}

void RaylibEncapsulation::PrintSphere(std::string type, Vector3 position, float size, std::pair<int, int> Vertex, Color color)
{
    if (type.compare("Basic") == 0)
        DrawSphere(position, size, color);
    else if (type.compare("Wires") == 0)
        DrawSphereWires(position, size, Vertex.first, Vertex.second, color);
    else
        std::cout << "[-] Unknow Shpere Type, valid are Basic, Wires" << '\n';
}

void RaylibEncapsulation::PrintGrid(int slices, float space)
{
    DrawGrid(slices, space);
}
void RaylibEncapsulation::PrintFps(std::pair<int, int> pos)
{
    DrawFPS(pos.first, pos.second);
}