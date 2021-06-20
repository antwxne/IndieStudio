/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** RaylibError
*/

#ifndef RAYLIBERROR_HPP_
#define RAYLIBERROR_HPP_

#include "Error.hpp"
/**
 * @brief Raylib exception class
 * @class RaylibError
 * 
 */
class RaylibError : public Error {
    public:
        /**
         * @brief Construct a new Raylib Error object
         * 
         * @param desc 
         */
        RaylibError(const std::string &desc) noexcept;
        /**
         * @brief Destroy the Raylib Error object
         * 
         */
        ~RaylibError() = default;
};

#endif /* !RAYLIBERROR_HPP_ */
