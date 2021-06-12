/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneMaxime
*/

#ifndef SCENEMAXIME_HPP_
#define SCENEMAXIME_HPP_

#include "AScene.hpp"

class SceneMaxime : public AScene {
    public:
        SceneMaxime();
        ~SceneMaxime();

        int run(Raylib &lib) final;
        void InitAssets() final;

    protected:
    private:
        static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
        static const std::vector<std::string> _assetsPath;
};

#endif /* !SCENEMAXIME_HPP_ */
