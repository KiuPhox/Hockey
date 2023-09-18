#pragma once

#include <SDL2/SDL_image.h>

#include "Component.h"

class Sprite : public Component
{
public:
    SDL_Rect rect;
    SDL_Texture *texture;
    Sprite(GameObject *obj, SDL_Texture *texture);
};