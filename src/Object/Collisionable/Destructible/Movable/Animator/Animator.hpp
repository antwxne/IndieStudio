/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Animator
*/

#ifndef ANIMATOR_HPP_
#define ANIMATOR_HPP_

#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"

class Animator : public MovableObject
{
    public:
        Animator(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path, const std::string &animePath);
        Animator(Animator &ToCopy);
        ~Animator();
        void addFrameCount(const int up) noexcept;
        int getFrameActual() noexcept;
        void setFrameCount(const int frame) noexcept;
        std::string getAnimPath() const noexcept;

    private:
        int _frameCount;
        std::string _animePath;
};

#endif /* !ANIMATOR_HPP_ */
