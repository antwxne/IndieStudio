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
    AObject(const Type3<float> &pos, const std::pair<int, int> &size, float scale, const std::pair<RGB, RGB> &colors);
    AObject(const Type3<float> &pos, const std::pair<int, int> &size, float scale);
    ~AObject() = default;

    [[nodiscard]] const typeField &getTypeField() const noexcept override;
    [[nodiscard]] const Type3<float> &getPosition() const noexcept final;
    [[nodiscard]] const std::pair<int, int> &getSize() const noexcept final;
    [[nodiscard]] const std::pair<RGB, RGB> &getColors() const noexcept final;
    [[nodiscard]] const float &getScale() const noexcept final;
    void set3d(bool is3d) noexcept final;
    void setPosition(Type3<float> position) noexcept final;

    void setSize(std::pair<int, int> size) noexcept final;
    void setScale(float scale) noexcept final;

protected:
    Type3<float> _pos;
    std::pair<int, int> _size;
    std::pair<RGB, RGB> _color;
    float _rotation;
    typeField _typeField;
    float _scale;
};

#endif //INDIESTUDIO_AOBJECT_HPP
