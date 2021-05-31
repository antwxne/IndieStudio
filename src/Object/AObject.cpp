/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/AObject.hpp"

AObject::AObject(const std::pair<int, int> &pos,
    const std::pair<int, int> &size
): _pos(pos), _size(size), _bitmap(1 << OBJECT)
{
}
