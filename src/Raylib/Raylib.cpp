/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Raylib
*/

#include <algorithm>
#include <iostream>
#include "Raylib.hpp"
#include "RaylibError.hpp"
#include "Object/Collisionable/CollisionableObject.hpp"
#include "Object/UiObject/UiGame/BorderPlayer.hpp"
#include "Object/Ground/Ground.hpp"
#include "UiObject/UiObject.hpp"
#include "Button.hpp"

Raylib::Raylib() : _camera(
    {{0.0f, 20.0f, 15.0f}, { 0.0f, 0.0f, 2.0f}, {0.0f, 1.0f, 0.0f}, 40.0f, 0})
{
}

Raylib::~Raylib()
{
    if (IsAudioDeviceReady())
        CloseAudioDevice();
    if (IsWindowReady())
        CloseWindow();
    freeResources();
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

bool Raylib::isMousePressed() const noexcept
{
    return (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

bool Raylib::isMouseDown() const noexcept
{
    return (IsMouseButtonDown(MOUSE_BUTTON_LEFT));
}

bool Raylib::isMouseReleased() const noexcept
{
    return (IsMouseButtonReleased(MOUSE_BUTTON_LEFT));
}

const std::pair<float, float> Raylib::getMousePosition() const noexcept
{
    Vector2 vecPos = GetMousePosition();

    return (std::make_pair(vecPos.x, vecPos.y));
}


void Raylib::drawRectangleLinesEx(const float &posX, const float &posY, const float &width,
    const float &height, RGB color, int const &lineThick) noexcept
{
    Rectangle rec = {posX, posY, width, height};
    DrawRectangleLinesEx(rec, lineThick, {color.r, color.g, color.b, color.a});
}

void Raylib::printObjects(Raylib::vectorObject &objects) noexcept
{
    BeginDrawing();
    ClearBackground(BLACK);
    for (auto &i : objects) {
        if (i->getTypeField().is3D) {
            BeginMode3D(_camera);
            if (i->getTypeField().isCollisionable) {
            auto const &derived = std::dynamic_pointer_cast<CollisionableObject>(i);
            drawModel(derived->getModel(), derived->getTexture(), i->getPosition(), i->getScale(), i->getColors().first);
            }
            else if (i->getTypeField().isGround) {
                auto const &derived = std::dynamic_pointer_cast<Ground>(i);
                drawMesh(derived->getModel(), derived->getTexture(), i->getPosition(), i->getScale(), i->getColors().first, i->getSize());
            }
            EndMode3D();
        }
        if (!i->getTypeField().is3D) {
            auto const &derived = std::dynamic_pointer_cast<UiObject>(i);
            drawTexture(derived->getTexture(), {i->getPosition().first, i->getPosition().second}, i->getRotation(), i->getScale(), i->getColors().first);
            if (i->getTypeField().isButton) {
                auto const &derivedButton = std::dynamic_pointer_cast<button::Button>(i);
                drawText(derivedButton->getText(), derivedButton->getTextPos(), derivedButton->getTextSize(), i->getColors().second);
            }
            if (i->getTypeField().isContourRect) {
                std::cout << i->getPosition().first << std::endl;
                drawRectangleLinesEx(i->getPosition().first, i->getPosition().second, i->getSize().first, i->getSize().second, i->getColors().first, i->getScale());
           }
            if (i->getTypeField().isFullSquare) {
                std::cout << i->getPosition().first << std::endl;
                drawRectangle(i->getPosition().first, i->getPosition().second, i->getSize().first, i->getSize().second, i->getColors().first);
            }
        }
    }
    EndDrawing();
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

bool Raylib::isControllerValid(int const &idx, std::string const &ControllerName
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

void Raylib::displayMusic(const std::string &path, float volume)
{
    auto it = _music.find(path);

    if (it == _music.end()) {
        _music.insert({path, LoadMusicStream(path.c_str())});
        it = _music.find(path);
        it->second.looping = true;
    }
    SetMusicVolume(it->second, volume);
    PlayMusicStream(it->second);
}

void Raylib::displaySound(const std::string &path, float volume)
{
    auto it = _sound.find(path);

    if (it == _sound.end()) {
        _sound.insert({path, LoadSound(path.c_str())});
        it = _sound.find(path);
    }
    SetSoundVolume(it->second, volume);
    PlaySoundMulti(it->second);
}

void Raylib::updateMusic(const std::string &path)
{
    auto it = _music.find(path);

    if (it == _music.end())
        return;
    UpdateMusicStream(it->second);
}

void Raylib::drawMesh(const std::string &modelPath, const std::string &texturePath, coords pos, float scale, RGB tint, const std::pair<int, int> &size)
{
    auto it = _models.find(modelPath);
    auto at = _textures.find(texturePath);

    if (at == _textures.end()) {
        _textures.insert({texturePath, LoadTexture(texturePath.c_str())});
        at = _textures.find(texturePath);
    }
    if (it == _models.end()) {
        _models.insert({modelPath, LoadModelFromMesh(GenMeshPlane(size.first, size.second, 5, 5))});
        it = _models.find(modelPath);
        SetMaterialTexture(&it->second.materials[0], MAP_DIFFUSE, at->second);
    }
    DrawModel(it->second, {pos.first, pos.second, pos.third}, scale, {tint.r, tint.g, tint.b, tint.a});
}

void Raylib::drawModel(const std::string &modelPath, const std::string &texturePath, coords pos, float scale, RGB tint)
{
    auto it = _models.find(modelPath);
    auto at = _textures.find(texturePath);

    if (at == _textures.end()) {
        _textures.insert({texturePath, LoadTexture(texturePath.c_str())});
        at = _textures.find(texturePath);
    }
    if (it == _models.end()) {
        _models.insert({modelPath, LoadModel(modelPath.c_str())});
        it = _models.find(modelPath);
        SetMaterialTexture(&it->second.materials[0], MAP_DIFFUSE, at->second);
    }
    DrawModel(it->second, {pos.first, pos.second, pos.third}, scale,
        {tint.r, tint.g, tint.b, tint.a});
}

void Raylib::drawTexture(const std::string &path, Vector2 pos, float rotation, float scale, RGB tint)
{
    auto it = _textures.find(path);

    if (it == _textures.end()) {
        _textures.insert({path, LoadTexture(path.c_str())});
        it = _textures.find(path);
    }
    DrawTextureEx(it->second, pos, rotation, scale, {tint.r, tint.g, tint.b, tint.a});
}

void Raylib::drawText(const std::string &text, coords pos, float scale,
    RGB tint
)
{
    DrawText(text.c_str(), pos.first, pos.second, scale,
        {tint.r, tint.g, tint.b, tint.a});
}

void Raylib::freeResources()
{
    for (auto &model : _models)
        UnloadModel(model.second);
    _models.clear();
    for (auto &texture : _textures)
        UnloadTexture(texture.second);
    _textures.clear();
}

float Raylib::getDeltaTime() noexcept
{
    return GetFrameTime();
}

void Raylib::drawRectangleLines(const int &posX, const int &posY,
    const int &width, const int &height, RGB color
) const noexcept
{
    DrawRectangleLines(posX, posY, width, height, {color.r, color.g, color.b, color.a});
}

void Raylib::drawRectangle(const int &posX, const int &posY, const int &width,
    const int &height, RGB color
) const noexcept
{
    DrawRectangle(posX, posY, width, height, {color.r, color.g, color.b, color.a});
}
