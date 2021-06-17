/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/AObject.hpp"

#ifndef INDIESTUDIO_COLLISIONABLEOBJECT_HPP
#define INDIESTUDIO_COLLISIONABLEOBJECT_HPP

/**
 * @class Collisionable Object
 *
 * @brief base class for objects with collision
 */
class CollisionableObject: public AObject {
public:
    /**
     * @brief Construct a new Collisionable Object object
     *
     * @param pos
     * @param size
     * @param path
     */
    CollisionableObject(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path);
    /**
     * @brief Construct a new Collisionable Object object
     *
     * @param collisionableObject
     */
    CollisionableObject(CollisionableObject const &collisionableObject);
    /**
     * @brief Destroy the Collisionable Object object
     *
     */
    ~CollisionableObject() = default;

    /**
     * @brief check colision and update the object
     *
     * @return true
     * @return false
     */
    bool hit(const CollisionableObject &) noexcept;
    /**
     * @brief Get the Texture object
     *
     * @return const std::string&
     */
    [[nodiscard]] const std::string &getTexture() const noexcept;
    /**
     * @brief Get the Model object
     *
     * @return const std::string&
     */
    [[nodiscard]] const std::string &getModel() const noexcept;

    /**
     * @brief Set the Texture object
     *
     * @param texture
     */
    void setTexture(const std::string &texture) noexcept;
    /**
     * @brief Set the Model object
     *
     * @param texture
     */
    void setModel(const std::string &texture) noexcept;

    void setRotationAngle(const float angle) noexcept;
    void setRotationAxis(const coords &axis) noexcept;
    const coords &get3DSize() const noexcept {return  _3DSize;};

protected:
    std::pair<std::string, std::string> _path;
    coords _3DSize;
};

#endif //INDIESTUDIO_COLLISIONABLEOBJECT_HPP
