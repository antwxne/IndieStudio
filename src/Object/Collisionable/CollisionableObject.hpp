/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/AObject.hpp"

#ifndef INDIESTUDIO_COLLISIONABLEOBJECT_HPP
#define INDIESTUDIO_COLLISIONABLEOBJECT_HPP

class CollisionableObject: public AObject {
public:
    CollisionableObject(const std::pair<int, int> &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path);
    ~CollisionableObject() = default;

    [[nodiscard]] const std::string &getTexture() const noexcept;
    [[nodiscard]] const std::string &getModel() const noexcept;

    void setTexture(const std::string &texture) noexcept;
    void setModel(const std::string &texture) noexcept;

    bool hit(const CollisionableObject &) const noexcept;
private:
    std::string _texturePath;
    std::string _modelPath;
};

#endif //INDIESTUDIO_COLLISIONABLEOBJECT_HPP
