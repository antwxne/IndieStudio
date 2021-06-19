/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Raylib
*/

#include <algorithm>
#include <iostream>
#include <cmath>

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
    SetExitKey(KEY_NULL);
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

void Raylib::draw3DObjects(Raylib::uAObject &it, Raylib::vectorObject &objects)
{
    if (it->getTypeField().isTank) {
        auto tankCollider = std::dynamic_pointer_cast<CollisionableObject>(it);
        auto tank = std::dynamic_pointer_cast<Tank>(it);
        if (tank->getLife() >= 0) {
            auto &cannon = const_cast<Cannon &>(tank->getCannon());
            auto &bullets = cannon.getBullets();
            findCollision(tankCollider, objects);
            for (auto &bullet : bullets) {
                if (bullet->getPosition().first != -120.f)
                    findCollision(bullet, objects);
                drawModel(bullet->getModel(), bullet->getTexture(),
                    bullet->getPosition(), bullet->getScale(),
                    bullet->getColors().first,
                    bullet->getRotationAxis(),
                    bullet->getRotationAngle());
            }
            drawModel(tank->getModel(), tank->getTexture(),
                tank->getPosition(), tank->getScale(),
                tank->getColors().first, tank->getRotationAxis(),
                tank->getRotationAngle());
            drawModel(cannon.getModel(), cannon.getTexture(),
                cannon.getPosition(), cannon.getScale(),
                cannon.getColors().first, cannon.getRotationAxis(),
                cannon.getRotationAngle());
        }
    } else if (it->getTypeField().isAnimator) {
        auto const &derived = std::dynamic_pointer_cast<Animator>(it);
        drawAnimation(derived->getModel(), derived->getTexture(), derived->getAnimPath(), derived->getPosition(), derived->getFrameActual(), derived->getScale());
    } else if (it->getTypeField().isCollisionable) {
        auto const &derived = std::dynamic_pointer_cast<CollisionableObject>(it);
        drawModel(derived->getModel(), derived->getTexture(), it->getPosition(), it->getScale(), it->getColors().first, it->getRotationAxis(), it->getRotationAngle());
    } else if (it->getTypeField().isGround) {
        auto const &derived = std::dynamic_pointer_cast<Ground>(it);
        drawMesh(derived->getModel(), derived->getTexture(), it->getPosition(), it->getScale(), it->getColors().first, it->getSize());
    } else if (it->getTypeField().isParticule) {
        auto const derived = std::dynamic_pointer_cast<Particles>(it)->getParticles();
        for (auto const &i: derived)
            drawSphere(i.position, i.color, (i.radius  * i.scale));
    }
}

void Raylib::draw2DObjects(Raylib::uAObject &it)
{
    if (!it->getTypeField().is3D && it->getTypeField().isTransparent == false) {
        drawTexture(std::dynamic_pointer_cast<UiObject>(it)->getTexture(), {it->getPosition().first, it->getPosition().second}, it->getRotationAngle(), it->getScale(), it->getColors().first);
        if (it->getTypeField().isButton) {
            auto const &derivedButton = std::dynamic_pointer_cast<button::Button>(it);
            drawText(derivedButton->getText(), derivedButton->getTextPos(), derivedButton->getTextSize(), it->getColors().second);
        }
        if (it->getTypeField().isContourRect)
            drawRectangleLinesEx(it->getPosition().first, it->getPosition().second, it->getSize().first, it->getSize().second, it->getColors().first, it->getScale());
        if (it->getTypeField().isFullSquare)
            drawRectangle(it->getPosition().first, it->getPosition().second, it->getSize().first, it->getSize().second, it->getColors().first);
        if (it->getTypeField().isText) {
            auto const &text = std::dynamic_pointer_cast<TexteUI>(it);
            drawText(text->getText(), text->getTextPos(), text->getTextSize(), it->getColors().first);
        }
    }
}

void Raylib::printObjects(Raylib::vectorObject &objects) noexcept
{
    BeginDrawing();
    ClearBackground(BLACK);
    for (auto &i : objects) {
        if (i->getTypeField().is3D) {
            BeginMode3D(_camera);
            draw3DObjects(i, objects);
            EndMode3D();
        }
        draw2DObjects(i);
    }
    EndDrawing();
}

bool Raylib::isKeyReleased(int &button) const noexcept
{
    return (IsKeyReleased(button));
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

std::vector<int> Raylib::getControllerInput(int idx)
{
    std::array<int, 4> joystick = {static_cast<int>(GetGamepadAxisMovement(0, 0)), static_cast<int>(GetGamepadAxisMovement(0, 2)), static_cast<int>(GetGamepadAxisMovement(0, 3)), GetGamepadButtonPressed()};
    std::vector<int> joystickToInput;

    for (std::size_t i = 0; i != 3; ++i)
        if (joystick[i])
            joystickToInput.emplace_back(JLL + i * 2 + (1 * (joystick[i] > 0)));
    if (joystick[3] == 6)
        joystickToInput.emplace_back(JA);
    return (joystickToInput);
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
    auto controllerInputs = getControllerInput(0);
    keysDown.insert(keysDown.end(), controllerInputs.begin(), controllerInputs.end());
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
    for (auto &stop : _music) {
        if (stop.first != path) {
            StopMusicStream(stop.second.first);
            stop.second.second = false;
        }
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

void Raylib::drawAnimation(const std::string &modelPath, const std::string &texturePath, const std::string &animationPath, const coords pos, int frameCount, float scale)
{
    auto anim = _animation.find(animationPath);
    auto model = _models.find(modelPath);
    auto text = _textures.find(texturePath);

    if (text == _textures.end()) {
        _textures.insert({texturePath, LoadTexture(texturePath.c_str())});
        text = _textures.find(texturePath);
    }
    if (model == _models.end()) {
        _models.insert({modelPath, LoadModel(modelPath.c_str())});
        model = _models.find(modelPath);
        SetMaterialTexture(&model->second.materials[0], MAP_DIFFUSE, text->second);
    }
    if (anim == _animation.end()) {
        int animsCount = 0;
        _animation.insert({animationPath, LoadModelAnimations(animationPath.c_str(), &animsCount)});
        anim = _animation.find(animationPath);
    }

    UpdateModelAnimation(model->second, anim->second[0], frameCount);
    DrawModelEx(model->second, {pos.first, pos.second, pos.third}, (Vector3){ 1.0f, 0.0f, 0.0f }, -180.0f, (Vector3){ scale, scale, scale }, WHITE);
}

int Raylib::getFrameMax(const std::string &path) {
    auto modeAnim = _animation.find(path);

    if (modeAnim == _animation.end())
        return 0;
    else
        return modeAnim->second[0].frameCount;
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
void Raylib::findCollision(std::shared_ptr<CollisionableObject> obj,
    const std::vector<std::shared_ptr<AObject>> &allObjs
) noexcept
{
    auto toFind = _models.find(obj->getModel());
    if (toFind == _models.cend())
        return;
    auto positionCurrent = obj->getPosition();
    float currentScale = obj->getScale();
    auto tmpBoundCurrent = GetMeshBoundingBox(toFind->second.meshes[0]);
    float maxCurrent = tmpBoundCurrent.max.z > tmpBoundCurrent.max.x ? tmpBoundCurrent.max.z : tmpBoundCurrent.max.x;
    BoundingBox boundCurrent = (BoundingBox) {(Vector3){
        positionCurrent.first - (maxCurrent * currentScale),
        positionCurrent.second - (tmpBoundCurrent.min.y),
        positionCurrent.third - (maxCurrent * currentScale)},
        (Vector3){
            positionCurrent.first + (maxCurrent * currentScale),
            positionCurrent.second + (tmpBoundCurrent.max.y),
            positionCurrent.third + (maxCurrent * currentScale)}};

    for (auto &it : allObjs) {
        if (it->getTypeField().isCollisionable && it->getPosition() != obj->getPosition()) {
            auto tmp = std::dynamic_pointer_cast<CollisionableObject>(it);
            auto toFindOther = _models.find(tmp->getModel());
            if (toFindOther == _models.cend())
                return;
            auto positionOther = it->getPosition();
            float scaleOther = it->getScale();
            float otherRotaton = std::abs(it->getRotationAngle());
            auto tmpBoundOther = GetMeshBoundingBox(toFindOther->second.meshes[0]);
            BoundingBox boundOther = (BoundingBox) {
                (Vector3){
                    positionOther.first - (otherRotaton <= 110 && otherRotaton >= 70 || otherRotaton <= 290 && otherRotaton >= 250 ? tmpBoundOther.max.z : tmpBoundOther.max.x) * scaleOther,
                    positionOther.second - tmpBoundOther.max.y,
                    positionOther.third - (otherRotaton <= 110 && otherRotaton >= 70 || otherRotaton <= 290 && otherRotaton >= 250 ? tmpBoundOther.max.x : tmpBoundOther.max.z) * scaleOther},
                (Vector3){
                    positionOther.first + (otherRotaton <= 110 && otherRotaton >= 70 || otherRotaton <= 290 && otherRotaton >= 250 ? tmpBoundOther.max.z : tmpBoundOther.max.x) * scaleOther,
                    positionOther.second + tmpBoundOther.max.y,
                    positionOther.third + (otherRotaton <= 110 && otherRotaton >= 70 || otherRotaton <= 290 && otherRotaton >= 250 ? tmpBoundOther.max.x : tmpBoundOther.max.z) * scaleOther}};
            if (CheckCollisionBoxes(boundCurrent, boundOther)) {
                auto sound = obj->hit(tmp);
                if (sound != NONE_SOUND)
                    displaySound(MAP_SONG.at(sound), 1.f);
                    //fonction son charlie;
            }
        }
    }
}
bool Raylib::collabsWall(std::pair<int, int> firstItem, coords firstItemSize,std::pair<int, int> scdItem, coords scdItemSize)
{
    if (CheckCollisionBoxes((BoundingBox){(Vector3){static_cast<float>(firstItem.first) - static_cast<float>(firstItemSize.first)/2,
            0 - firstItemSize.second/2,static_cast<float>(firstItem.second) - static_cast<float>(firstItemSize.third)/2},
            (Vector3){static_cast<float>(firstItem.first) + static_cast<float>(firstItemSize.first)/2,
            0 + firstItemSize.second/2, static_cast<float>(firstItem.second) + static_cast<float>(firstItemSize.third)/2}},
        (BoundingBox){(Vector3){static_cast<float>(scdItem.first) - static_cast<float>(scdItemSize.first)/2,
            0 - scdItemSize.second/2,static_cast<float>(scdItem.second) - static_cast<float>(scdItemSize.third)/2},
            (Vector3){static_cast<float>(scdItem.first) + static_cast<float>(scdItemSize.first)/2,
                0 + scdItemSize.second/2, static_cast<float>(scdItem.second) + static_cast<float>(scdItemSize.third)/2}}) ==
        true)
        return true;
    return false;
}