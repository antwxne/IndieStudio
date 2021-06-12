/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <vector>

#ifndef INDIESTUDIO_IOBJECT_HPP
#define INDIESTUDIO_IOBJECT_HPP

enum objType_e {
    BASIC,
    GRADIENT,
    LINES,
    WIRES
};

struct RGB
{
    RGB(int red = 0, int green = 0, int blue = 0, int alpha = 0) : r(red), g(green), b(blue), a(alpha) {};
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

    virtual void setSize(std::pair<int, int> size) noexcept = 0;
    virtual void setScale(float scale) noexcept = 0;

    [[nodiscard]] virtual const float &getScale() const noexcept = 0;
    [[nodiscard]] virtual const std::pair<struct RGB, struct RGB> &getColors() const noexcept = 0;
    [[nodiscard]] virtual const objType_e &getType() const noexcept = 0;
    [[nodiscard]] virtual const bool is3D() const noexcept = 0;
    virtual const void funcDraw() noexcept = 0;
    //virtual const sprite &getSprite() const noexcept = 0;
};

#endif //INDIESTUDIO_IOBJECT_HPP
