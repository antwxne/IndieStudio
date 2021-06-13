/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Raylib
*/

#include <algorithm>

#include "Raylib.hpp"
#include "RaylibError.hpp"

Raylib::Raylib() : _camera(
    {{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0})
{
}

Raylib::~Raylib()
{
    if (IsAudioDeviceReady())
        CloseAudioDevice();
    if (IsWindowReady())
        CloseWindow();
}

void Raylib::setCamera(Vector3 &pos, Vector3 &target, Vector3 &up, float &fovy,
    int &projection
) noexcept
{
    _camera.position = pos;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
};

Camera Raylib::getCamera() const noexcept
{
    return _camera;
};

void Raylib::createWindow(int &screenWidth, int &screenHeight,
    std::string const &title, std::size_t const &fps
) noexcept
{
    _screenSize.first = screenWidth;
    _screenSize.second = screenHeight;
    InitWindow(screenWidth, screenHeight, title.c_str());
    InitAudioDevice();
    SetTargetFPS(fps);
}

bool Raylib::gameLoop() const noexcept
{
    return !WindowShouldClose();
}

bool Raylib::isKeyPressed(int &button) const noexcept
{
    return (IsKeyPressed(button));
}

void Raylib::printObjects(Raylib::vectorObject &objects) const noexcept
{
    // BeginDrawing();
    // ClearBackground(RAYWHITE);
    // BeginMode3D(_camera);
    // for (auto const &i : objects)
    //     if (i->getTypeField().is_3D) {
    //         i->funcDraw();
    //     }
    // EndMode3D();
    // for (auto const &i : objects)
    //     if (!i->getTypeField().is_3D)
    //         i->funcDraw();
    // EndDrawing();
}

bool Raylib::isKeyReleased(int &button) const noexcept
{
    return (IsKeyReleased(button));
}

void Raylib::printGrid(int const &slices, float const &space) const noexcept
{
    DrawGrid(slices, space);
}

void Raylib::printFps(std::pair<int, int> const &pos) const noexcept
{
    DrawFPS(pos.first, pos.second);
}

bool Raylib::isControllerDetected(int const &idx) const noexcept
{
    return IsGamepadAvailable(idx);
}

std::string Raylib::getControllerName(int const &idx) const noexcept
{
    return GetGamepadName(idx);
}

bool Raylib::isControllerValid(int const &idx,
    std::string const &ControllerName
) const noexcept
{
    if (ControllerName.compare("xbox"))
        return (IsGamepadName(idx, XBOX360_NAME_ID) ||
            IsGamepadName(idx, XBOX360_LEGACY_NAME_ID));
    if (ControllerName.compare("ps3"))
        return IsGamepadName(idx, PS3_NAME_ID);
    return false;
}

std::string Raylib::textForSubText(const std::string &text, int &pos,
    int &frameCounter
) const noexcept
{
    return TextSubtext(text.c_str(), pos, frameCounter);
}

int Raylib::getKeyPressed() const noexcept
{
    int input = GetKeyPressed();
    auto iterator = std::find(_keys.begin(), _keys.end(), input);
    if (iterator == _keys.end())
        return (0);
    return std::distance(_keys.begin(), iterator);
}