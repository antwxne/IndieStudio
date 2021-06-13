/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_IOBJECT_HPP
#define INDIESTUDIO_IOBJECT_HPP

#include <vector>
#include "Raylib/RayObj/IRayObj.hpp"

enum objType_e {
    BASIC,
    GRADIENT,
    LINES,
    WIRES
};

struct RGB
{
    RGB(int red = 255, int green = 255, int blue = 255, int alpha = 255) : r(red), g(green), b(blue), a(alpha) {};
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};


template <typename T>
std::pair<T, T> &operator+=(std::pair<T, T>&current, const std::pair<T, T> &other)
{
    current.first += other.first;
    current.second += other.second;
    return current;
}

typedef struct type_field_s {
    bool is_3D: 1;
    bool is_object: 1;
    bool is_collisionable: 1;
    bool is_destructible: 1;
    bool is_movable: 1;
    bool is_tank: 1;
    bool is_cannon: 1;
    bool is_bullet: 1;
} type_field_t;

class IObject {
public:
    [[nodiscard]] virtual const type_field_t &getTypeField() const noexcept = 0;
    [[nodiscard]] virtual const std::pair<int, int> &getPosition() const noexcept = 0;
    [[nodiscard]] virtual const std::pair<int, int> &getSize() const noexcept = 0;
    [[nodiscard]] virtual const std::pair<RGB, RGB> &getColors() const noexcept = 0;
    [[nodiscard]] virtual const float &getScale() const noexcept = 0;

    virtual void setSize(std::pair<int, int> size) noexcept = 0;
    virtual void setScale(float scale) noexcept = 0;
    virtual void set3d(bool is3d) noexcept = 0;
    virtual void setPosition(std::pair<int, int> position) noexcept = 0;

    virtual const void funcDraw() noexcept = 0;
    //virtual const sprite &getSprite() const noexcept = 0;
};

#endif //INDIESTUDIO_IOBJECT_HPP
