/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_IOBJECT_HPP
#define INDIESTUDIO_IOBJECT_HPP

#include <vector>

class IObject {
public:
    virtual int getBitMap() const noexcept = 0;
    [[nodiscard]] virtual const std::pair<int, int> &getPosition() const noexcept = 0;
    [[nodiscard]] virtual const std::pair<int, int> &getSize() const noexcept = 0;
    //virtual const sprite &getSprite() const noexcept = 0;
    enum shift_e {
        OBJECT,
        COLLISIONABLE,
        MOVABLE,
        DESTROYABLE
    };
};

#endif //INDIESTUDIO_IOBJECT_HPP
