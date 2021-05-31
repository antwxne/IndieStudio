/*
** EPITECH PROJECT, 2021
** IScene.hpp
** File description:
** IScene.hpp
*/

#pragma once

class IScene {
    public:
    virtual void run() noexcept = 0;
    virtual void close() noexcept = 0;
    virtual void destroy() noexcept = 0;
};