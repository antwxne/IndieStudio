/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Raylib
*/

#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

#ifndef RAYLIBENCAPSULATION_HPP_
#define RAYLIBENCAPSULATION_HPP_

#include <string>
#include <utility>
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include "raylib.h"

#include "Object/IObject.hpp"
#include "Object/UiObject/UiGame/BorderPlayer.hpp"
#include "Object/Collisionable/Destructible/Movable/Animator/Animator.hpp"
#include "Object/AObject.hpp"
#include "Object/Collisionable/CollisionableObject.hpp"


/**
 * @brief Raylib encapsulation
 * @class Raylib
 * 
 */
class Raylib
{
public:
    using uAObject = std::shared_ptr<AObject>;
    using vectorObject = std::vector<uAObject>;
    /**
     * @brief all raylib that we handle
     * @enum Inputs
     * 
     */
    enum Inputs {
        NULL_KEY,
        ENTER,
        SPACE,
        ESCAPE,
        TAB,
        UP,
        DOWN,
        RIGHT,
        LEFT,
        A, Z, E, R, T, Y, U, O, I, P, Q, S, D, F, G, H, J, K, L, M, W, X, C, V, B, N,
        PRESSED,
        RELEASED
    };

    // std::pair<GamepadButton, Inputs> _gamepadToInput {
    // };
    /**
     * @brief Construct a new Raylib object
     * 
     */
    Raylib();
    /**
     * @brief Destroy the Raylib object
     * 
     */
    ~Raylib();
    /**
     * @brief Create a Window object
     * 
     * @param screenWidth 
     * @param screenHeight 
     * @param title 
     * @param Fps 
     */
    void createWindow(int &screenWidth, int &screenHeight, std::string const &title, std::size_t const &Fps) noexcept;
    /**
     * @brief game loop
     * 
     * @return true 
     * @return false 
     */
    bool gameLoop() const noexcept;
    /**
     * @brief print all objects
     * 
     * @param objects 
     */
    void printObjects(vectorObject &objects) noexcept;
    // all print funcs under will be private (ex: type Vector3 only defined in raylib.h)
    /**
     * @brief print FPS
     * 
     * @param pos 
     */
    void printFps(std::pair<int, int> const &pos) const noexcept;
    /**
     * @brief draw a model
     * 
     * @param modelPath 
     * @param texturePath 
     * @param pos 
     * @param scale 
     * @param tint 
     * @param axis 
     * @param angle 
     */
    void drawModel(const std::string &modelPath, const std::string &texturePath, coords pos, float scale, RGB tint, coords axis, float angle);
    /**
     * @brief draw a mesh
     * 
     * @param modelPath 
     * @param texturePath 
     * @param pos 
     * @param scale 
     * @param tint 
     * @param size 
     */
    void drawMesh(const std::string &modelPath, const std::string &texturePath, coords pos, float scale, RGB tint, const std::pair<int, int> &size);
    /**
     * @brief draw a sphere
     * 
     * @param pos 
     * @param tint 
     * @param radius 
     */
    void drawSphere(const coords &pos, const RGB tint, const float radius);
    /**
     * @brief draw an animated object
     * 
     * @param modelPath 
     * @param texturePath 
     * @param animationPath 
     * @param pos 
     * @param frameCount 
     * @param scale 
     */
    void drawAnimation(const std::string &modelPath, const std::string &texturePath, const std::string &animationPath, const coords pos, int frameCount, float scale);
    /**
     * @brief draw a texture
     * 
     * @param path 
     * @param pos 
     * @param rotation 
     * @param scale 
     * @param tint 
     */
    void drawTexture(const std::string &path, Vector2 pos, float rotation, float scale, RGB tint);
    /**
     * @brief draw rectangle's outlines
     * 
     * @param posX 
     * @param posY 
     * @param width 
     * @param height 
     * @param color 
     */
    void drawRectangleLines(int const &posX, int const &posY, int const &width, int const &height, RGB color) const noexcept;
    /**
     * @brief draw a rectangle
     * 
     * @param posX 
     * @param posY 
     * @param width 
     * @param height 
     * @param color 
     */
    void drawRectangle(int const &posX, int const &posY, int const &width, int const &height, RGB color) const noexcept;
    /**
     * @brief draw text
     * 
     * @param text 
     * @param pos 
     * @param scale 
     * @param tint 
     */
    void drawText(const std::string &text, coords pos, float scale, RGB tint);

    /**
     * @brief play music
     * 
     * @param path 
     * @param volume 
     */
    void displayMusic(const std::string &path, float volume);
    /**
     * @brief play a sound
     * 
     * @param path 
     * @param volume 
     */
    void displaySound(const std::string &path, float volume);

    /**
     * @brief Set the Camera object
     * 
     * @param pos 
     * @param target 
     * @param up 
     * @param fovy 
     * @param projection 
     */
    void setCamera(Vector3 &pos, Vector3 &target, Vector3 &up, float &fovy, int &projection) noexcept;
    /**
     * @brief Get the Camera object
     * 
     * @return Camera 
     */
    Camera getCamera() const noexcept;
    /**
     * @brief check Collision with mouse
     * 
     * @param mousePos 
     * @param width 
     * @param height 
     * @param posX 
     * @param posY 
     * @return true 
     * @return false 
     */
    bool checkCollision(std::pair<float, float> mousePos, float width, float height, float posX, float posY);
    /**
     * @brief detect a controller
     * 
     * @param idx 
     * @return true 
     * @return false 
     */
    bool isControllerDetected(int const &idx) const noexcept;
    /**
     * @brief check if the controller is valid
     * 
     * @param idx 
     * @param ControllerName 
     * @return true 
     * @return false 
     */
    bool isControllerValid(int const &idx, std::string const &ControllerName) const noexcept;
    /**
     * @brief Get the Controller Name object
     * 
     * @param idx 
     * @return std::string 
     */
    std::string getControllerName(int const &idx) const noexcept;
    /**
     * @brief Get the Pressed Character object
     * 
     * @return char 
     */
    char getPressedCharacter() noexcept;
    /**
     * @brief Get the Key Pressed object
     * 
     * @return int 
     */
    int getKeyPressed() const noexcept;
    /**
     * @brief is the button pressed
     * 
     * @param button 
     * @return true 
     * @return false 
     */
    bool isKeyPressed(int &button) const noexcept;
    /**
     * @brief is the button released
     * 
     * @param button 
     * @return true 
     * @return false 
     */
    bool isKeyReleased(int &button) const noexcept;
    /**
     * @brief Get the Keys Down object
     * 
     * @return std::vector<int> 
     */
    std::vector<int> getKeysDown() noexcept;
    /**
     * @brief is mouse pressed?
     * 
     * @return true 
     * @return false 
     */
    bool isMousePressed() const noexcept;
    /**
     * @brief is mouse down?
     * 
     * @return true 
     * @return false 
     */
    bool isMouseDown() const noexcept;
    /**
     * @brief is mouse released
     * 
     * @return true 
     * @return false 
     */
    bool isMouseReleased() const noexcept;
    /**
     * @brief Get the Mouse Position object
     * 
     * @return const std::pair<float, float> 
     */
    const std::pair<float, float> getMousePosition() const noexcept;

    /**
     * @brief Get the Frame Max object
     * 
     * @param path 
     * @return int 
     */
    int getFrameMax(const std::string &path);
    /**
     * @brief Get the Delta Time object
     * 
     * @return float 
     */
    static float getDeltaTime() noexcept;
    /**
     * @brief free all resources
     * 
     */
    void freeResources();
    /**
     * @brief draw retangle lines ex
     * 
     * @param posX 
     * @param posY 
     * @param width 
     * @param height 
     * @param color 
     * @param lineThick 
     */
    void drawRectangleLinesEx(const float &posX, const float &posY, const float &width,
        const float &height, RGB color, int const &lineThick) noexcept;
    /**
     * @brief draw a border player object
     * 
     * @param borderPlayer const &
     */
    void draw(const BorderPlayer &borderPlayer);
    /**
     * @brief check if a wall is placed over another
     * 
     * @param firstItem 
     * @param firstItemSize 
     * @param scdItem 
     * @param scdItemSize 
     * @return true 
     * @return false 
     */
    static bool collabsWall(std::pair<int, int> firstItem, coords firstItemSize,std::pair<int, int> scdItem, coords scdItemSize);

private:
    /**
     * @brief Draw 3D objects
     * 
     * @param it 
     * @param objects 
     */
    void draw3DObjects(Raylib::uAObject &it, Raylib::vectorObject &objects);
    /**
     * @brief draw 2D objects
     * 
     * @param it 
     */
    void draw2DObjects(Raylib::uAObject &it);
    /**
     * @brief find collision between objects
     * 
     * @param obj 
     * @param allObjs 
     */
    void findCollision(std::shared_ptr<CollisionableObject> obj, const std::vector<std::shared_ptr<AObject>> &allObjs) noexcept;

private:
    /**
     * @brief screen size
     * 
     */
    std::pair<int, int> _screenSize;
    /**
     * @brief camera
     * 
     */
    Camera _camera;
    /**
     * @brief all models
     * @var key = name
     * @var value = model
     * 
     */
    std::unordered_map<std::string, Model> _models;
    /**
     * @brief all textures
     * @var key = name
     * @var value = texture
     * 
     */
    std::unordered_map<std::string, Texture2D> _textures;
    /**
     * @brief all animation models
     * @var key = name
     * @var value = animation model
     * 
     */
    std::unordered_map<std::string, ModelAnimation *> _animation;
    /**
     * @brief all musics
     * @var key = name
     * @var value = music
     * 
     */ 
    std::unordered_map<std::string, std::pair<Music, bool>> _music;
    /**
     * @brief all sounds
     * @var key = name
     * @var value = sound
     * 
     */
    std::unordered_map<std::string, Sound> _sound;
    /**
     * @brief input
     * 
     */
    std::vector<int> _inputSave;
    /**
     * @brief all keys
     * 
     */
    std::vector<int> _keys = {
        KEY_NULL,
        KEY_ENTER,
        KEY_SPACE,
        KEY_ESCAPE,
        KEY_TAB,
        KEY_UP,
        KEY_DOWN,
        KEY_RIGHT,
        KEY_LEFT,
        KEY_Q,
        KEY_W,
        KEY_E,
        KEY_R,
        KEY_T,
        KEY_Y,
        KEY_U,
        KEY_I,
        KEY_O,
        KEY_P,
        KEY_A,
        KEY_S,
        KEY_D,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_Z,
        KEY_X,
        KEY_C,
        KEY_V,
        KEY_B,
        KEY_N,
    };
};

#endif /* !RAYLIBENCAPSULATION_HPP_ */
