#include "sprite.h"
#include <string>
#include <memory>
#include <iostream>

// Sprite::Sprite(SDL_Renderer *renderer, std::string path)
//     : path(path), renderer(renderer)
// {
//     texture = std::make_unique<SDL_Texture>(IMG_LoadTexture(renderer, path.c_str()));
// }

// Sprite::Sprite(const Sprite &other)
//     : path(other.path), renderer(renderer)
// {
//     texture = std::make_unique<SDL_Texture>(IMG_LoadTexture(renderer, path.c_str()));
// }

// Sprite::Sprite(Sprite &&other)
//     : path(std::move(other.path)), texture(std::move(other.texture)), renderer(renderer)
// {
// }

// Sprite &Sprite::operator=(const Sprite &other)
// {
//     this->path = other.path;
//     this->renderer = other.renderer;
//     this->texture = std::make_unique<SDL_Texture>(IMG_LoadTexture(renderer, path.c_str()));
//     return *this;
// }

// Sprite &Sprite::operator=(Sprite &&other)
// {
//     this->path = std::move(other.path);
//     this->renderer = other.renderer;
//     this->texture = std::move(other.texture);
//     return *this;
// }

Sprite::Sprite(const Sprite &other)
    : path(other.path)
{
    texture = std::make_unique<SDL_Texture>(IMG_LoadTexture(Sprite::renderer, path.c_str()));
}

Sprite::Sprite(Sprite &&other)
    : path(std::move(other.path)), texture(std::move(other.texture)) {}

Sprite &Sprite::operator=(const Sprite &other)
{
    this->path = other.path;
    this->texture = std::make_unique<SDL_Texture>(IMG_LoadTexture(Sprite::renderer, path.c_str()));
    return *this;
}

Sprite &Sprite::operator=(Sprite &&other)
{
    this->path = std::move(other.path);
    this->texture = std::move(other.texture);
    return *this;
}