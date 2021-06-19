/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <vector>

#include "Object/AObject.hpp"
#include "Object/Collisionable/Destructible/Movable/Cannon.hpp"
#include <chrono>

#ifndef INDIESTUDIO_PARTICLES_HPP
#define INDIESTUDIO_PARTICLES_HPP

/**
 * @class Particles
 *
 * @brief Class to manage particles
 */
class Particles: public AObject {
public:
    /**
     * @struct particle
     *
     * @brief infos needed to draw a particle
     * @var a acceleration of the particle (x, y, z)
     * @var v velocity of the particle (x, y, z)
     * @var position position (x, y, z)
     * @var color color of the particle (r, g, b, a)
     * @var size float radius of sphere
     * @var scale scaling of the particle
     */
    struct particule {
        coords a;
        coords v;
        coords position;
        RGB color;
        float radius;
        float scale;
    };
public:
    /**
     * @brief Constructor
     * @param pos position for place the particles
     * @param size size of one particle
     * @param maxSize maximum size of one particle
     * @param scale scaling
     * @param colors colors of particles
     * @param nParticles number of particles
     */
    Particles(const coords &pos, const std::pair<float, int> &size, float maxSize, float scale, const std::pair<RGB, RGB> &colors, std::size_t nParticles, const coords &accelleration, const float maxTime);
    /**
     * @brief default destructor for particles
     */
    ~Particles() = default;
    /**
     * @brief update all the particles in the class
     *
     * @param objPos object position to reset particle to it
     */
    bool update() noexcept;
    /**
     * @brief get all the particles from the object
     * @return vector with infos to display each particle
     */
    const std::vector<particule> &getParticles() const noexcept;
    /**
     * @brief change the color of all the particles
     * @param new color
     */
    void changeColor(const RGB &color) noexcept;
    /**
     * @brief Set the Acceleration object
     *
     * @param acceleration
     */
    void setAcceleration(const coords &acceleration);
private:
    /**
     * @var vector de particle
     * @brief store all particles infos
     */
    std::vector<particule> _particles;
    /**
     * @var float
     * @brief maximum size of particles
     */
    float _maxSize;
    /**
     * @var coord reference
     * @brief reference to object position
     */
    const coords &_objPos;
    /**
     * @brief acceleration base
     */
    coords _acceleration;
    float _sizeParticle;
    float _maxTime;
    std::chrono::_V2::system_clock::time_point _stop;
    std::chrono::_V2::system_clock::time_point _start;
    std::chrono::_V2::high_resolution_clock _time;
    std::chrono::_V2::high_resolution_clock::time_point _updateTime;
};

#endif //INDIESTUDIO_PARTICLES_HPP
