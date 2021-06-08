/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** RaylibError
*/

#include "RaylibError.hpp"

RaylibError::RaylibError(const std::string &desc) noexcept : Error("raylib: " + desc)
{
}
