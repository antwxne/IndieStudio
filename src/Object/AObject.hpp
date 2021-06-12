/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/IObject.hpp"
#include "Raylib/RayObj/IRayObj.hpp"

#ifndef INDIESTUDIO_AOBJECT_HPP
#define INDIESTUDIO_AOBJECT_HPP

class AObject: public IObject {
public:
    AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size, std::unique_ptr<IRayObj> func, bool is3D, float scale);
    ~AObject() = default;

    [[nodiscard]] const type_field_t &getTypeField() const noexcept override;
    [[nodiscard]] const std::pair<int, int> &getPosition() const noexcept final;
    [[nodiscard]] const std::pair<int, int> &getSize() const noexcept final;

    void setSize(std::pair<int, int> size) noexcept final;
    void setScale(float scale) noexcept final;

    [[nodiscard]] const std::pair<struct RGB, struct RGB> &getColors() const noexcept final;
    [[nodiscard]] const objType_e &getType() const noexcept final;
    [[nodiscard]] const bool is3D() const noexcept final;
    [[nodiscard]] const float &getScale() const noexcept final;
    virtual const void funcDraw() noexcept final;

protected:
    std::pair<int, int> _pos;
    std::pair<int, int> _size;
    objType_e _type;
    std::pair<struct RGB, struct RGB> _color;
    float _rotation;
    type_field_t _type_field;
    std::unique_ptr<IRayObj> _drawable;
    bool _is3D;
    float _scale;
    //sprite
};

#endif //INDIESTUDIO_AOBJECT_HPP
