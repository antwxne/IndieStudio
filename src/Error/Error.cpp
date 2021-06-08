/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &desc) noexcept : _desc("Error: " + desc)
{
}

const char *Error::what() const noexcept
{
    return _desc.c_str();
}