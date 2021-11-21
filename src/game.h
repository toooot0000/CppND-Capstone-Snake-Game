#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "foodSpawner.h"
#include "timer.h"

class Game
{
public:
    Game(std::size_t grid_width, std::size_t grid_height);
    void Run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration);
    int GetScore() const;
    int GetSize() const;

private:
    Snake snake;
    SDL_Point food;

    FoodSpawner foodSpawner;
    const unsigned int FOOD_LIMIT{3};
    Timer foodTimer{3};
    std::vector<Food> foodList;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};

    void PlaceFood();
    void UpdateFood();
    void Update();
};

#endif