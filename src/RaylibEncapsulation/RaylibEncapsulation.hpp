/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaylibEncapsulation
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
#include "raylib.h"

class RaylibEncapsulation
{
public:
    RaylibEncapsulation();
    ~RaylibEncapsulation();

    void CreateWindow(int screenWidth, int screenHeight, std::string const title, std::size_t const Fps);
    void DestroyWindow() const;

    void DrawingLoopBegun() const;
    void DrawingLoopEnd() const;

    void PrintText(std::string const text, std::pair<int, int> const position, int const fontSize, Color const color) const;
    void PrintCircle(std::string const type, std::pair<int, int> const position, float const radius, std::pair<Color, Color> const color) const;
    void PrintRectangle(std::string const type, std::pair<int, int> const position, std::pair<int, int> const size, std::pair<Color, Color> const color) const;
    void PrintGrid(int const slices, float const space) const;
    void PrintCube(std::string const type, Vector3 const position, Vector3 const size, Color const color) const;
    void PrintSphere(std::string const type, Vector3 const position, float const size, std::pair<int, int> const Vertex ,Color const color) const;
    void PrintFps(std::pair<int, int> const pos) const;

    void SetCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
    Camera GetCamera() const;

    void Set3d(bool is3d);
    bool Get3d() const;

    bool IsControllerDetected(int const idx) const;
    bool IsControllerValid(int const idx, std::string const ControllerName) const;
    std::string GetControllerName(int const idx) const;

protected:
private:
    std::pair<int, int> _screenSize;
    Camera _camera;
    bool _is3D;
};

#endif /* !RAYLIBENCAPSULATION_HPP_ */
