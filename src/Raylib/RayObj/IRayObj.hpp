/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** IRayObj
*/

#ifndef IRAYOBJ_HPP_
#define IRAYOBJ_HPP_

#include "Raylib/Raylib.hpp"
#include "Object/IObject.hpp"

class IRayObj {
    public:
        virtual ~IRayObj() = default;
        virtual void draw(IObject &obj) = 0;

    protected:
    private:
};

#endif /* !IRAYOBJ_HPP_ */
