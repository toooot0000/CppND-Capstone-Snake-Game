#pragma once

#include "keymap.h"
#include <SDL_keyboard.h>

enum InputType
{
    Keydown,
    Quit
};

class InputEvent
{
private:
    SDL_Keycode key;
    InputType type = InputType::Keydown;

public:
    InputEvent() = default;
    ~InputEvent() = default;

    InputEvent(SDL_Keycode key, InputType type) : key(key), type(type) {}

    InputEvent(InputType type) : key(SDLK_ESCAPE), type(type) {}

    InputEvent(const InputEvent &other) = delete;

    InputEvent(InputEvent &&other) = default;

    InputEvent &operator=(const InputEvent &other) = delete;

    InputEvent &operator=(InputEvent &&other)
    {
        key = other.key;
        type = other.type;
        return *this;
    }
};