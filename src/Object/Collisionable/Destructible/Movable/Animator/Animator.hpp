/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Animator
*/

#ifndef ANIMATOR_HPP_
#define ANIMATOR_HPP_

#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"
/**
 * @brief Class for animated Objects
 * @class Animator
 * 
 */
class Animator : public MovableObject
{
    public:
        /**
         * @brief Construct a new Animator object
         * 
         * @param pos 
         * @param size 
         * @param path 
         * @param animePath 
         */
        Animator(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path, const std::string &animePath);
        /**
         * @brief Construct a new Animator object
         * 
         * @param ToCopy 
         */
        Animator(Animator &ToCopy);
        /**
         * @brief Destroy the Animator object
         * 
         */
        ~Animator();
        /**
         * @brief 
         * 
         * @param up 
         */
        void addFrameCount(const int up) noexcept;
        /**
         * @brief Get the Frame Actual object
         * 
         * @return int 
         */
        int getFrameActual() noexcept;
        /**
         * @brief Set the Frame Count object
         * 
         * @param frame 
         */
        void setFrameCount(const int frame) noexcept;
        /**
         * @brief Get the Anim Path object
         * 
         * @return std::string 
         */
        std::string getAnimPath() const noexcept;

        void setAnimPath(const std::string &animPath) noexcept;

    private:
        /**
         * @brief n frames
         * 
         */
        int _frameCount;
        /**
         * @brief path to animated object
         * 
         */
        std::string _animePath;
};

#endif /* !ANIMATOR_HPP_ */
