/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaylibEncapsulation
*/

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

    void CreateWindow(int screenWidth, int screenHeight, std::string title, std::size_t Fps);
    void DestroyWindow();

    void DrawingLoopBegun();
    void DrawingLoopEnd();

    void PrintText(std::string text, std::pair<int, int> position, int fontSize, Color color);
    void PrintCircle(std::string type, std::pair<int, int> position, float radius, std::pair<Color, Color> color);
    void PrintRectangle(std::string type, std::pair<int, int> position, std::pair<int, int> size, std::pair<Color, Color> color);
    void PrintGrid(int slices, float space);
    void PrintCube(std::string type, Vector3 position, Vector3 size, Color color);
    void PrintSphere(std::string type, Vector3 position, float size, std::pair<int, int> Vertex ,Color color);
    void PrintFps(std::pair<int, int> pos);

    void SetCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
    Camera GetCamera(void);

    void Set3d(bool is3d);
    bool Get3d(void);

protected:
private:
    std::pair<int, int> _screenSize;
    Camera _camera;
    bool _is3D;
};

#endif /* !RAYLIBENCAPSULATION_HPP_ */
