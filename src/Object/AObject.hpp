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
    AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size, float scale, const std::pair<RGB, RGB> &colors, std::unique_ptr<IRayObj> &&func);
    AObject(const std::pair<int, int> &pos, const std::pair<int, int> &size, float scale, std::unique_ptr<IRayObj> &&func);
    AObject(std::unique_ptr<IRayObj> &&func);
    ~AObject() = default;

    [[nodiscard]] const type_field_t &getTypeField() const noexcept override;
    [[nodiscard]] const std::pair<int, int> &getPosition() const noexcept final;
    [[nodiscard]] const std::pair<int, int> &getSize() const noexcept final;
    [[nodiscard]] const std::pair<RGB, RGB> &getColors() const noexcept final;
    [[nodiscard]] const float &getScale() const noexcept final;
    void set3d(bool is3d) noexcept final;
    void setPosition(std::pair<int, int> position) noexcept final;
    const void funcDraw() noexcept final;

    void setSize(std::pair<int, int> size) noexcept final;
    void setScale(float scale) noexcept final;

protected:
    std::pair<int, int> _pos;
    std::pair<int, int> _size;
    std::pair<RGB, RGB> _color;
    float _rotation;
    type_field_t _type_field;
    std::unique_ptr<IRayObj> _drawable;
    float _scale;
    //sprite
};

#endif //INDIESTUDIO_AOBJECT_HPP
