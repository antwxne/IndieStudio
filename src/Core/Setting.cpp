/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Setting
*/

#include "Setting.hpp"

Setting::Setting(int widthScreen, int heightScreen, const std::size_t &fps, float musicVol, float soundVol)
    : _musicVol(musicVol), _soundVol(soundVol), _widthScreen(widthScreen), _heightScreen(heightScreen), _fps(fps)
{
}

Setting::Setting(const Setting &settings)
    : _musicVol(settings._musicVol), _soundVol(settings._soundVol), _widthScreen(settings._widthScreen), _heightScreen(settings._heightScreen), _fps(settings._fps)
{
}