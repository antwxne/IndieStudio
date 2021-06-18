/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Animator
*/

#include "Animator.hpp"

Animator::Animator(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path, const std::string &animePath)
    : MovableObject(pos, size, path), _frameCount(0), _animePath(animePath)
{
    _typeField.isAnimator = true;
}

Animator::Animator(Animator &toCopy)
    : MovableObject(toCopy._pos, coords(1, 1, 1), toCopy._path), _frameCount(toCopy._frameCount), _animePath(toCopy._animePath)
{
    _typeField.isAnimator = true;
}

Animator::~Animator()
{
}

void Animator::setFrameCount(const int frame) noexcept
{
    _frameCount = frame;
}

int Animator::getFrameActual() noexcept {
    return _frameCount;
}

void Animator::addFrameCount(const int up) noexcept
{
    _frameCount += up;
}

std::string Animator::getAnimPath() const noexcept
{
    return _animePath;
}