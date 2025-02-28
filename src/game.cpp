#include "game.h"
#include <iostream>
#include <algorithm>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      //   engine(dev()),
      //   random_w(0, static_cast<int>(grid_width - 1)),
      //   random_h(0, static_cast<int>(grid_height - 1))
      foodSpawner(grid_width, grid_height)
{
    // PlaceFood();
    UpdateFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running)
    {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, snake);
        Update();
        // renderer.Render(snake, food);
        renderer.Render(snake, foodList);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {
            renderer.UpdateWindowTitle(score, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::UpdateFood()
{
    // remove all eaten food
    std::vector<Food> newFoodList;
    for (auto &food : foodList)
    {
        if (!food.isEaten)
        {
            newFoodList.emplace_back(food);
        }
    }
    std::swap(foodList, newFoodList);

    bool foodSignal = false;

    // spawn new food
    if (foodList.size() == 0 || (foodList.size() < FOOD_LIMIT && foodTimer.IsTimeOut()))
    {
        foodSignal = true;
        foodTimer.Restart(FOOD_SPAWN_MICROSEC);
    }

    if (foodSignal)
    {
        std::vector<SDL_Point> avoidVec(begin(snake.body), end(snake.body));
        for (const auto &food : foodList)
        {
            avoidVec.emplace_back(food.position);
        }
        foodList.emplace_back(foodSpawner.SpawnFood(avoidVec));
    }
}

void Game::Update()
{
    if (!snake.alive)
        return;

    snake.Update();

    int new_x = static_cast<int>(snake.head_x);
    int new_y = static_cast<int>(snake.head_y);

    // Check if there's food over here
    for (auto &food : foodList)
    {
        if (food.position.x == new_x && food.position.y == new_y && !food.isEaten)
        {
            score += food.type;
            snake.GrowBody(food.type);
            snake.speed += 0.02 * food.type;
            food.isEaten = true;
            break;
        }
    }
    UpdateFood();
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }