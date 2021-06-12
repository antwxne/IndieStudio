/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Raylib/Raylib.hpp"

class IScene {
    public:
        virtual ~IScene() {};
        virtual void InitAssets() = 0;
        virtual int run(Raylib &lib) = 0;

    protected:
    private:
};

#endif /* !ISCENE_HPP_ */