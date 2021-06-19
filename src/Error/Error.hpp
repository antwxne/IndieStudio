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

/**
 * @class Error
 * @brief customized exception class
 */
class Error : public std::exception {
    public:
        Error(const std::string &descn, const std::string &where = "") noexcept;
        ~Error() = default;

        const char *what() const noexcept override;
        const char *where() const noexcept;
    protected:
        std::string _desc;
        std::string _where;
};

#endif /* !ERROR_HPP_ */
