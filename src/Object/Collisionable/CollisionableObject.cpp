/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Destructible/Movable/TankAi.hpp"
#include "CollisionableObject.hpp"
#include "Object/Collisionable/Destructible/Movable/PowerUps/PowerUps.hpp"

CollisionableObject::CollisionableObject(const coords &pos, const coords &size,
    const std::pair<std::string, std::string> &path
) : AObject(pos, std::make_pair(size.first, size.second), 1), _path(path)
{
    _typeField.is3D = true;
    _typeField.isCollisionable = true;
    _3DSize = size;
}

CollisionableObject::CollisionableObject(CollisionableObject const &object)
    : AObject(object._pos, object._size, object._scale), _path(object._path)
{
    _typeField.is3D = true;
    _typeField.isCollisionable = true;
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

void CollisionableObject::setRotationAngle(const float angle) noexcept
{
    _rotationAngle = angle;
}

void CollisionableObject::setRotationAxis(const coords &axis) noexcept
{
    _rotationAxis = axis;
}

bool CollisionableObject::hit(std::shared_ptr<CollisionableObject> obj) noexcept
{
    if (this->_typeField.isTank && obj->_typeField.isCollisionable) {
        auto tmp = dynamic_cast<Tank *>(this);
        tmp->setPosition(tmp->getPreviousPos());
    }
    if (this->_typeField.isDestructible && obj->_typeField.isBullet) {
        auto destructObj = dynamic_cast<DestructibleObject *>(this);
        auto bullet = std::dynamic_pointer_cast<const Bullet>(obj);
        destructObj->updateLife(-bullet->getDamage());
    }
    if (this->_typeField.isBullet && (!obj->getTypeField().isTank || !this->_typeField.isShooting)) {
        auto bullet = dynamic_cast<Bullet *>(this);
        bullet->bounce();
        bullet->setLife(bullet->getLife() - 1);
        if (bullet->getLife() <= 0) {
            bullet->resetBullet();
        }
    }
    if (this->_typeField.isTank && obj->getTypeField().isPowerUps) {
        auto power = std::dynamic_pointer_cast<PowerUps>(obj);
        auto &tank = dynamic_cast<Tank &>(*this);
        power->applyPowerUps(tank);
    }
    return false;
}