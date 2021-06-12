/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaySound
*/

#ifndef RAYSOUND_HPP_
#define RAYSOUND_HPP_

#include "Raylib/Raylib.hpp"

class RaySound {
    public:
        RaySound(std::string filename, float volume);
        ~RaySound();
        void Play();
        void SetVolume(float &volume);

    private:
        Sound _sound;
};

#endif /* !RAYSOUND_HPP_ */
