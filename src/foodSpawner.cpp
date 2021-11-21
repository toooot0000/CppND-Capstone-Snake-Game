#include "foodSpawner.h"
#include <unordered_set>
#include <functional>

FoodSpawner::FoodSpawner(std::size_t grid_width, std::size_t grid_height)
    : engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
}

struct PairHash
{
    template <typename T1, typename T2>
    std::size_t operator()(std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

Food FoodSpawner::SpawnFood(std::vector<SDL_Point> &noPlace)
{
    Food ret;
    std::unordered_set<std::pair<int, int>, PairHash> avoidSet;
    for (auto cur : noPlace)
    {
        avoidSet.emplace(std::make_pair(cur.x, cur.y));
    }
    int x, y;
    while (true)
    {
        x = random_w(engine);
        y = random_h(engine);
        if (avoidSet.find(std::make_pair(x, y)) == avoidSet.end())
        {
            ret.position.x = x;
            ret.position.y = y;
            break;
        }
    }

    std::uniform_real_distribution<> foodTypeDis;
    double randNum = foodTypeDis(engine);
    if (randNum < SUPER_PROBABILITY)
    {
        ret.type = ret.Super;
    }
    else if (randNum < ENHANCED_PROBABILITY)
    {
        ret.type = ret.Enhanced;
    }

    return std::move(ret);
}
