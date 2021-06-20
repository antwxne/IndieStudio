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

/**
 * @brief different player's type
 * @enum playerType
 * 
 */
enum playerType {
    IA,
    PLAYER,
    NONE
};
/**
 * @brief random default name for players
 * 
 */
static const std::vector<std::string> _nameRandom {
    "Tony",
    "Joffrey",
    "Romain",
    "Remi",
    "Antoine",
    "Clement",
    "Maxime",
    "Robin",
    "Charlie"
};

/**
 * @brief store player's infos and settings
 * @struct PlayerSettings
 * 
 */
struct PlayerSettings {
    PlayerSettings() : type(IA), name(_nameRandom[std::rand() % _nameRandom.size()]), score(0), isLooser(false) {};
    PlayerSettings(int type, std::string name, int score) : type(static_cast<playerType>(type)), name(name), score(score), isLooser(false) {};
    playerType type;
    std::string name;
    int score;
    bool isLooser;
};

/**
 * @brief store info about wich bonus are selected in menu\n
 *  dépend completement des bonus choisis\n
 *  a voir selon les combinaisons si le jeu les supporte\n
 *  il faut que toutes les combinaisons soient viables --> peut etre que trois au final?
 * @struct GameBonuses
 */
struct GameBonuses {
    GameBonuses() : SpeedUpBonus(false), LifeUpBonus(false), DamageUpBonus(false) {}
    bool SpeedUpBonus;
    bool LifeUpBonus;
    bool DamageUpBonus;
};

/**
 * @struct Setting
 * @brief store game settings
 */
struct Setting {
    using inputsPlayer = std::array<Raylib::Inputs, 7>;
    /**
     * @brief Construct a new Setting object
     * 
     * @param widthScreen 
     * @param heightScreen 
     * @param fps 
     * @param musicVol 
     * @param soundVol 
     */
    Setting(int widthScreen = 1920, int heightScreen = 1080, const std::size_t &fps = 60, float musicVol = 1.0f, float soundVol = 1.0f);
    /**
     * @brief Construct a new Setting object
     * 
     * @param settings 
     */
    Setting(const Setting &settings);
    /**
     * @brief bonuses selected
     * 
     */
    GameBonuses bonuses;
    /**
     * @brief all the players settings
     * 
     */
    std::vector<PlayerSettings> _playersSettings;
    /**
     * @brief key binding for player 1
     * 
     */
    inputsPlayer _keysPlayerOne;
    /**
     * @brief key binding for player 2
     * 
     */
    inputsPlayer _keysPlayerTwo;
    /**
     * @brief key binding for player 3
     * 
     */
    inputsPlayer _keysPlayerThree;
    /**
     * @brief store all keybings
     * 
     */
    std::array<inputsPlayer, 3> _keysPlayers;
    /**
     * @brief music volume
     * 
     */
    float _musicVol;
    /**
     * @brief sounds volume
     * 
     */
    float _soundVol;
    /**
     * @brief width screen
     * 
     */
    int _widthScreen;
    /**
     * @brief height screen
     * 
     */
    int _heightScreen;
    /**
     * @brief number of FPS
     * 
     */
    int _fps;
    /**
     * @brief loaded?
     * 
     */
    bool load = false;
    /**
     * @brief statement load?
     * 
     */
    bool _statementLoad = false;
};

#endif /* !SETTINGS_HPP_ */
