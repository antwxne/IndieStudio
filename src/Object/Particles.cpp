/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include <random>
#include <algorithm>
#include <chrono>

#include "Particles.hpp"
#include "Raylib/Raylib.hpp"

Particles::Particles(const coords &pos, const std::pair<float, int> &size, float maxSize,
    float scale, const std::pair<RGB, RGB> &colors, std::size_t nParticles, const coords &accelleration, const float maxTime
) : AObject(pos, size, scale, colors),_particles(), _maxSize(maxSize), _objPos(pos), _acceleration(accelleration), _sizeParticle(size.first), _maxTime(maxTime)
{
    _start = _time.now();

    _typeField.isParticule = true;
    _typeField.is3D = true;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> alpha(50, 250);
    std::uniform_real_distribution<float> acc(0.0f, 0.005f);
    particule tmp {.position = pos, .color = colors.first, .radius = (static_cast<float>(size.first)), .scale = scale};
    float tmpRand;

    for (std::size_t i = 0; i < nParticles; ++i) {
        tmp.color.a = alpha(gen);
        tmp.a = accelleration;
        tmpRand = acc(gen);
        tmp.a.first += tmp.a.first > 0 ? tmpRand : -tmpRand;
        tmpRand = acc(gen);
        tmp.a.second += tmp.a.second > 0 ? tmpRand : -tmpRand;
        tmpRand = acc(gen);
        tmp.a.third += tmp.a.third > 0 ? tmpRand : -tmpRand;
        tmp.v = {0 , 0, 0};
        _particles.push_back(tmp);
    }
}
const std::vector<Particles::particule> &Particles::getParticles() const noexcept
{
    return _particles;
}
bool Particles::update() noexcept
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> acc(0.0f, 0.05f);
    bool r;
    float tmpRand;
    static auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start) >= std::chrono::milliseconds(70)) {
        start = std::chrono::high_resolution_clock::now();
        for (auto &i : _particles) {
            r = gen() % 2;
            i.v += i.a;
            i.position += i.v;
            i.radius += static_cast<float>(r) / 10;
            if (i.radius > _maxSize) {
                i.position = _objPos;
                i.radius = _sizeParticle;
                i.v = {0 , 0, 0};
                i.a = _acceleration;
                tmpRand = acc(gen);
                i.a.first += i.a.first > 0 ? tmpRand : -tmpRand;
                tmpRand = acc(gen);
                i.a.second += i.a.second > 0 ? tmpRand : -tmpRand;
                tmpRand = acc(gen);
                i.a.second += i.a.second > 0 ? tmpRand : -tmpRand;
            }
        }
    }

    _stop = _time.now();
    if (std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(_stop - _start).count() > _maxTime) {
        std::cout << "[PARTICULE] ON RM La Particule\n";
        _start = _time.now();
        return (true);
    }
    return (false);
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

void Particles::setAcceleration(const coords &acceleration)
{
    _acceleration = acceleration;
}
