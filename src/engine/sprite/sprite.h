#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <memory>
#include <string>

class Sprite
{
private:
    std::unique_ptr<SDL_Texture> texture;
    std::string path;
    static SDL_Renderer *renderer;

public:
    Sprite() = default;
    ~Sprite() = default;

    // Sprite(SDL_Renderer *renderer, std::string path);

    /**
     * @brief Construct a new Sprite object from a file path
     * 
     * @param path 
     */
    Sprite(std::string path);

    /**
     * @brief Copy construct a new Sprite object
     * 
     * @param other 
     */
    Sprite(const Sprite &other);

    /**
     * @brief Move construct a new Sprite object
     * 
     * @param other 
     */
    Sprite(Sprite &&other);

    Sprite &operator=(const Sprite &other);
    Sprite &operator=(Sprite &&other);

    inline SDL_Texture *getTexture() const noexcept
    {
        return texture.get();
    }
};
