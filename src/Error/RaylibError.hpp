/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** RaylibError
*/

#ifndef RAYLIBERROR_HPP_
#define RAYLIBERROR_HPP_

#include "Error.hpp"

class RaylibError : public Error {
    public:
        RaylibError(const std::string &desc) noexcept;
        ~RaylibError() = default;

    protected:
    private:
};

#endif /* !RAYLIBERROR_HPP_ */
