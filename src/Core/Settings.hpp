/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

struct Setting {
    Setting(float musicVol = 1.0f, float soundVol = 1.0f) : _musicVol(musicVol), _soundVol(soundVol) {}
    float _musicVol;
    float _soundVol;
};

#endif /* !SETTINGS_HPP_ */
