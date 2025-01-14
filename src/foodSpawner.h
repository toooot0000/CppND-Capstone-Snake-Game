#pragma once
#include "SDL.h"
#include <vector>
#include <random>

struct Food
{
    enum Types
    {
        Normal = 1,
        Enhanced = 2,
        Super = 4
    };

    Food(){};
    Food(const Food &other);
    Food(Food &&other);

    Food &operator=(const Food &other);
    Food &operator=(Food &&other);

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
    const double SUPER_PROBABILITY = 0.1;
    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
};
