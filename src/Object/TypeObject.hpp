/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_TYPEOBJECT_HPP
#define INDIESTUDIO_TYPEOBJECT_HPP

#include <typeinfo>
#include <functional>
#include <unordered_map>

#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"

using TypeInfo = std::reference_wrapper<const std::type_info>;

class Hash {
public:
    std::size_t operator()(TypeInfo code) const
    {
        return code.get().hash_code();
    }
};

class Equal {
    bool operator()(TypeInfo left, TypeInfo right) const
    {
        return left.get() == right.get();
    }
};

static const std::unordered_map<TypeInfo, IObject::shift_e, Hash, Equal> TYPES_OBJECT {
    {typeid(AObject), IObject::shift_e::OBJECT},
    {typeid(CollisionableObject), IObject::shift_e::COLLISIONABLE},
    {typeid(MovableObject), IObject::shift_e::MOVABLE}
};

#endif //INDIESTUDIO_TYPEOBJECT_HPP
