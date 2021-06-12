/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayMusic
*/

#include "RayMusic.hpp"

RayMusic::RayMusic(std::string filepath, bool loop) : _music(LoadMusicStream(filepath.c_str()))
{
    _music.looping = loop;
}

RayMusic::~RayMusic()
{
}

void RayMusic::StartMusic()
{
    PlayMusicStream(_music);
}

void RayMusic::UpdateMusic()
{
    UpdateMusicStream(_music);
}

void RayMusic::StopMusic()
{
    StopMusicStream(_music);
}

void RayMusic::SetVolume(float &volume)
{
    SetMusicVolume(_music, volume);
}