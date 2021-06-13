/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

struct Setting {
    Setting(float musicVol = 1.0f, float soundVol = 1.0f, int widthScreen = 1920, int heightScreen = 1080, int fps = 60) :
        _musicVol(musicVol), _soundVol(soundVol), _widthScreen(widthScreen), _heightScreen(heightScreen), _fps(fps) {}
    Setting(int widthScreen = 1920, int heightScreen = 1080, int fps = 60) :
        _musicVol(1.0f), _soundVol(1.0f), _widthScreen(widthScreen), _heightScreen(heightScreen), _fps(fps) {}
    float _musicVol;
    float _soundVol;
    int _widthScreen;
    int _heightScreen;
    int _fps;
};

#endif /* !SETTINGS_HPP_ */
