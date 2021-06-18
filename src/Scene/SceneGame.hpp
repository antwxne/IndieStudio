/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_

#include "AScene.hpp"

class SceneGame : public AScene {
    public:
        SceneGame(Setting &settings);
        ~SceneGame();

        Scenes run(Raylib &lib) final;
    protected:
    private:
        void initTanks();
        void initTankUi(int tankCounter, std::shared_ptr<Tank> tank, PlayerSettings &settings);

    static const std::vector<std::pair<float, float>> _playerPos;
    static const std::vector<std::pair<float, float>> _scorePos;
    static const std::vector<std::pair<float, float>> _uiLifePosPlayer;
};

#endif /* !SCENEGAME_HPP_ */
