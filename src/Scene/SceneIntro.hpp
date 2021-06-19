//
// Created by clement on 17/06/2021.
//

#pragma once
#include "AScene.hpp"

/**
 * @brief direction for tanks in intro
 * @enum Direction
 * 
 */
enum Direction {
    NEUTRAL,
    UP,
    DOWN,
};

/**
 * @brief intro of the game
 * 
 * @class SceneIntro
 * 
 */
class SceneIntro : public AScene {
public:
    /**
     * @brief Construct a new Scene Intro object
     * 
     * @param settings 
     */
    SceneIntro(Setting &settings);
    /**
     * @brief Destroy the Scene Intro object
     * 
     */
    ~SceneIntro() noexcept;
    /**
     * @brief run
     * 
     * @param lib 
     * @return Scenes 
     */
    Scenes run(Raylib &lib) final;
private:
    /**
     * @brief is enter key pressed
     * 
     */
    bool _enter;
};