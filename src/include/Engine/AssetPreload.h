#pragma once

#include <map>

#include <SDL2/SDL_image.h>

#include "Engine/RenderWindow.h"

enum ImageKey
{
    BACKGROUND,
    BALL,
    RED_PLAYER,
    BLUE_PLAYER,
    RED_ARROW,
    BLUE_ARROW
};

class AssetPreload
{
public:
    static void init(RenderWindow *window);
    static SDL_Texture *getTexture(ImageKey key);

private:
    static std::map<ImageKey, SDL_Texture *> textures;
};