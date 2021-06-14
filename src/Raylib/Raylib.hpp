/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Raylib
*/

#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

#ifndef RAYLIBENCAPSULATION_HPP_
#define RAYLIBENCAPSULATION_HPP_

#include <string>
#include <utility>
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include "raylib.h"

#include "Object/IObject.hpp"

class Raylib
{
public:
    using uIObject = std::shared_ptr<IObject>;
    using vectorObject = std::vector<uIObject>;
    enum Keys {
        NULL_KEY,
        ENTER,
        SPACE,
        ESCAPE,
        TAB,
        CLICK,
        RELEASED,
        UP,
        DOWN,
        RIGHT,
        LEFT,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    };

    Raylib();
    ~Raylib();

    void createWindow(int &screenWidth, int &screenHeight, std::string const &title, std::size_t const &Fps) noexcept;

    bool gameLoop() const noexcept;

    void printObjects(vectorObject &objects) noexcept;
    // all print funcs under will be private (ex: type Vector3 only defined in raylib.h)
    void printFps(std::pair<int, int> const &pos) const noexcept;
    void printGrid(int const &slices, float const &space) const noexcept;
    void drawModel(const std::string &modelPath, const std::string &texturePath, coords pos, float scale, RGB tint);
    void drawTexture(const std::string &path, int posX, int posY, RGB tint);
    void drawText(const std::string &text, coords pos, float scale, RGB tint);

    void setCamera(Vector3 &pos, Vector3 &target, Vector3 &up, float &fovy, int &projection) noexcept;
    Camera getCamera() const noexcept;

    bool isControllerDetected(int const &idx) const noexcept;
    bool isControllerValid(int const &idx, std::string const &ControllerName) const noexcept;
    std::string getControllerName(int const &idx) const noexcept;

    bool isMousePressed() const noexcept;
    bool isMouseReleased() const noexcept;
    bool isKeyPressed(int &button) const noexcept;
    bool isKeyReleased(int &button) const noexcept;
    std::string textForSubText(std::string const &text, int &pos, int &frameCounter) const noexcept;
    int getKeyPressed() const noexcept;
    const std::pair<float, float> getMousePosition() const noexcept; 

    static float getDeltaTime() noexcept;
    void freeResources();

protected:
private:
    std::pair<int, int> _screenSize;
    Camera _camera;
    std::unordered_map<std::string, Model> _models;
    std::unordered_map<std::string, Texture2D> _textures;
    std::vector<int> _keys = {
        KEY_NULL,
        KEY_ENTER,
        KEY_SPACE,
        KEY_ESCAPE,
        KEY_TAB,
        KEY_UP,
        KEY_DOWN,
        KEY_RIGHT,
        KEY_LEFT,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
    };
};

#endif /* !RAYLIBENCAPSULATION_HPP_ */
