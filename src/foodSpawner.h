#pragma once
#include "SDL.h"
#include <vector>
#include <random>

struct Food
{
    enum Types
    {
        Normal = 1,
        Enhanced = 2
    };
    Types type = Types::Normal;
    SDL_Point position;
    bool isEaten{false};
};

class FoodSpawner
{
public:
    FoodSpawner(std::size_t grid_width, std::size_t grid_height);
    Food SpawnFood(std::vector<SDL_Point> &noPlace);

private:
    const double ENHANCED_PROBABILITY = 0.3;
    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
};
