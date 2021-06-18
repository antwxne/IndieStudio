/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/Collisionable/Destructible/Movable/Cannon.hpp"
#include "Object/Collisionable/Destructible/Movable/MovableObject.hpp"
#include <utility>

#ifndef INDIESTUDIO_TANK_HPP
#define INDIESTUDIO_TANK_HPP

/**
 * @class Tank
 *
 * @brief base class for tank which is played by the player
 */
class Tank: public MovableObject {
public:

    /**
     * @brief path to texture
     * 
     */
    static const std::string bodyTexture;

    /**
     * @brief path to model
     * 
     */
    static const std::string bodyModel;



    /**
     * @brief path to texture
     * 
     */
    static const std::string darkGreen;


    /**
     * @brief path to texture
     * 
     */
    static const std::string darkRed;

    
    /**
     * @brief path to texture
     * 
     */
    static const std::string greenCamo;

    /**
     * @brief path to model
     * 
     */
    static const std::string cannonModel;

    /**
     * @brief Construct a new Tank object
     * 
     * @param pos 
     * @param size 
     * @param cannon 
     */
    Tank(const std::string &name, const coords &pos, const coords &size, const int maxBullets, const std::pair<std::string, std::string> &path, const std::pair<std::string, std::string> &cannonPath);
    /**
     * @brief Destroy the Tank object
     * 
     */
     //Tank(Tank &tank);
    ~Tank() = default;

    /**
     * @brief fire with the cannon
     * 
     */
    virtual void fire();

    /**
     * @brief overriden move to call _cannon.move
     * 
     * @param direction 
     */
    void move(const coords &direction) noexcept override;

    /**
     * @brief adds angle to current rotation of the cannon
     * 
     * @param angle 
     */
    void rotateCannon(float angle);

    /**
     * @brief calls cannon.moveBullets() to update the bullets positions
     * 
     */
    void moveBullets() noexcept;

    /**
     * @brief calls cannon.increaseDamage() to add one to _bullets.damage
     * 
     */
    void increaseDamage() noexcept;

    /**
     * @brief Get the Cannon object
     * 
     * @return Cannon const& 
     */
    const Cannon &getCannon() const noexcept;

    /**
     * @brief Get the Name object
     * 
     * @return std::string const& 
     */
    std::string const &getName() const noexcept;

    /**
     * @brief Get the Score object
     * 
     * @return std::size_t const& 
     */
    std::size_t const &getScore() const noexcept;

    /**
     * @brief Set the Score object
     * 
     * @param score 
     */
    void setScore(const std::size_t &score) noexcept;

    /**
     * @brief Get the Previous Pos object
     * 
     * @return const coords& 
     */
    const coords &getPreviousPos() const noexcept;
    std::pair<std::string, std::string> getPathTank() noexcept;
    struct tank_t {
        float x;
        float z;
        float y;
        float life;
        std::size_t score;
        char name[50];
    };

    const tank_t &getTankStructSave() noexcept;
    static void writeTankList(std::vector<Tank> _tankList) noexcept;
    static std::vector<Tank> readTank();
    /**
     * @brief Set the Pos object
     * 
     * @param pos 
     */
    void setPosition(const coords &pos) noexcept override;
protected:

    /**
     * @brief cannon of the turret with its proper data and model, inheriting from Movable
     * 
     */
    Cannon _cannon;

    /**
     * @brief name of the tank
     * 
     */
    std::string _name;

    /**
     * @brief score of the tank determined on kills
     * 
     */
    std::size_t _score;
    tank_t _save;

    /**
     * @brief previous frame tank's position
     * 
     */
    coords _previousPos;
};

#endif //INDIESTUDIO_TANK_HPP
