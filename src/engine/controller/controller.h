#pragma once

// #include "snake.h"
#include "inputEvent.h"

class Controller
{
public:
    // void HandleInput(bool &running, Snake &snake) const;
    Controller(){};
    ~Controller(){};
    InputEvent pollEvent();

private:
    // void ChangeDirection(Snake &snake, Snake::Direction input,
    //                      Snake::Direction opposite) const;
};
