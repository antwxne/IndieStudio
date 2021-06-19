/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &desc, const std::string &where) noexcept : _desc("Error: " + desc), _where("Where: " + where)
{
}

const char *Error::what() const noexcept
{
    return _desc.c_str();
}
const char *Error::where() const noexcept
{
    return _where.c_str();
}