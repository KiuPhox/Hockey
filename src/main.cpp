#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "RenderWindow.h"

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
    if (!(TTF_Init()))
        std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    return true;
}

bool SDLinit = init();

RenderWindow window("Tiny Football", 800, 496);

SDL_Texture *bgTexture = window.loadTexture("assets/images/bg.png");

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

SDL_Event event;

TTF_Font *font32 = TTF_OpenFont("assets/fonts/AlienAbduction.ttf", 32);

void update()
{
    lastTick = currentTick;
    currentTick = SDL_GetPerformanceCounter();
    deltaTime = (double)((currentTick - lastTick) * 1000 / (double)SDL_GetPerformanceFrequency());
}

void render()
{
    window.clear();

    window.render(0, 0, bgTexture);

    window.display();
}

int main(int argc, char *argv[])
{

    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                break;
            }
        }

        update();
        render();
    }

    window.cleanUp();
    SDL_Quit();

    return EXIT_SUCCESS;
}