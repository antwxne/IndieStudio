/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

class Error : public std::exception {
    public:
        Error(const std::string &desc) noexcept;
        ~Error() = default;

        const char *what() const noexcept override;
    protected:
        std::string _desc;
};

#endif /* !ERROR_HPP_ */
