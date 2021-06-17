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
#include "Object/UiObject/UiGame/TexteUi.hpp"
#include "Object/UiObject/UiGame/BorderPlayer.hpp"
#include "Object/Ground/Ground.hpp"
#include "UiObject/UiObject.hpp"
#include "Object/Particles.hpp"
#include "Button.hpp"
#include "Tank.hpp"
#include "Cannon.hpp"

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
    SetExitKey(KEY_DELETE);
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
            if (i->getTypeField().isTank) {
                //i know it's uggly right? :c
                auto tankCollider = dynamic_cast<CollisionableObject &>(*i);
                auto tank = std::dynamic_pointer_cast<Tank>(i);
                auto &cannon = const_cast<Cannon &>(tank->getCannon());

                findCollision(tankCollider, objects);
                findCollision(cannon, objects);

                drawModel(tank->getModel(), tank->getTexture(), tank->getPosition(), tank->getScale(), tank->getColors().first, tank->getRotationAxis(), tank->getRotationAngle());
                drawModel(cannon.getModel(), cannon.getTexture(), cannon.getPosition(), cannon.getScale(), cannon.getColors().first, cannon.getRotationAxis() ,cannon.getRotationAngle());
            } else if (i->getTypeField().isCollisionable) {
            auto const &derived = std::dynamic_pointer_cast<CollisionableObject>(i);
            drawModel(derived->getModel(), derived->getTexture(), i->getPosition(), i->getScale(), i->getColors().first, i->getRotationAxis(), i->getRotationAngle());
            }
            else if (i->getTypeField().isGround) {
                auto const &derived = std::dynamic_pointer_cast<Ground>(i);
                drawMesh(derived->getModel(), derived->getTexture(), i->getPosition(), i->getScale(), i->getColors().first, i->getSize());
            }
            else if (i->getTypeField().isParticule) {
                auto const derived = std::dynamic_pointer_cast<Particles>(i);
                for (auto const &i: derived->getParticles()) {
                    drawSphere(i.position, i.color, (i.radius  * i.scale));
                }
            }
            EndMode3D();
        }
        if (!i->getTypeField().is3D && i->getTypeField().isTransparent == false) {
            auto const &derived = std::dynamic_pointer_cast<UiObject>(i);
            drawTexture(derived->getTexture(), {i->getPosition().first, i->getPosition().second}, i->getRotationAngle(), i->getScale(), i->getColors().first);
            if (i->getTypeField().isButton) {
                auto const &derivedButton = std::dynamic_pointer_cast<button::Button>(i);
                drawText(derivedButton->getText(), derivedButton->getTextPos(), derivedButton->getTextSize(), i->getColors().second);
            }
            if (i->getTypeField().isContourRect) {
                drawRectangleLinesEx(i->getPosition().first, i->getPosition().second, i->getSize().first, i->getSize().second, i->getColors().first, i->getScale());
           }
            if (i->getTypeField().isFullSquare) {
                drawRectangle(i->getPosition().first, i->getPosition().second, i->getSize().first, i->getSize().second, i->getColors().first);
            }
            if (i->getTypeField().isText) {
                auto const &text = std::dynamic_pointer_cast<TexteUI>(i);
                drawText(text->getText(), text->getTextPos(), text->getTextSize(), i->getColors().first);
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

bool Raylib::checkCollision(std::pair<float, float> pos, float width, float height, float posX, float posY)
{
    Rectangle rect = {posX, posY, width, height};
    Vector2 vec = {pos.first, pos.second};

    return (CheckCollisionPointRec(vec, rect));
}

char Raylib::getPressedCharacter() noexcept
{
    char key = GetCharPressed();

    if (IsKeyPressed(KEY_BACKSPACE))
        return (-1);
    return (key);
}

int Raylib::getKeyPressed() const noexcept
{
    int input = GetKeyPressed();
    auto iterator = std::find(_keys.begin(), _keys.end(), input);

    if (iterator == _keys.end())
        return (0);
    return std::distance(_keys.begin(), iterator);
}

std::vector<int> Raylib::getKeysDown() noexcept
{
    int input;
    std::vector<int> keysDown = {};
    std::unordered_map<int,std::function<void()>>::iterator itKey;

    while ((input = getKeyPressed()) != Raylib::NULL_KEY) {
        _inputSave.emplace_back(input);
    }
    for (auto it = _inputSave.begin(); it != _inputSave.end();) {
        if (IsKeyUp(_keys.at(*it))) {
            it = _inputSave.erase(it);
            continue;
        }
        keysDown.emplace_back(*it);
        it++;
    }
    return keysDown;
}

void Raylib::displayMusic(const std::string &path, float volume)
{
    auto it = _music.find(path);

    if (it == _music.end()) {
        _music.insert({path, {LoadMusicStream(path.c_str()), false}});
        it = _music.find(path);
        it->second.first.looping = true;
    }
    if (!it->second.second) {
        PlayMusicStream(it->second.first);
        it->second.second = true;
    }
    SetMusicVolume(it->second.first, volume);
    UpdateMusicStream(it->second.first);
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

void Raylib::drawSphere(const coords &pos, const RGB tint, const float radius)
{
    // std::cout << "[RAYLIB] pos x: " << pos.first <<"\n";
    // std::cout << "[RAYLIB] pos Y: " << pos.second <<"\n";
    // std::cout << "[RAYLIB] pos z: " << pos.third <<"\n";
    // std::cout << "[RAYLIB] radius: " << radius <<"\n";
    DrawSphere({pos.first, pos.second, pos.third}, radius, {tint.r, tint.g, tint.b, tint.a});
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

void Raylib::drawModel(const std::string &modelPath, const std::string &texturePath, coords pos, float scale, RGB tint, coords axis, float angle)
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
    DrawModelEx(it->second, {pos.first, pos.second, pos.third}, {axis.first, axis.second, axis.third}, angle, {scale, scale, scale}, {tint.r, tint.g, tint.b, tint.a});
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
void Raylib::findCollision(CollisionableObject &obj,
    const std::vector<std::shared_ptr<AObject>> &allObjs
) noexcept
{
    std::cout << "obj pos " << obj.getPosition().first << " " <<  obj.getPosition().second << " " << obj.getPosition().third << std::endl;
    auto plouf = _models.find(obj.getModel());
    if (plouf == _models.cend())
        return;
//    auto boundCurrent = GetMeshBoundingBox(plouf->second.meshes[0]);
    auto positionCurrent = obj.getPosition();
    auto sizeCurrent = obj.get3DSize();
    //std::cout << "Bound max == (" << boundCurrent.max.x << ", " << boundCurrent.max.y << ", " << boundCurrent.max.z << ")\n";

    BoundingBox boundCurrent = (BoundingBox) {(Vector3){positionCurrent.first - sizeCurrent.first / 2,
        positionCurrent.second - sizeCurrent.second / 2,
        positionCurrent.third - sizeCurrent.third / 2},
        (Vector3){positionCurrent.first + sizeCurrent.first / 2,
            positionCurrent.second + sizeCurrent.second / 2,
            positionCurrent.third + sizeCurrent.third / 2}};
    std::cout << "Bound max == (" << boundCurrent.max.x << ", " << boundCurrent.max.y << ", " << boundCurrent.max.z << ")\n";

    //    boundCurrent.max.x += positionCurrent.first;
//    boundCurrent.max.y += positionCurrent.second;
//    boundCurrent.max.z += positionCurrent.third;
//    boundCurrent.min.x = positionCurrent.first - boundCurrent.min.x;
//    boundCurrent.min.y = positionCurrent.second - boundCurrent.min.y;
//    boundCurrent.min.z = positionCurrent.third - boundCurrent.min.z;


    for (auto &it : allObjs) {
        if (it->getTypeField().isCollisionable) {
            auto tmp = dynamic_cast<const CollisionableObject &>(*it);
            auto positionOther = tmp.getPosition();
            auto boundOther = GetMeshBoundingBox(_models.find(tmp.getModel())->second.meshes[0]);
            boundOther.max.x += positionOther.first;
            boundOther.max.y += positionOther.second;
            boundOther.max.z += positionOther.third;
            boundOther.min.x = positionOther.first - boundOther.min.x;
            boundOther.min.y = positionOther.second - boundOther.min.y;
            boundOther.min.z = positionOther.third - boundOther.min.z;

            if (CheckCollisionBoxes(boundCurrent, boundOther)) {
                std::cout << "pos tank " << obj.getPosition().first << ", " << obj.getPosition().second<< ", " << obj.getPosition().third << ", "<< std::endl;

                obj.hit(tmp);
            }
        }
    }
}
