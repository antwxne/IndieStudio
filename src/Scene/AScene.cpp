/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AScene
*/

#include "AScene.hpp"

void AScene::triggerInputFuncs(Raylib &lib)
{
    int input = NULL_KEY;
    std::unordered_map<int,std::function<void()>>::iterator itKey;

    while ((input = lib.getKeyPressed()) != NULL_KEY) {
        itKey = _keys.find(input);
        if (itKey != _keys.end())
            itKey->second();
    }
}
