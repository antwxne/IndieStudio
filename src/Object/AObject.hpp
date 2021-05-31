/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_AOBJECT_HPP
#define INDIESTUDIO_AOBJECT_HPP

#include "Object/IObject.hpp"

class AObject: public IObject {
public:
    AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size);
    ~AObject() = default;
protected:
    std::pair<int, int> _pos;
    std::pair<int, int> _size;
    int _bitmap;
    //sprite
};

#endif //INDIESTUDIO_AOBJECT_HPP
