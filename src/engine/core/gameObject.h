#pragma once

#include "SDL.h"
#include "controller/inputEvent.h"
#include "sprite/sprite.h"
#include <memory>

class GameObject
{
private:
    SDL_Rect rect;
    std::unique_ptr<Sprite> spr;

public:
    GameObject() = default;
    ~GameObject() = default;

    virtual void init(){};
    virtual void process(){};
    virtual void input(InputEvent &e){};

    SDL_Rect getRect() const noexcept
    {
        return rect;
    }
    inline Sprite *getSprite() const noexcept
    {
        return spr.get();
    }
};
