#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Engine/RenderWindow.h"
#include "Engine/Collider.h"
#include "Engine/Physic.h"
#include "Engine/Input.h"

#include "Game/Ball.h"

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
SDL_Texture *ballTexture = window.loadTexture("assets/images/ball.png");
SDL_Texture *playerRedTexture = window.loadTexture("assets/images/player_red.png");
SDL_Texture *playerBlueTexture = window.loadTexture("assets/images/player_blue.png");

SDL_Event event;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
float deltaTime = 0;

TTF_Font *font32 = TTF_OpenFont("assets/fonts/AlienAbduction.ttf", 32);

Physic *physic;
Input *input;

void update(float deltaTime)
{
    for (GameObject *gameObject : GameObject::gameObjects)
    {
        gameObject->update(deltaTime);
    }
}

void render()
{
    window.clear();

    for (GameObject *gameObject : GameObject::gameObjects)
    {
        window.render(gameObject);
    }

    window.display();
}

void initGame()
{
    new GameObject(Vector2(0, 0), bgTexture);
    new Ball(Vector2(0, 0), ballTexture);
    new Player(Vector2(-150, 0), playerRedTexture, Player::RED_TEAM);
    new Player(Vector2(150, 0), playerBlueTexture, Player::BLUE_TEAM);

    // new Player(Vector2(-300, 0), playerRedTexture, Player::RED_TEAM);
    // new Player(Vector2(150, 100), playerBlueTexture, Player::BLUE_TEAM);
    // new Player(Vector2(150, -100), playerBlueTexture, Player::BLUE_TEAM);
    // new Player(Vector2(300, 0), playerBlueTexture, Player::BLUE_TEAM);
    physic = new Physic();
}

void loop()
{
    int quit = 0;

    while (!quit)
    {

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
                break;
            }
        }

        lastTick = currentTick;
        currentTick = SDL_GetPerformanceCounter();
        deltaTime = (currentTick - lastTick) / (float)SDL_GetPerformanceFrequency();

        input->update();
        physic->update();
        update(deltaTime);
        render();
    }
}

int main(int argc, char *argv[])
{
    initGame();
    loop();
    window.cleanUp();
    SDL_Quit();

    return EXIT_SUCCESS;
}