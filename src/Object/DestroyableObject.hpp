/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#ifndef INDIESTUDIO_DESTROYABLEOBJECT_HPP
#define INDIESTUDIO_DESTROYABLEOBJECT_HPP

class DestroyableObject {
public:
    DestroyableObject();
    ~DestroyableObject() = default;

    [[nodiscard]] float getLife() const;
    void setLife(float life);
    void updateLife(float life);
    bool isDestroyed() const;

protected:
    float _life;
};

#endif //INDIESTUDIO_DESTROYABLEOBJECT_HPP
