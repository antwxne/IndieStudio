/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Raylib
*/

#include <algorithm>

#include "Raylib.hpp"
#include "RaylibError.hpp"

Raylib::Raylib() :
    _camera({{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0})
{
}

Raylib::~Raylib()
{
    if (IsAudioDeviceReady())
        CloseAudioDevice();
    if (IsWindowReady())
        CloseWindow();
}

void Raylib::setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection)
{
    _camera.position = pos;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
};

Camera Raylib::getCamera() const
{
    return _camera;
};

void Raylib::createWindow(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
{
    _screenSize.first = screenWidth;
    _screenSize.second = screenHeight;
    InitWindow(screenWidth, screenHeight, title.c_str());
    InitAudioDevice();
    SetTargetFPS(fps);
}

bool Raylib::gameLoop()
{
    return !WindowShouldClose();
}

bool Raylib::isKeyPressed(int button) const noexcept
{
    return (IsKeyPressed(button));
}

void Raylib::printObjects(Raylib::vectorObject objects)
{
    BeginDrawing();
    BeginMode3D(_camera);
    for (auto &i : objects)
        if (i->is3D())
            i->funcDraw();
    EndMode3D();
    for (auto &i : objects)
        if (!i->is3D())
            i->funcDraw();
    EndDrawing();
}

bool Raylib::isKeyReleased(int button) const noexcept
{
    return (IsKeyReleased(button));
}

void Raylib::printCircle(std::pair<int, int> const position, float const radius, std::pair<Color, Color> const color) const
{
        // DrawCircle(position.first, position.second, radius, color.first);
        // DrawCircleGradient(position.first, position.second, radius, color.first, color.second);
        // DrawCircleLines(position.first, position.second, radius, color.first);
        // std::cout << "[-] Unknow Circle Type, valid are Basic, Gradient, Lines" << '\n';
}

void Raylib::printCube(Vector3 const position, Vector3 const size, Color const color) const
{
        // DrawCube(position, size.x, size.y, size.z, color);
        // DrawCubeWires(position, size.x, size.y, size.z, color);
        // std::cout << "[-] Unknow Cube Type, valid are Basic, Wires" << '\n';
}

void Raylib::printSphere(Vector3 const position, float const size, std::pair<int, int> const Vertex, Color const color) const
{
        // DrawSphere(position, size, color);
        // DrawSphereWires(position, size, Vertex.first, Vertex.second, color);
        // std::cout << "[-] Unknow Shpere Type, valid are Basic, Wires" << '\n';
}

void Raylib::printGrid(int const slices, float const space) const
{
    DrawGrid(slices, space);
}

void Raylib::printFps(std::pair<int, int> const pos) const
{
    DrawFPS(pos.first, pos.second);
}

bool Raylib::isControllerDetected(int const idx) const
{
    return IsGamepadAvailable(idx);
}

std::string Raylib::getControllerName(int const idx) const
{
    return GetGamepadName(idx);
}

bool Raylib::isControllerValid(int const idx, std::string const &ControllerName) const
{
    if (ControllerName.compare("xbox"))
        return (IsGamepadName(idx, XBOX360_NAME_ID) || IsGamepadName(idx, XBOX360_LEGACY_NAME_ID));
    if (ControllerName.compare("ps3"))
        return IsGamepadName(idx, PS3_NAME_ID);
    return false;
}

int Raylib::getKeyPressed() const
{
    int input = GetKeyPressed();
    auto iterator = std::find(_keys.begin(), _keys.end(), input);
    if (iterator == _keys.end())
        return (0);
    return std::distance(_keys.begin(), iterator);
}