/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/IObject.hpp"
//#include "TypeObject.hpp"

#ifndef INDIESTUDIO_AOBJECT_HPP
#define INDIESTUDIO_AOBJECT_HPP

class AObject: public IObject {
public:
    AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size);
    ~AObject() = default;

    [[nodiscard]] int getBitMap() const noexcept final;
    [[nodiscard]] const std::pair<int, int> & getPosition() const noexcept final;
    [[nodiscard]] const std::pair<int, int> & getSize() const noexcept final;

//    template<typename T>
//    static bool isTypeOf(const IObject &obj) {
//        return (obj.getBitMap() << TYPES_OBJECT.at(typeid(T))) & 1;
//    }

protected:
    std::pair<int, int> _pos;
    std::pair<int, int> _size;
    int _bitmap;
    float _rotation;
    //sprite
};

#endif //INDIESTUDIO_AOBJECT_HPP
