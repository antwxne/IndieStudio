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
    PlayerSettings() : type(IA), name("BOT" + std::to_string(std::rand() % 10)), score(0), isLooser(true) {}
    PlayerSettings(int type = IA, std::string name = "tkt", int score = 0) : type(static_cast<playerType>(type)), name(name), score(score), isLooser(true) {}
    playerType type;
    std::string name;
    int score;
    bool isLooser;
};


// dépend completement des bonus choisis
// a voir selon les combinaisons si le jeu les supporte
// il faut que toutes les combinaisons soient viables --> peut etre que trois au final?
struct GameBonuses {
    GameBonuses() : SpeedUpBonus(false), LifeUpBonus(false), DamageUpBonus(false) {}
    bool SpeedUpBonus;
    bool LifeUpBonus;
    bool DamageUpBonus;
};

/**
 * @struct setting
 * @brief store game settings
 */
struct Setting {
    using inputsPlayer = std::array<Raylib::Inputs, 7>;

    Setting(int widthScreen = 1920, int heightScreen = 1080, const std::size_t &fps = 60, float musicVol = 1.0f, float soundVol = 1.0f);
    Setting(const Setting &settings);

    GameBonuses bonuses;

    std::vector<PlayerSettings> _playersSettings;

    inputsPlayer _keysPlayerOne;
    inputsPlayer _keysPlayerTwo;
    inputsPlayer _keysPlayerThree;
    std::array<inputsPlayer, 3> _keysPlayers;

    float _musicVol;
    float _soundVol;
    int _widthScreen;
    int _heightScreen;
    int _fps;
    bool load = false;
    bool _statementLoad = false;
};

#endif /* !SETTINGS_HPP_ */
