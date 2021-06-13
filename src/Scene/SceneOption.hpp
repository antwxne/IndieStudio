/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneOption
*/

#ifndef SCENEOPTION_HPP_
#define SCENEOPTION_HPP_

#include "Raylib.hpp"
#include "AScene.hpp"

class SceneOption : public AScene
{
    public:
        SceneOption(std::shared_ptr<Setting> settings);
        ~SceneOption();
        void initAssets() final;
        Scenes run(Raylib &lib, Scenes const &prevScene) final;

    protected:
    private:
};

#endif /* !SCENEOPTION_HPP_ */
