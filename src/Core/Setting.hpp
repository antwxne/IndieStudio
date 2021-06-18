/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <string>
#include <array>
#include <cstddef>
#include "Raylib.hpp"

enum playerType {
    IA,
    PLAYER,
    NONE
};

struct PlayerSettings {
    PlayerSettings() : type(IA), name("BOT" + std::to_string(std::rand() % 10)) {}
    playerType type;
    std::string name;
    bool isWin;
};

// to-do: tableau associatif inputs --> char pour pouvoir les custom depuis les settings

/**
 * @struct setting
 * @brief store game settings
 */
struct Setting {
    using inputsPlayer = std::array<Raylib::Inputs, 7>;
    using tanksCoords = std::vector<std::pair<float, float>>;

    Setting(int widthScreen = 1920, int heightScreen = 1080, const std::size_t &fps = 60, float musicVol = 1.0f, float soundVol = 1.0f);
    Setting(const Setting &settings);

    std::vector<PlayerSettings> _playersSettings;
    inputsPlayer _keysPlayerOne;
    inputsPlayer _keysPlayerTwo;
    std::array<inputsPlayer, 2> _keysPlayers;
    float _musicVol;
    float _soundVol;
    int _widthScreen;
    int _heightScreen;
    int _fps;

    tanksCoords _zeroTankPos = {};
    tanksCoords _oneTankPos = {
        {std::make_pair(-8.0f, -5.0f)}
    };
    tanksCoords _twoTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(-8.0f, -5.0f)}
    };
    tanksCoords _threeTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(-8.0f, -5.0f)}
    };
    tanksCoords _fourTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(-8.0f, -5.0f)}
    };
    static const std::array<tanksCoords, 5> _tanksPosNbPlayers;
    bool load = false;
    bool _statementLoad = false;
};

#endif /* !SETTINGS_HPP_ */
