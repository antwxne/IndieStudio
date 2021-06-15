/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <string>

#include "Object/Collisionable/Destructible/Movable/Tank.hpp"

#ifndef INDIESTUDIO_PLAYER_HPP
#define INDIESTUDIO_PLAYER_HPP

/**
 * @class Player
 *
 * @brief contains info about the player
 */
class Player {
public:
    /**
     * @brief constructor of class player
     * @param tank  reference to a tank
     */
    Player(Tank &tank);
    /**
     * @brief destructor
     */
    ~Player() = default;
    /**
     * @return player's name
     */
    const std::string &getName() const;
    /**
     * @brief set a new name to the player
     * @param name new name
     */
    void setName(const std::string &name);
    /**
     *
     * @return player's score
     */
    std::size_t getScore() const;
    /**
     * @brief set the player's score
     * @param score new score
     */
    void setScore(std::size_t score);
    /**
     * @brief increase player's score
     * @param inc number to add to current score
     */
    void increaseScore(std::size_t inc);

private:
    /**
     * @var player's name
     */
    std::string _name;
    /**
     * @var player's score
     */
    std::size_t _score;
    /**
     * @var reference to a tank
     */
    Tank &_tank;
    //vector carrés rouge Clément
};

#endif //INDIESTUDIO_PLAYER_HPP
