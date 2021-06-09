/*
** EPITECH PROJECT, 2021
** AScene.hpp
** File description:
** AScene.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Raylib.hpp"
#include "IObject.hpp"

class AScene {
public:
    AScene() = default;
    virtual ~AScene() = default;
    virtual int run(Raylib &lib) = 0;

    //Could prepare some funcs with all the classic raylib use?
    //  void mainSceneLoop();
    //  virtual void inLoop() = 0;
protected:
    std::vector<std::unique_ptr<IObject>> _objects;
};
