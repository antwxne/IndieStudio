/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <utility>
#include <string>

class Core {
    public:
    enum Scenes {
        QUIT = -1,
        MENU
    };
        Core(int screenWidth = 1920, int screenHeight = 1080, std::string const &title = "default", std::size_t const fps = 60);
        ~Core();

        void start();

    protected:
    private:
        int _screenWidth;
        int _screenHeight;
        std::string _title;
        std::size_t _fps;
};

#endif /* !CORE_HPP_ */
