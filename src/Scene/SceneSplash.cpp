/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneSplash
*/

#include "SceneSplash.hpp"
#include "TexteUi.hpp"
#include "FullSquare.hpp"

SceneSplash::SceneSplash(Setting &settings)
    : UiScene(settings), _frame(0), _logoPositionX(settings._widthScreen / 2 - 128), _logoPositionY(settings._heightScreen / 2 - 128), _framesCounter(0), _lettersCount(0),
    _topSideRecWidth(16), _leftSideRecHeight(16), _bottomSideRecWidth(16), _rightSideRecHeight(16), _scene(0), _alpha(1)
{
    _objects.emplace_back(std::make_shared<FullSquare>(coords(0, 0), std::make_pair(1920, 1080), 1, std::make_pair(RGB(), RGB())));
    _objects.emplace_back(std::make_shared<TexteUI>(coords(_settings._widthScreen/2 - 44, _settings._heightScreen/2 + 48), std::make_pair(0, 0), "Raylib", 50, 1, std::make_pair(RGB(0, 0, 0, 0), RGB())));
    _objects.emplace_back(std::make_shared<TexteUI>(coords(10, 100), std::make_pair(0, 0), "NormIndie présente:", 120, 1, std::make_pair(RGB(0, 0, 0), RGB())));
    _objects.emplace_back(std::make_shared<FullSquare>(coords(-100, -100), std::make_pair(16, 16), 1, std::make_pair(RGB(0, 0, 0), RGB())));
    _objects.emplace_back(std::make_shared<FullSquare>(coords(-100, -100), std::make_pair(16, 16), 1, std::make_pair(RGB(0, 0, 0), RGB())));
    _objects.emplace_back(std::make_shared<FullSquare>(coords(-100, -100), std::make_pair(16, 16), 1, std::make_pair(RGB(0, 0, 0), RGB())));
    _objects.emplace_back(std::make_shared<FullSquare>(coords(-100, -100), std::make_pair(16, 16), 1, std::make_pair(RGB(0, 0, 0), RGB())));
}

SceneSplash::~SceneSplash()
{
}

void SceneSplash::eventScene(Raylib &lib)
{
    if (_scene == 0) {
        _framesCounter++;
        if (_framesCounter == 120) {
            _scene = 1;
            _framesCounter = 0;
        }
    } else if (_scene == 1) {
        _topSideRecWidth += 4;
        _leftSideRecHeight += 4;
        if (_topSideRecWidth == 256)
            _scene = 2;
    } else if (_scene == 2) {
        _bottomSideRecWidth += 4;
        _rightSideRecHeight += 4;
        if (_bottomSideRecWidth == 256)
            _scene = 3;
    } else if (_scene == 3) {
        _framesCounter++;
        if (_framesCounter / 12) {
            _lettersCount++;
            _framesCounter = 0;
        }
        if (_lettersCount >= 10) {
            _alpha -= 0.02f;
            if (_alpha <= 0.0f) {
                _alpha = 0.0f;
                _scene = 4;
            }
        }
    } else if (_scene == 4)
        _state = 0;
    if (_scene == 0) {
        if ((_framesCounter/15)%2)
            _objects.back()->setPosition(coords(_logoPositionX, _logoPositionY));
            _objects.back()->setSize(std::make_pair(16, 16));
    }
    if (_scene == 1) {
        _objects.back()->setPosition(coords(_logoPositionX, _logoPositionY));
        _objects.back()->setSize(std::make_pair(_topSideRecWidth, 16));
        _objects.at(_objects.size() - 2)->setPosition(coords(_logoPositionX, _logoPositionY));
        _objects.at(_objects.size() - 2)->setSize(std::make_pair(16, _leftSideRecHeight));
    }
    if (_scene == 2) {
        _objects.at(_objects.size() - 3)->setPosition(coords(_logoPositionX + 240, _logoPositionY));
        _objects.at(_objects.size() - 3)->setSize(std::make_pair(16, _rightSideRecHeight));
        _objects.at(_objects.size() - 4)->setPosition(coords(_logoPositionX, _logoPositionY + 240));
        _objects.at(_objects.size() - 4)->setSize(std::make_pair(_bottomSideRecWidth, 16));
    }
    if (_scene == 3) {
        auto color = _objects.at(1)->getColors();
        color.first.a += (10 * (color.first.a < 250));
        _objects.at(1)->setColor(color);
    }
}

Scenes SceneSplash::endScene(Raylib &lib) noexcept
{
    return (Scenes::INTRODUCTION);
}