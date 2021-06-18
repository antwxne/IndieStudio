/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Raylib/Raylib.hpp"

static const std::string _menuMusic = "asset/music/menu_music.mp3";

static const std::string _gameMusic = "asset/music/game_music.mp3";

static const std::string _winMusic = "asset/music/win_music.mp3";

static const std::string _mouseClick = "asset/sound_effects/click.wav";

static const std::string _mouseOver = "asset/sound_effects/over.wav";

enum Scenes {
    QUIT = -1,
    MENU,
    NEW_GAME,
    GAME,
    LOAD,
    OPTION,
    SAVE,
    INTRODUCTION,
    SPLASHSCREEN
};

class IScene {
    public:
        virtual ~IScene() {};
        virtual Scenes run(Raylib &lib) = 0;
};

#endif /* !ISCENE_HPP_ */