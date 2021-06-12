/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RaySound
*/

#include "RaySound.hpp"

RaySound::RaySound(std::string filename) : _sound(LoadSound(filename.c_str()))
{
}

RaySound::~RaySound()
{
}

void RaySound::Play()
{
    PlaySoundMulti(_sound);
}
