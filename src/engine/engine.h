/**
 * The main game engine class. 
 */

#pragma once

#include <unordered_map>
#include "core/core.h"

class Game
{
private:
    std::unordered_map<int, GameObject> gameObjects;
    void registerGameObject(GameObject &obj);

    void mainLoop();
    void init();
    void render();

public:
    /**
     * @brief Construct a new Game object running a given game.
     * 
     * @param game 
     */
    Game(GameObject game) {}
    ~Game() {}
};