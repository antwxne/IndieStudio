/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/IObject.hpp"

#ifndef INDIESTUDIO_AOBJECT_HPP
#define INDIESTUDIO_AOBJECT_HPP

class AObject: public IObject {
public:
    AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size);
    ~AObject() = default;

    [[nodiscard]] const type_field_t & getTypeField() const noexcept override;
    [[nodiscard]] const std::pair<int, int> & getPosition() const noexcept final;
    [[nodiscard]] const std::pair<int, int> & getSize() const noexcept final;

protected:
    std::pair<int, int> _pos;
    std::pair<int, int> _size;
    float _rotation;
    type_field_t _type_field;
    //sprite
};

#endif //INDIESTUDIO_AOBJECT_HPP
