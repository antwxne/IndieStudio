/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneRobin
*/

#ifndef SCENEROBIN_HPP_
#define SCENEROBIN_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

class SceneRobin : public AScene {
    public:
        SceneRobin();
        ~SceneRobin();

        int run(Raylib &lib) override;
        void InitAssets() final {};
    protected:
    private:
};

#endif /* !SCENEROBIN_HPP_ */
