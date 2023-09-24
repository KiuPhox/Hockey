#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Component.h"

enum Align
{
    LEFT,
    CENTER,
    RIGHT
};

class Text : public Component
{
public:
    std::string text;
    SDL_Color color;
    TTF_Font *font;
    Align align;

    Text(GameObject *obj, std::string text, TTF_Font *font, SDL_Color color = {255, 255, 255, 255}, Align align = Align::LEFT);
};
