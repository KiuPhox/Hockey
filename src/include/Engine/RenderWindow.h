#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Engine/GameObject.h"
#include "Engine/Sprite.h"
#include "Engine/Text.h"

class RenderWindow
{
public:
    RenderWindow(const char *title, int w, int h);
    SDL_Texture *loadTexture(const char *filePath);
    void cleanUp();
    void clear();
    void render(GameObject *gameObject);
    void render(Sprite *sprite);
    void render(Text *text);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};