/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <random>
#include <algorithm>

#include "Particles.hpp"

Particles::Particles(const coords &pos, const std::pair<int, int> &size, const std::pair<int, int> &maxSize,
    float scale, const std::pair<RGB, RGB> &colors, std::size_t nParticles
) : AObject(pos, size, scale, colors),_particles(), _maxSize(maxSize), _objPos(pos)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> alpha(100, 250);
    std::uniform_real_distribution<float> acc(-0.5f, 0.5f);
    std::uniform_real_distribution<float> vel(-20, 20);
    particle tmp {.position = pos, .color = colors.first, .size = size, .scale = scale};

    _particles.reserve(nParticles);
    _typeField.isParticle = true;
    for (std::size_t i = 0; i < nParticles; ++i) {
        tmp.color.a = alpha(gen);
        tmp.a = {acc(gen), acc(gen), acc(gen)};
        tmp.v = {vel(gen), vel(gen), vel(gen)};
        _particles[i] = tmp;
    }
}
const std::vector<Particles::particle> &Particles::getParticles() const noexcept
{
    return _particles;
}
void Particles::update(const coords &objPos) noexcept
{
    std::random_device rd;
    std::mt19937 gen(rd());
    bool r;

    for (auto &i : _particles) {
        r = gen() % 10 <= 3;
        i.v += i.a;
        i.position += i.v;
        i.size.first += r;
        i.size.second += r;
        if (i.size.first <= _maxSize.first || i.size.second <= _maxSize.second) {
            i.position = objPos;
            i.size = _size;
        }
    }

}
void Particles::changeColor(const RGB &color) noexcept
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(100, 250);

    for (auto &i : _particles) {
        i.color = color;
        i.color.a = 100 + (dist(gen) % 155);
    }
}
