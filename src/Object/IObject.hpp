/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_IOBJECT_HPP
#define INDIESTUDIO_IOBJECT_HPP

#include <vector>
#include <cstring>
#include <memory>
#include <utility>
#include <string>
#include <iostream>

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


struct coords
{
    coords(float f = 0, float s = 0, float t = 0) : first(f), second(s), third(t) {};
    coords &operator+=(coords const &rhs) {
        first += rhs.first;
        second += rhs.second;
        third += rhs.third;
        return *this;
    }

    coords &operator-(coords const &rhs) {
        first -= rhs.first;
        second -= rhs.second;
        third -= rhs.third;
        return *this;
    }

    coords &operator*=(float val) {
        first *= val;
        second *= val;
        third *= val;
        return *this;
    }

    float first;
    float second;
    float third;
};

// template<typename T>
// struct Type3
// {
//     Type3(T f, T s, T t) : first(f), second(s), third(t) {};
//     T first;
//     T second;
//     T third;
// };

// template <typename T>
// struct Type3<T> &operator+=(struct Type3<T>&current, const struct Type3<T> &other)
// {
//     current.first += other.first;
//     current.second += other.second;
//     current.third += other.third;
//     return current;
// }

// template<typename T>
// struct Type3<T> &operator-(struct Type3<T> &a, const struct Type3<T> &b)
// {
//     a.first -= b.first;
//     a.second -= b.second;
//     a.third -= b.third;
//     return a;
// }

struct typeField {
    bool is3D: 1;
    bool isObject: 1;
    bool isButton: 1;
    bool isCollisionable: 1;
    bool isDestructible: 1;
    bool isMovable: 1;
    bool isTank: 1;
    bool isCannon: 1;
    bool isBullet: 1;
    bool isIa: 1;
    bool isWall: 1;
};

/**
 * @class IObject
 *
 * @brief interface for objects
 */
class IObject {
public:
    /**
     * @brief Get the Type Field object
     * 
     * @return const typeField& 
     */
    [[nodiscard]] virtual const typeField &getTypeField() const noexcept = 0;
    /**
     * @brief Get the Position object
     * 
     * @return const coords& 
     */
    [[nodiscard]] virtual const coords &getPosition() const noexcept = 0;
    /**
     * @brief Get the Size object
     * 
     * @return const std::pair<int, int>& 
     */
    [[nodiscard]] virtual const std::pair<int, int> &getSize() const noexcept = 0;
    /**
     * @brief Get the Colors object
     * 
     * @return const std::pair<RGB, RGB>& 
     */
    [[nodiscard]] virtual const std::pair<RGB, RGB> &getColors() const noexcept = 0;
    /**
     * @brief Get the Scale object
     * 
     * @return const float& 
     */
    [[nodiscard]] virtual const float &getScale() const noexcept = 0;

    /**
     * @brief Set the Size object
     * 
     * @param size 
     */
    virtual void setSize(std::pair<int, int> size) noexcept = 0;
    /**
     * @brief Set the Scale object
     * 
     * @param scale 
     */
    virtual void setScale(float scale) noexcept = 0;
    /**
     * @brief 
     * 
     * @param is3d ? true or false 
     */
    virtual void set3d(bool is3d) noexcept = 0;
    /**
     * @brief Set the Position object
     * 
     * @param position 
     */
    virtual void setPosition(coords position) noexcept = 0;
};

#endif //INDIESTUDIO_IOBJECT_HPP
