/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#pragma once

#include <vector>

#include "AScene.hpp"
#include "ScenePause.hpp"
#include "Map/Map.hpp"
#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

/**
 * @brief Maxime's scene
 * 
 * @class SceneMaxime
 */
class SceneMaxime : public AScene {
    public:
        /**
         * @brief Construct a new Scene Maxime object
         * 
         * @param settings 
         */
        SceneMaxime(Setting &settings);
        /**
         * @brief Destroy the Scene Maxime object
         * 
         */
        ~SceneMaxime();
        /**
         * @brief run scene
         * 
         * @param lib 
         * @return Scenes 
         */
        Scenes run(Raylib &lib) final;
        /**
         * @brief manage player's heart in ui
         * 
         * @param name 
         * @param life 
         */
        void manageHeart(const std::string &name, const int life);
        /**
         * @brief check player's life
         * 
         */
        void checkHeart() noexcept;
        /**
         * @brief init all tanks
         * 
         */
        void initTanks();
    private:
        /**
         * @brief positions for hearts in ui
         * 
         */
        std::vector<int> _listPosHeart;
        /**
         * @brief menu pos
         * 
         */
        static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
        /**
         * @brief scene menu pause
         * 
         */
        pause::ScenePause _scenePause;
        /**
         * @brief tank
         * 
         */
        std::shared_ptr<Tank> _tanks;
        /**
         * @brief key pressed
         * 
         */
        bool _pressed;
        /**
         * @brief enter pressed
         * 
         */
        bool _enter;
        /**
         * @brief game in pause
         * 
         */
        bool _isPaused;
        /**
         * @brief state of scene
         * 
         */
        bool _state;
        /**
         * @brief save tanks in file
         * 
         */
        void saveTanks() noexcept;
        /**
         * @brief map
         * 
         */
        std::unique_ptr<Map> _map;
};

/**
 * @brief _position for name in ui
 * 
 */
static const std::vector<std::pair<float, float>> _namePlayerPos {
    {std::make_pair(170.0f, 1035.0f)},
    {std::make_pair(670.0f, 1035.0f)},
    {std::make_pair(1170.0f, 1035.0f)},
    {std::make_pair(1670.0f, 1035.0f)},
};

/**
 * @brief position for score in ui
 * 
 */
static const std::vector<std::pair<float, float>> _scorePos {
    {std::make_pair(280.0f, 990.0f)},
    {std::make_pair(780.0f, 990.0f)},
    {std::make_pair(1280.0f, 990.0f)},
    {std::make_pair(1780.0f, 990.0f)},
};

/**
 * @brief position for life in ui
 * 
 */
static const std::vector<std::pair<float, float>> _uiLifePosPlayer{
    std::make_pair(265, 1050),
    std::make_pair(765, 1050),
    std::make_pair(1265, 1050),
    std::make_pair(1765, 1050)
};

/**
 * @brief position for tanks
 * 
 */
static const std::vector<std::pair<float, float>> _posTank {
    std::make_pair(-8, -5),
    std::make_pair(-8, 5),
    std::make_pair(8, 5),
    std::make_pair(8,-5)
};