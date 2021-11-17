#pragma once

#include "SDL.h"
#include "core/gameObject.h"
#include <vector>

class Renderer
{
public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height);
    ~Renderer();

    void updateWindowTitle(int score, int fps);
    void render(const std::vector<GameObject> &objList);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
};
