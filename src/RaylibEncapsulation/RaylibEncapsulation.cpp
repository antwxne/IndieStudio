/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaylibEncapsulation
*/

#include "RaylibEncapsulation.hpp"

RaylibEncapsulation::RaylibEncapsulation() {}

RaylibEncapsulation::~RaylibEncapsulation() {}

void RaylibEncapsulation::CreateWindow(int screenWidth, int screenHeight, std::string title, std::size_t Fps) {
    _screenSize.first = screenWidth;
    _screenSize.second = screenHeight;
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(Fps);
}

void RaylibEncapsulation::DestroyWindow() {
    CloseWindow();
}

void RaylibEncapsulation::DrawingLoopBegun() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void RaylibEncapsulation::DrawingLoopEnd() {
    EndDrawing();
}

void RaylibEncapsulation::PrintText(std::string text, std::pair<int, int> position, int fontSize, Color color) {
    DrawText(text.c_str(), position.first, position.second, fontSize, color);
}