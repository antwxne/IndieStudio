/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** UiObject
*/

#ifndef UIOBJECT_HPP_
#define UIOBJECT_HPP_

#include "AObject.hpp"

class UiObject : public AObject
{
    public:
        UiObject(const coords &pos, const std::pair<int, int> &size, const std::string &texture, float scale, std::pair<RGB, RGB> const &color);
        UiObject(const coords &pos, const std::pair<int, int> &size, const std::string &texture, float scale);
        ~UiObject();
        void setTexture(const std::string &newTexture) noexcept;
        const std::string getTexture() const noexcept;
    private:
        std::string _texture;
};

#endif /* !UIOBJECT_HPP_ */
