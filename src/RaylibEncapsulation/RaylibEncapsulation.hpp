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
#include "raylib.h"

class RaylibEncapsulation {
    public:
        RaylibEncapsulation();
        ~RaylibEncapsulation();

        void CreateWindow(int screenWidth, int screenHeight, std::string title, std::size_t Fps);
        void DestroyWindow();

        void DrawingLoopBegun();
        void DrawingLoopEnd();
        void PrintText(std::string text, std::pair<int, int> position, int fontSize, Color color);

    protected:
    private:
        std::pair<int, int> _screenSize;
};

#endif /* !RAYLIBENCAPSULATION_HPP_ */
