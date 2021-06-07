/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <vector>

#ifndef INDIESTUDIO_IOBJECT_HPP
#define INDIESTUDIO_IOBJECT_HPP

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
    //virtual const sprite &getSprite() const noexcept = 0;
};

#endif //INDIESTUDIO_IOBJECT_HPP
