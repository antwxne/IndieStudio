/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <vector>

#include "Object/AObject.hpp"

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
     * @var size pair of int for size of the particle
     * @var scale scaling of the particle
     */
    struct particle {
        coords a;
        coords v;
        coords position;
        RGB color;
        std::pair<int, int> size;
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
    Particles(const coords &pos, const std::pair<int, int> &size, const std::pair<int, int> &maxSize, float scale, const std::pair<RGB, RGB> &colors, std::size_t nParticles);
    /**
     * @brief default destructor for particles
     */
    ~Particles() = default;
    /**
     * @brief update all the particles in the class
     *
     * @param objPos object position to reset particle to it
     */
    void update(const coords &objPos) noexcept;
    /**
     * @brief get all the particles from the object
     * @return vector with infos to display each particle
     */
    const std::vector<particle> &getParticles() const noexcept;
    /**
     * @brief change the color of all the particles
     * @param new color
     */
    void changeColor(const RGB &color) noexcept;
private:
    /**
     * @var vector de particle
     * @brief store all particles infos
     */
    std::vector<particle> _particles;
    /**
     * @var pair of int
     * @brief maximum size of particles
     */
    std::pair<int, int> _maxSize;
    /**
     * @var coord reference
     * @brief reference to object position
     */
    const coords &_objPos;
};

#endif //INDIESTUDIO_PARTICLES_HPP
