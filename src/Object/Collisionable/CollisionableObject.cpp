/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Destructible/Movable/TankAi.hpp"
#include "CollisionableObject.hpp"

CollisionableObject::CollisionableObject(const coords &pos,
    const std::pair<int, int> &size, const std::pair<std::string, std::string> &path
) : AObject(pos, size, 1)
{
    _path = path;
    _typeField.isCollisionable = true;
    _typeField.is3D = true;
}

CollisionableObject::CollisionableObject(CollisionableObject const &object) : AObject(object._pos, object._size, 1), _path(object._path)
{
    _typeField.isCollisionable = true;
    _typeField.is3D = true;
}

void CollisionableObject::setTexture(const std::string &texture) noexcept
{
    _path.first = texture;
}

void CollisionableObject::setModel(const std::string &texture) noexcept
{
    _path.second = texture;
}

const std::string &CollisionableObject::getTexture() const noexcept
{
    return _path.first;
}

const std::string &CollisionableObject::getModel() const noexcept
{
    return _path.second;
}

bool CollisionableObject::hit(const CollisionableObject &obj) noexcept
{
    if (this->_pos.first + this->_size.first >= obj._pos.first
    && this->_pos.first <= obj._pos.first + obj._size.first
    && this->_pos.second + this->_size.second >= obj._pos.second
    && this->_pos.second <= obj._pos.second + obj._size.second) {
        if (this->_typeField.isIa && obj._typeField.isWall) {
            auto tmp = dynamic_cast<TankAI *>(this);
            tmp->setBlocked(true);
        }
        if (this->_typeField.isDestructible) {
            auto tmp = dynamic_cast<DestructibleObject *>(this);
            tmp->updateLife(-1);
        }
        if (this->_typeField.isBullet) {
            auto tmp = dynamic_cast<Bullet *>(this);
            tmp->bounce();
        }
        return true;
    }
    return false;
}