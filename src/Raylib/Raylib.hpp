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

#include <cstddef>
#include <string>
#include <utility>
#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include "raylib.h"

#include "IObject.hpp"
#include "Raylib/RayObj/IRayObj.hpp"

class Raylib
{
public:
    using uIObject = std::unique_ptr<IObject>;
    using vectorObject = std::vector<uIObject>;
    enum Keys {
        NULL_KEY,
        ENTER,
        SPACE,
        ESCAPE,
        TAB,
        UP,
        DOWN,
        RIGHT,
        LEFT,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    };

    Raylib();
    ~Raylib();

    void createWindow(int screenWidth, int screenHeight, std::string const &title, std::size_t const Fps);

    bool gameLoop();

    void printObjects(vectorObject &objects);
    // all print funcs under will be private (ex: type Vector3 only defined in raylib.h)
    void printFps(std::pair<int, int> const pos) const;
    void printGrid(int const slices, float const space) const;

    void setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
    Camera getCamera() const;

    bool isControllerDetected(int const idx) const;
    bool isControllerValid(int const idx, std::string const &ControllerName) const;
    std::string getControllerName(int const idx) const;

    bool isKeyPressed(int button) const noexcept;
    bool isKeyReleased(int button) const noexcept;
    int getKeyPressed() const;

protected:
private:
    std::pair<int, int> _screenSize;
    Camera _camera;
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
