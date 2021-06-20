/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Indie
*/

#include "Raylib/Raylib.hpp"
#include "Core.hpp"
#include "Error/Error.hpp"

int main()
{
    try {
        core::Core core;
        core.start();
    } catch (const Error &error) {
        std::cerr << error.what() << ", " << error.where() << std::endl;
    } catch (const std::runtime_error &error) {
        std::cout << "runtime_error : " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "exception : " << error.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error catch." << std::endl;
        return 84;
    }
    return (0);
}
