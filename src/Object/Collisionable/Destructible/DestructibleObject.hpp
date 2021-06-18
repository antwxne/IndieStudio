/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/CollisionableObject.hpp"

#ifndef INDIESTUDIO_DESTROYABLEOBJECT_HPP
#define INDIESTUDIO_DESTROYABLEOBJECT_HPP


/**
 * @class Destructible object
 *
 * @brief Base class for destructible object
 */
class DestructibleObject: public CollisionableObject {
public:
    /**
     * @brief Construct a new Destructible Object object
     *
     * @param pos
     * @param size
     * @param path
     */
    DestructibleObject(const coords &pos,
        const coords &size, const std::pair<std::string, std::string> &path);
    /**
     * @brief Destroy the Destructible Object object
     *
     */
    ~DestructibleObject() = default;
    /**
     * @brief Get the Life object
     *
     * @return float
     */
    [[nodiscard]] float getLife() const;
    /**
     * @brief Set the Life object
     *
     * @param life
     */
    void setLife(float life);
    /**
     * @brief
     *
     * @param life
     */
    void updateLife(float life);
    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool isDestroyed() const;
    struct destructible_t {
        int x;
        int y;
        float life;
    };
    /**
     * @brief Get the Struct Save object
     *
     * @return const destructible_t&
     */
    const destructible_t &getStructSave() noexcept;

protected:
    float _life;
    destructible_t _save;
};

#endif //INDIESTUDIO_DESTROYABLEOBJECT_HPP
