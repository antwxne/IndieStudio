/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** RayMusic
*/

#ifndef RAYMUSIC_HPP_
#define RAYMUSIC_HPP_

#include "Raylib/Raylib.hpp"

class RayMusic {
    public:
        RayMusic(std::string filepath, bool loop);
        ~RayMusic();
        void StartMusic();
        void StopMusic();
        void UpdateMusic();
        void SetVolume(float &volume);

    private:
        Music _music;
};

#endif /* !RAYMUSIC_HPP_ */
