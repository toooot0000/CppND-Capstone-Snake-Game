/**
 * The main game engine class. 
 * Main duty:
 *  1. Basic game loop
 *  2. Organize game objects
 */

#pragma once

#include <unordered_map>
#include "core/core.h"

class Game
{
private:
public:
    Game() {}
    ~Game() {}
    void mainLoop();
    void init();
};