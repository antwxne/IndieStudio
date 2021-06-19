/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_

#include "AScene.hpp"
#include "Map.hpp"
#include "FrameUI.hpp"
#include "ScenePause.hpp"
#include "Object/Collisionable/Destructible/Movable/TankAi.hpp"
#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

/**
 * @brief game scene
 * @class SceneGame
 * 
 */
class SceneGame : public AScene {
    public:
        using tanksCoords = std::vector<std::pair<float, float>>;

        /**
         * @brief Construct a new Scene Game object
         * 
         * @param settings 
         */
        SceneGame(Setting &settings);
        /**
         * @brief Destroy the Scene Game object
         * 
         */
        ~SceneGame();
        /**
         * @brief 
         * 
         * @param lib 
         * @return Scenes 
         */
        Scenes run(Raylib &lib) final;
    protected:
        /**
         * @brief init all tanks
         * 
         * @param coords 
         */
        void initTanks(const tanksCoords &coords);
        /**
         * @brief init tank ui
         * 
         * @param tankCounter 
         * @param tank 
         * @param settings 
         */
        void initTankUi(int tankCounter, std::shared_ptr<Tank> tank, PlayerSettings &settings);
        /**
         * @brief init colors
         * 
         */
        void initColors();
        /**
         * @brief init Map
         * 
         * @param tanksCoords 
         */
        void initMap(const tanksCoords &tanksCoords);
        /**
         * @brief manage display of player's life
         * 
         * @param name 
         * @param life 
         */
        void manageHeart(const std::string &name, const int life);
        /**
         * @brief save
         * 
         */
        void saveAll() noexcept;
        /**
         * @brief update objects once per frame
         * 
         * @param lib 
         */
        void updateObjects(Raylib &lib) noexcept;
        /**
         * @brief Create a Rect object
         * 
         */
        void createRect() noexcept;
        /**
         * @brief init save
         * 
         */
        void initSaveTanks();
        /**
         * @brief apply bonuses on players
         * 
         */
        void applyBonuses(std::shared_ptr<Tank> tank) noexcept;
        /**
         * @brief player position
         * 
         */
        static const std::vector<std::pair<float, float>> _playerPos;
        /**
         * @brief score position
         * 
         */
        static const std::vector<std::pair<float, float>> _scorePos;
        /**
         * @brief player's life position in ui
         * 
         */
        static const std::vector<std::pair<float, float>> _uiLifePosPlayer;
        /**
         * @brief map to display
         * 
         */
        std::unique_ptr<Map> _map;
        /**
         * @brief check for pause menu
         * 
         */
        bool _isPaused;
        bool _endGame;
        /**
         * @brief pause scene for pause menu
         * 
         */
        pause::ScenePause _scenePause;


    /**
     * @brief default position for no tanks
     * 
     */
    const tanksCoords _zeroTankPos = {};
    /**
     * @brief default position for 1 tank
     * 
     */
    const tanksCoords _oneTankPos = {
        {std::make_pair(-8.0f, -5.0f)}
    };
    /**
     * @brief default position for 2 tanks
     * 
     */
    const tanksCoords _twoTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(8.0f, -5.0f)}
    };
    /**
     * @brief default position for 3 tanks
     * 
     */
    const tanksCoords _threeTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(8.0f, -5.0f)}, {std::make_pair(-8.0f, 5.0f)}
    };
    /**
     * @brief default position for 4 tanks
     * 
     */
    const tanksCoords _fourTanksPos = {
        {std::make_pair(-8.0f, -5.0f)}, {std::make_pair(8.0f, -5.0f)}, {std::make_pair(-8.0f, 5.0f)}, {std::make_pair(8.0f, 5.0f)}
    };
    /**
     * @brief player position with n player
     * 
     */
    const std::array<tanksCoords, 5> _tanksPosNbPlayers = {
        _zeroTankPos,
        _oneTankPos,
        _twoTanksPos,
        _threeTanksPos,
        _fourTanksPos
    };
};

#endif /* !SCENEGAME_HPP_ */
