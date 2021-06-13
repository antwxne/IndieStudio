/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/CollisionableObject.hpp"

#ifndef INDIESTUDIO_DESTROYABLEOBJECT_HPP
#define INDIESTUDIO_DESTROYABLEOBJECT_HPP

class DestructibleObject: public CollisionableObject {
public:
    DestructibleObject(const coords &pos,
        const std::pair<int, int> &size, const std::pair<std::string, std::string> &path);
    ~DestructibleObject() = default;

    [[nodiscard]] float getLife() const;
    void setLife(float life);
    void updateLife(float life);
    bool isDestroyed() const;
    struct destructible_t {
        int x;
        int y;
        float life;
    };
    const destructible_t &getStructSave() noexcept;

protected:
    float _life;
    destructible_t _save;
};

#endif //INDIESTUDIO_DESTROYABLEOBJECT_HPP
