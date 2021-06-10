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

#include "Keys.hpp"
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
private:
protected:
    void triggerInputFuncs(Raylib &lib);
    std::vector<std::unique_ptr<IObject>> _objects;
    std::unordered_map<int,std::function<void()>> _keys = {
        {NULL_KEY, [](){}},
        {ENTER, [](){}},
        {SPACE, [](){}},
        {ESCAPE, [](){}},
        {TAB, [](){}},
        {UP, [](){}},
        {DOWN, [](){}},
        {RIGHT, [](){}},
        {LEFT, [](){}},
        {A, [](){}},
        {B, [](){}},
        {C, [](){}},
        {D, [](){}},
        {E, [](){}},
        {E, [](){}},
        {F, [](){}},
        {G, [](){}},
        {H, [](){}},
        {I, [](){}},
        {J, [](){}},
        {K, [](){}},
        {L, [](){}},
        {M, [](){}},
        {N, [](){}},
        {O, [](){}},
        {P, [](){}},
        {Q, [](){}},
        {R, [](){}},
        {S, [](){}},
        {T, [](){}},
        {U, [](){}},
        {V, [](){}},
        {W, [](){}},
        {X, [](){}},
        {Y, [](){}},
        {Z, [](){}},
    };
};
