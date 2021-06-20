/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** UiObject
*/

#ifndef UIOBJECT_HPP_
#define UIOBJECT_HPP_

#include "AObject.hpp"
#include <array>

/**
 * @brief UI object base class
 * @class UiObject
 * 
 */
class UiObject : public AObject
{
    public:
        /**
         * @brief Construct a new Ui Object object
         * 
         * @param pos 
         * @param size 
         * @param texture 
         * @param scale 
         * @param color 
         */
        UiObject(const coords &pos, const std::pair<int, int> &size, const std::string &texture, float scale, std::pair<RGB, RGB> const &color);
        /**
         * @brief Construct a new Ui Object object
         * 
         * @param pos 
         * @param size 
         * @param texture 
         * @param scale 
         */
        UiObject(const coords &pos, const std::pair<int, int> &size, const std::string &texture, float scale);
        /**
         * @brief Destroy the Ui Object object
         * 
         */
        ~UiObject();
        /**
         * @brief Set the Texture object
         * 
         * @param newTexture 
         */
        void setTexture(const std::string &newTexture) noexcept;
        /**
         * @brief Get the Texture object
         * 
         * @return const std::string 
         */
        const std::string getTexture() const noexcept;
    private:
        /**
         * @brief texture
         * 
         */
        std::string _texture;
};

#endif /* !UIOBJECT_HPP_ */
